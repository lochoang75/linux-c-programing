#include <sys/stat.h>
#include <ctype.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include "get_num.h"
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        usageErr("%s filename num_bytes [x]", argv[0]);
    }

    char *file_name = argv[1];
    int num_bytes = getInt(argv[2], GN_NONNEG | GN_ANY_BASE, NULL);
    bool use_append = true;
    if (argc == 4) {
        if (strcmp(argv[3], "x") == 0) {
            use_append = false;
        }
    }
    
    int fd = 0;
    char buf = 'x';
    int write_status = 0;

    if (use_append) {
        fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT);
        if (fd < 0) {
            errExit("error open");
        }
        do {
            write_status = write(fd, &buf, sizeof(buf));
            if (write_status < 0) {
                errExit("Write error");
            }
            num_bytes--;
        } while(num_bytes > 0);
        close(fd);

    } else {
        fd = open(file_name, O_WRONLY | O_CREAT);
        if (fd < 0) {
            errExit("error open");
        }
        do {
            lseek(fd, 0, SEEK_END);
            write_status = write(fd, &buf, sizeof(buf));
            if (write_status < 0) {
                errExit("Write error");
            }
            num_bytes--;
        } while(num_bytes > 0);
        close(fd);
    }

    return 0;
}
