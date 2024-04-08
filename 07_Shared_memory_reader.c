/*
                                                                   Program.No:7
                                                           IPC SHARED MEMORY (READER)
                                                           ==========================      
*/
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
int main()
{
   void *shared_memory;
   char buff[100];
   int shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
   printf("ID of Shared Memory is %d\n",shmid);
   shared_memory=shmat(shmid,NULL,0);
   printf("Process attached at %p\n",shared_memory);
   printf("Data read from shared memory is %s",(char *)shared_memory);
   return 0;
}
/*
OUTPUT
======
ID of Shared Memory is 2
Process attached at 0x7fc713a5b000
Data read from shared memory is Albin george
*/
