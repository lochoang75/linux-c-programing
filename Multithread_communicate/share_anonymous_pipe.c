#include <stdio.h>
#include <unistd.h>

int main()
{
        int status, myPipe[2];
        pipe(myPipe);  // create the pipe
        pid_t pid = fork();

        /* child process */
        if(pid == 0)
        {
                close(myPipe[0]);  // close unused read end
                write(myPipe[1], "a", 1);
                printf("Child process sent 'a'\n");
                close(myPipe[1]);
        }

        /* parent process */
        else
        {
                char buffer[21];
                close(myPipe[1]);  // close unused write end
                int pid_child = wait(&status);
                int length = read(myPipe[0], buffer, 20);
                buffer[length] = '\0';
                printf("Parent process received '%s'\n", buffer);
                close(myPipe[0]);
        }

        return 0;
}