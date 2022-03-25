#include<stdio.h>
#include<unistd.h>

int main() {
   int pipefds1[2];

   char writemessage[20] = "Hi";  
   char readmessage[20];
   
   
   if (pipe(pipefds1) == -1) {
      printf("Unable to create pipe 1 \n");
      return 1;
   }

   
   
   if (fork() != 0)  {
      close(pipefds1[0]); // Close the unwanted pipe1 read side
       
      printf(" Writing done to pipe 1 by %d & Message is %s\n", getpid(),writemessage);
      write(pipefds1[1],writemessage, sizeof(writemessage));
     
   } else { //child process
      close(pipefds1[1]); // Close the unwanted pipe1 write side
      read(pipefds1[0], readmessage, sizeof(readmessage));
      printf("Reading from pipe 1 by %d & Message is %s\n",getpid(), readmessage);
    
   }
   return 0;
}
