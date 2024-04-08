/*
                                                                   Program.No:6
                                                             ROUND-ROBIN SCHEDULING
                                                             ======================      
*/
#include<stdio.h>
struct process
{
   int pid;
   int btime;
   int rtime;
};
void round_robin(struct process p[],int n,int quantum)
{
   int time=0,i,remaining_processes=n,current_time_slice=0;
   while(remaining_processes>0)
   {
      for(i=0;i<n;i++)
      {
         if(p[i].rtime==0)
             continue;
         if(p[i].rtime<=quantum)
         {
            time+=p[i].rtime;
            current_time_slice=p[i].rtime;
            p[i].rtime=0;
         }
         else
         {
            time+=quantum;
            p[i].rtime-=quantum;
            current_time_slice=quantum;
         }
         printf("Process P[%d] executed for %d time units from %d to %d\n",p[i].pid,current_time_slice,time-current_time_slice,time);
         if(p[i].rtime==0)
            remaining_processes--;
      }
   }
}
int main()
{
   int i,n,quantum;
   struct process p[10];
   printf("Enter the number of processes:");
   scanf("%d",&n);
   printf("Enter the time quantum:");
   scanf("%d",&quantum);
   for(i=0;i<n;i++)
   {
      printf("Enter the process id:");
      scanf("%d",&p[i].pid);
      printf("Enter the burst time:");
      scanf("%d",&p[i].btime);
      p[i].rtime=p[i].btime;
   }
   round_robin(p,n,quantum);
   return 0;
}
/*
OUTPUT
======
Enter the number of processes:3
Enter the time quantum:3
Enter the process id:0
Enter the burst time:5
Enter the process id:1
Enter the burst time:7
Enter the process id:2
Enter the burst time:1
Process P[0] executed for 3 time units from 0 to 3
Process P[1] executed for 3 time units from 3 to 6
Process P[2] executed for 1 time units from 6 to 7
Process P[0] executed for 2 time units from 7 to 9
Process P[1] executed for 3 time units from 9 to 12
Process P[1] executed for 1 time units from 12 to 13
*/
