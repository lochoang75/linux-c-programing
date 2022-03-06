#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char * argv[]) {
    int fd = open("test.txt", O_RDONLY);
    printf("old fd is: %d\n", fd);
    int new_fd = fcntl(fd, F_DUPFD, 0);
    printf("new fd is: %d\n", new_fd);
    close(fd);
    close(new_fd);
    return 0;
}
