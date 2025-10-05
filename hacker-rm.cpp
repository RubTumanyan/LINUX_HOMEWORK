#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>


static const size_t CHUNK = 4 * 1024 * 1024; // 4 MiB


	static ssize_t safe_write(int fd, const void* buf, size_t count) {
	const unsigned char* p = static_cast<const unsigned char*>(buf);
	size_t written = 0;
	while (written < count) {
	ssize_t r = write(fd, p + written, count - written);
	if (r < 0) {
	if (errno == EINTR) continue;
	return -1;
}
	written += static_cast<size_t>(r);
}
	return static_cast<ssize_t>(written);
}


int main(int argc, char** argv) {
	if (argc != 2) {
	std::fprintf(stderr, "Usage: %s <file-to-erase>\n", argv[0]);
	return 2;
}


const char* path = argv[1];


struct stat st;
	if (stat(path, &st) == -1) {
	std::perror("stat");
	return 3;
}


if (!S_ISREG(st.st_mode)) {
	std::fprintf(stderr, "Error: '%s' is not a regular file.\n", path);
return 4;
}


off_t filesize = st.st_size;


int fd = open(path, O_WRONLY);
if (fd == -1) {
std::perror("open");
return 5;
}


}
