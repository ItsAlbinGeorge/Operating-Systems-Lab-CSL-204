/*
                                                                   Program.No:12
                                                                 BANKERS ALGORTHM
                                                                 ================
*/
#include<stdio.h>
int n,r,max[100][100],alloc[100][100],need[100][100],avail[100];
void input()
{
   int i,j;
   printf("Enter the number of processes:");
   scanf("%d",&n);
   printf("Enter the number of resources:");
   scanf("%d",&r);
   printf("Enter the MAX matrix:\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<r;j++)
      {
         scanf("%d",&max[i][j]);
      }
   }
   printf("Enter the ALLOCATION matrix:\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<r;j++)
      {
         scanf("%d",&alloc[i][j]);
      }
   }
   printf("Enter the available resources:");
   for(i=0;i<r;i++)
   {
      scanf("%d",&avail[i]);
   }
}
void show()
{
   int i,j;
   printf("Process\tAllocation\tMax\tAvailable\n");
   for(i=0;i<n;i++)
   {
      printf("P[%d]\t",i+1);
      for(j=0;j<r;j++)
      {
         printf("%d ",alloc[i][j]);
      }
      printf("\t");
      for(j=0;j<r;j++)
      {
         printf("%d ",max[i][j]);
      }
      printf("\t");
      if(i==0)
      {
         for(j=0;j<r;j++)
         {
            printf("%d ",avail[j]);
         }
      }
      printf("\n");
   }
}
void cal()
{
   int i,j,k,temp,flag=1,cl=0,safe[100],finish[100],need[100][100];
   for(i=0;i<n;i++)
   {
      finish[i]=0;
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<r;j++)
      {
         need[i][j]=max[i][j]-alloc[i][j];
      }
   }
   printf("\n");
   while(flag)
   {
      flag=0;
      for(i=0;i<n;i++)
      {
         int c=0;
         for(j=0;j<r;j++)
         {
            if((finish[i]==0)&&(need[i][j]<=avail[j]))
            {
               c++;
               if(c==r)
               {
                  for(k=0;k<r;k++)
                  {
                     avail[k]+=alloc[i][j];
                     finish[i]=1;
                     flag=1;
                  }
                  printf("P[%d]  ",i+1);
                  if(finish[i]==1)
                  {
                     i=n;
                  }
               }
            }
         }
      }
   }
   for(i=0;i<n;i++)
   {
      if(finish[i]==1)
      {
         cl++;
      }
      else
      {
         printf("P[%d] ",i+1);
      }
   }
   if(cl==n)
   {
      printf("\nThe system is in safe state");
   }
   else
   {
      printf("\nProcesses are in deadlock");
      printf("\nSystem is in unsafe state");
   }
}
int main()
{
   int i,j;
   printf("BANKERS ALGORITHM\n=================\n");
   input();
   show();
   printf("\nThe safe sequence is:");
   cal();
   return 0;
}
/*
OUTPUT
======
BANKERS ALGORITHM
=================
Enter the number of processes:5
Enter the number of resources:3
Enter the MAX matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter the ALLOCATION matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the available resources:3 3 2
Process	Allocation	Max	Available
P[1]	0 1 0 	7 5 3 	3 3 2 
P[2]	2 0 0 	3 2 2 	
P[3]	3 0 2 	9 0 2 	
P[4]	2 1 1 	2 2 2 	
P[5]	0 0 2 	4 3 3 	

The safe sequence is:
P[2]  P[4]  P[5]  P[3]  P[1]  
The system is in safe state
*/
