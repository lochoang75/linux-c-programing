#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        usageErr("%s file_name\n", argv[0]);
        return 0;
    }

    int origin_fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (origin_fd < 0)
    {
        errExit("create fd");
    }

    int shared_fd = dup(origin_fd);
    if (shared_fd < 0)
    {
        errExit("Dup fd error");
    }

    lseek(origin_fd, 100, SEEK_SET); 
    int share_offset = lseek(shared_fd, 0, SEEK_CUR);
    printf("seek offset on share is %d\n", share_offset);
    fcntl(origin_fd, F_SETFL, O_APPEND);
    int flag =  fcntl(shared_fd, F_GETFL);
    if (flag & O_APPEND)
    {
        printf("Status flag has been changed\n");
    }
    return 0;
}