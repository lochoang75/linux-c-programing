#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

#ifndef BUFF_SIZE
#define BUFF_SIZE 500
#endif

int cp(char *source_file, char *dest_file) {
    int source_fd = open(source_file, O_RDONLY, S_IRUSR | S_IWUSR |
                                    S_IRGRP | S_IWGRP |
                                    S_IROTH | S_IWOTH);

    int dest_fd = open(source_file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR |
                                    S_IRGRP | S_IWGRP |
                                    S_IROTH | S_IWOTH);
    if (source_fd == -1 || dest_fd == -1) {
        errExit("can't open file");
    }

    char buffer[BUFF_SIZE] = {0}; 
    int byte_read = 0;
    int byte_written = 0;
    while ((byte_read = read(source_fd, buffer, BUFF_SIZE)) > 0) {
        byte_written = write(dest_fd, buffer, (size_t) byte_read);
        if (byte_written == -1) {
            close(source_fd);
            close(dest_fd);
            errExit("Can't write file");
        }
        memset(buffer, 0, BUFF_SIZE);
    }

    close(source_fd);
    close(dest_fd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        usageErr("%s [source_file] [dest_file]\n", argv[0]);
    }

    int ret_code = cp (argv[1], argv[2]);
    return ret_code;
}
