/*
                                                                   Program.No:5
                                                               PRIORITY CPU SCHEDULING
                                                               =======================      
*/
#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
  int p_id;
  int priority;
  int b_time;
  int w_time;
  int ta_time;
}p[20],temp;
void main()
{
  int i,j,n,total_wt=0,total_tat=0;
  float av_wt,av_tat;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the process id:");
    scanf("%d",&p[i].p_id);
    printf("Enter the burst time of process P[%d]:",p[i].p_id);
    scanf("%d",&p[i].b_time);
    printf("Enter the priority of process P[%d]:",p[i].p_id);
    scanf("%d",&p[i].priority);
    printf("\n");
  }
  for(i=0;i<n-1;i++)
  {
     for(j=0;j<n-i-1;j++)
     {
        if(p[j].priority<p[j+1].priority)
        {
           temp=p[j];
           p[j]=p[j+1];
           p[j+1]=temp;
        }
     }
  }
  p[0].w_time=0;
  for(i=1;i<n;i++)
  {
       p[i].w_time=0;
       for(j=0;j<i;j++)
       {
         p[i].w_time+=p[j].b_time;
       }
  }
  printf("Process\t\tPriority\tBurst Time\tWaiting Time\tTurnaround Time");
  for(i=0;i<n;i++)
  {
    p[i].ta_time=p[i].w_time+p[i].b_time;
    total_wt+=p[i].w_time;
    total_tat+=p[i].ta_time;
    printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",p[i].p_id,p[i].priority,p[i].b_time,p[i].w_time,p[i].ta_time);
  }
  av_wt=(float)total_wt/n;
  av_tat=(float)total_tat/n;
  printf("\nAverage Waiting time:%f",av_wt);
  printf("\nAverage Turnaround time:%f",av_tat);
}
/*
OUTPUT
======
Enter the number of processes:5
Enter the process id:0
Enter the burst time of process P[0]:2
Enter the priority of process P[0]:3

Enter the process id:1
Enter the burst time of process P[1]:6
Enter the priority of process P[1]:1

Enter the process id:2
Enter the burst time of process P[2]:1
Enter the priority of process P[2]:4

Enter the process id:3
Enter the burst time of process P[3]:3
Enter the priority of process P[3]:8

Enter the process id:4
Enter the burst time of process P[4]:5
Enter the priority of process P[4]:7

Process		Priority	Burst Time	Waiting Time	Turnaround Time
P[3]		8		3		0		3
P[4]		7		5		3		8
P[2]		4		1		8		9
P[0]		3		2		9		11
P[1]		1		6		11		17
Average Waiting time:6.200000
Average Turnaround time:9.600000
*/
