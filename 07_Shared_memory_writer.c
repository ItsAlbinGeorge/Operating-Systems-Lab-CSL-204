/*
                                                                   Program.No:7
                                                            IPC SHARED MEMORY (WRITER)
                                                            ==========================      
*/
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
   void *shared_memory;
   char buff[100];
   int shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
   printf("ID of Shared Memory is %d\n",shmid);
   shared_memory=shmat(shmid,NULL,0);
   printf("Process attached at %p\n",shared_memory);
   printf("Enter a string to be written to shared memory:\n");
   read(0,buff,100);
   strcpy(shared_memory,buff);
   printf("String written in memory is %s\n",(char *)shared_memory);
   return 0;
}
/*
OUTPUT
======
ID of Shared Memory is 2
Process attached at 0x7f5931556000
Enter a string to be written to shared memory:
Albin george
String written in memory is Albin george
*/
