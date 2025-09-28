#include <fcntl.h>    
#include <unistd.h>   
#include <stdio.h>    
#include <stdlib.h>   

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *src_file = argv[1];
    const char *dst_file = argv[2];


    int fd_src = open(src_file, O_RDONLY);
    if (fd_src == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    int fd_dst = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dst == -1) {
        perror("Error opening/creating destination file");
        close(fd_src);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(fd_src, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = write(fd_dst, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("Error writing to destination file");
            close(fd_src);
            close(fd_dst);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading source file");
    }

    close(fd_src);
    close(fd_dst);

    return 0;
}

