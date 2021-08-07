#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
        int status;
        mknod("/tmp/pipefile", S_IFIFO | S_IRUSR | S_IWUSR, 0);
        pid_t pid = fork();

        /* child process */
        if(pid == 0)
        {
                int myPipe = open("/tmp/pipefile", O_WRONLY);
                write(myPipe, "a", 1);
                printf("Child process sent 'a'\n");
                close(myPipe);
        }

        /* parent process */
        else
        {
                int myPipe = open("/tmp/pipefile", O_RDONLY);
                char buffer[21];
                int pid_child = wait(&status);
                int length = read(myPipe, buffer, 20);
                buffer[length] = '\0';
                printf("Parent process received '%s'\n", buffer);
                close(myPipe);
        }
        unlink("/tmp/pipefile");

        return 0;
}