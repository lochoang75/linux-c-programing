#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int main (int argc, char* argv[]) {
    Boolean append_mode = FALSE;
    int fd = 0;
    if (argc < 2) {
        usageErr("%s [-a] file_name\n", argv[0]);
    }
    char buf[1024] = {'\0'};
    char opt = getopt(argc, argv, "a:");
    if (opt != -1) {
        if (opt == 'a') {
            append_mode = TRUE;
        }
    }

    if (append_mode == FALSE) {
       fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | 
                                                        S_IRGRP | S_IWGRP | 
                                                        S_IROTH | S_IWOTH);
    } else {
       fd = open(argv[2], O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR | 
                                               S_IRGRP | S_IWGRP | 
                                               S_IROTH | S_IWOTH);
    }
    if (fd == -1) {
        errExit("open");
    }
    while (fgets(buf, 1024, stdin) != NULL) {
        printf("%s\n", buf);
        if (append_mode){
            lseek(fd, 0, SEEK_END);
        }
        int numWritten = write(fd, buf, strlen(buf));
        if (numWritten == -1) {
            errExit("write");
        }
        memset(buf, '\0', strlen(buf));
    }
    close(fd);
    return 0;
}
