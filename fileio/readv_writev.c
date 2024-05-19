#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

static int _readv(int fd, struct iovec* iovec, size_t len);
static int _writev(int fd, struct iovec* iovec, size_t len);

int main(int argc, char* argv[])
{
    char first_line[5] = {'\0'};
    char second_line[5] = {'\0'};
    int read_fd = open("test.txt", O_RDONLY, S_IRUSR | S_IWUSR);
    if (read_fd < 0)
    {
        printf("Unable to open file to read\n");
        return -1;
    }
    struct iovec read_iov[2];
    read_iov[0].iov_base = first_line;
    read_iov[0].iov_len = 4;
    read_iov[1].iov_base = second_line;
    read_iov[1].iov_len = 4;
    printf("Read use readv\n");
    readv(read_fd, read_iov, 2);
    printf("%s\n", first_line);
    printf("%s\n", second_line);

    char third_line[5] = {'\0'};
    char fourth_line[5] = {'\0'};
    read_iov[0].iov_base = third_line;
    read_iov[1].iov_base = fourth_line;
    lseek(read_fd, 0, SEEK_SET);
    printf("Read use implement readv\n");
    _readv(read_fd, read_iov, 2);
    printf("%s\n", third_line);
    printf("%s\n", fourth_line);

    char *str0 = "hello ";
    char *str1 = "world\n";
    struct iovec write_iov[2];
    ssize_t nwritten;
    write_iov[0].iov_base = str0;
    write_iov[0].iov_len = strlen(str0);
    write_iov[1].iov_base = str1;
    write_iov[1].iov_len = strlen(str1);
    printf("Write use writev\n");
    nwritten = writev(STDOUT_FILENO, write_iov, 2);

    printf("Write use implement writev\n");
    nwritten = _writev(STDOUT_FILENO, write_iov, 2);
    return 0;
}

static int _readv(int fd, struct iovec *iov, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        int num_byte = read(fd, iov[i].iov_base, iov[i].iov_len);
        if (num_byte < 0)
        {
            printf("Read buffer error at %ld\n", i);
        }
    }
    return 0;
}

static int _writev(int fd, struct iovec *iov, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        int num_byte = write(fd, iov[i].iov_base, iov[i].iov_len);
        if (num_byte < 0)
        {
            printf("write buffer error at %ld\n", i);
        }
    }

    return 0;
}