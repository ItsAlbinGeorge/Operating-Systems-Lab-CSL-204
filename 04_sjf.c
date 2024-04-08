/*
                                                                   Program.No:4
                                                          SHORTEST JOB FIRST CPU SCHEDULING
                                                          =================================     
*/
#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
  int p_id;
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
    printf("\n");
  }
  for(i=0;i<n-1;i++)
  {
     for(j=0;j<n-i-1;j++)
     {
        if(p[j].b_time>p[j+1].b_time)
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
  printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time");
  for(i=0;i<n;i++)
  {
    p[i].ta_time=p[i].w_time+p[i].b_time;
    total_wt+=p[i].w_time;
    total_tat+=p[i].ta_time;
    printf("\nP[%d]\t\t%d\t\t%d\t\t%d",p[i].p_id,p[i].b_time,p[i].w_time,p[i].ta_time);
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

Enter the process id:1
Enter the burst time of process P[1]:6

Enter the process id:2
Enter the burst time of process P[2]:1

Enter the process id:3
Enter the burst time of process P[3]:3

Enter the process id:4
Enter the burst time of process P[4]:5

Process		Burst Time	Waiting Time	Turnaround Time
P[2]		1		0		1
P[0]		2		1		3
P[3]		3		3		6
P[4]		5		6		11
P[1]		6		11		17
Average Waiting time:4.200000
Average Turnaround time:7.600000
*/
