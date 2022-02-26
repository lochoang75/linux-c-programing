#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usageErr("%s file_name\n", argv[0]);
    }
    int fd = open(argv[1], O_WRONLY| O_APPEND);
    /* This seek will not take any effect due to whe open file in append mode
     * write function will call seek to the end before write */
    lseek(fd, 0, SEEK_SET);
    char buff[] = "this is a test line";
    int num_write = write(fd, buff, sizeof(buff));
    if (num_write < 0) {
        errExit("write error");
    }
    close(fd);
    return 0;
}
