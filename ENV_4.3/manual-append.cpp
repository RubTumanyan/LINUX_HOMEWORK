#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cerr << "Please provide a file path" << std::endl;
        return 1;
    }

    const char* filepath = argv[1];

    int fd1 = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd1 < 0) {
        std::cerr << "Error opening file: " << strerror(errno) << std::endl;
        return errno;
    }

    int fd2 = dup(fd1);
    if(fd2 < 0) {
        std::cerr << "Error duplicating descriptor: " << strerror(errno) << std::endl;
        close(fd1);
        return errno;
    }

    const char* line1 = "first line\n";
    const char* line2 = "second line\n";

    if(write(fd1, line1, strlen(line1)) < 0) {
        std::cerr << "Error writing first line: " << strerror(errno) << std::endl;
    }

    if(write(fd2, line2, strlen(line2)) < 0) {
        std::cerr << "Error writing second line: " << strerror(errno) << std::endl;
    }

    close(fd1);
    close(fd2);

    return 0;
}

