#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <sys/stat.h>
#include <algorithm>

#define BUFFER_SIZE 4096

int main(int argc, char** argv){
    if(argc < 3){
        std::cerr << "Usage: " << argv[0] << " source destination\n";
        return 1;
    }

    const char* source = argv[1];
    const char* dest = argv[2];

    int srcFd = open(source, O_RDONLY);
    if(srcFd < 0){
        std::cerr << "Cannot open source file: " << strerror(errno) << "\n";
        return errno;
    }

    int destFd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if(destFd < 0){
        std::cerr << "Cannot open destination file: " << strerror(errno) << "\n";
        close(srcFd);
        return errno;
    }

    char buffer[BUFFER_SIZE];
    off_t last = 0;
    off_t dataSize = 0, holeSize = 0;

    while(true){
        off_t dataPos = lseek(srcFd, last, SEEK_DATA);
        if(dataPos == -1){
            if(errno == ENXIO) break;
            std::cerr << "lseek data error: " << strerror(errno) << "\n";
            close(srcFd); close(destFd);
            return errno;
        }

        off_t holePos = lseek(srcFd, dataPos, SEEK_HOLE);
        if(holePos == -1){
            std::cerr << "lseek hole error: " << strerror(errno) << "\n";
            close(srcFd); close(destFd);
            return errno;
        }

        off_t toRead = holePos - dataPos;
        off_t copied = 0;

        while(copied < toRead){
            ssize_t n = read(srcFd, buffer, std::min((off_t)BUFFER_SIZE, toRead - copied));
            if(n <= 0){
                std::cerr << "read error\n";
                close(srcFd); close(destFd);
                return errno;
            }
            ssize_t w = write(destFd, buffer, n);
            if(w != n){
                std::cerr << "write error\n";
                close(srcFd); close(destFd);
                return errno;
            }
            copied += n;
            dataSize += n;
        }

        if(holePos > dataPos) {
            off_t holeLen = holePos - dataPos - copied;
            if(holeLen > 0){
                lseek(destFd, holeLen, SEEK_CUR);
                holeSize += holeLen;
            }
        }
        last = holePos;
    }

    close(srcFd);
    close(destFd);

    std::cout<< (dataSize + holeSize) 
              << " bytes " << dataSize << ", hole: " << holeSize << ").\n";

    return 0;
}

