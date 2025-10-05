#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <string>

void initialize(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cerr << "Error: Missing input file argument" << std::endl;
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        std::cerr << "Error opening file '" << argv[1] << "': " 
                  << strerror(errno) << std::endl;
        exit(errno);
    }

    if(dup2(fd, STDIN_FILENO) == -1)
    {
        std::cerr << "Error redirecting stdin: " << strerror(errno) << std::endl;
        close(fd);
        exit(errno);
    }

    close(fd);
}

int main(int argc, char** argv)
{
    initialize(argc, argv);

    std::string input;
    std::cin >> input;

    std::string reversed(input.rbegin(), input.rend());
    std::cout << reversed << std::endl;

    return 0;
}

