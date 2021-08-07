#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <mqueue.h>

#define PMODE 0655

int main()
{
   int status;
   struct mq_attr attr;
   attr.mq_maxmsg = 10;
   attr.mq_msgsize = 20;

   pid_t pid = fork();

   // child process - sending message
   if(pid == 0) {
      char message[20];
      strncpy(message, "Hello Parent!", 13);
      // write/create - attr needed because of O_CREAT
      mqd_t mqfd = mq_open("/test1", O_WRONLY|O_CREAT, PMODE, &attr);
      if(mqfd == -1) {
         perror("Child mq_open failure");
         exit(0);
      }
      status = mq_send(mqfd, message, strlen(message)+1, 0);
      if (status == -1) {
        perror("mq_send failure\n");
      }
      else {
        printf("Child is sending message: %s\n", message);
        printf("mq_send successful\n");
      }
      mq_close(mqfd);
      printf("Child process done\n");
   }

   // parent - receiving message
   else {
      // read only
      mqd_t mqfd = mq_open("/test1", O_RDONLY|O_CREAT, PMODE, &attr);
      if(mqfd == -1) {
         perror("Parent mq_open failure");
         exit(0);
      }

      // Parent is waiting for the child process to finish
      waitpid(pid, &status, 0);

      char buf[100];
      status = mq_receive(mqfd, buf, 100, 0);
      if (status == -1) {
        perror("mq_receive failure\n");
      }
      else {
        printf("mq_receive successful\n");
        printf("Parent received message: %s\n", buf);
      }

      mq_close(mqfd);
      mq_unlink("/test1");

      printf("Parent process done\n");
   }
   return 0;
}