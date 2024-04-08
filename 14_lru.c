/*
                                                                   Program.No:14
                                                               LEAST RECENTLY USED
                                                                 PAGE REPLACEMENT
                                                                ==================
*/
#include<stdio.h>
int findLRU(int time[],int n)
{
   int i,pos=0,minimum=time[0];
   for(i=0;i<n;i++)
   {
      if(time[i]<minimum)
      {
         minimum=time[i];
         pos=i;
      }
   }
   return pos;
}
void main()
{
   int i,j,k,pos,np,nf,flag1,flag2,faults=0,count=0,pages[50],frame[10],time[10];
   printf("Enter the number of pages:");
   scanf("%d",&np);
   printf("Enter the reference string:");
   for(i=0;i<np;i++)
   {
      scanf("%d",&pages[i]);
   }
   printf("Enter the number of frames:");
   scanf("%d",&nf);
   for(i=0;i<nf;i++)
   {
      frame[i]=-1;
   }
   printf("\n\tRef.String\tPage frames\n");
   for(i=0;i<np;i++)
   {
      printf("\t%d\t\t",pages[i]);
      flag1=flag2=0;
      for(j=0;j<nf;j++)
      {
         if(frame[j]==pages[i])
         {
            count++;
            time[j]=count;
            flag1=flag2=1;
            break;
         }
      }
      if(flag1==0)
      {
         for(j=0;j<nf;j++)
         {
            if(frame[j]==-1)
            {
               count++;
               faults++;
               frame[j]=pages[i];
               time[j]=count;
               flag2=1;
               break;
               for(k=0;k<nf;k++)
               {
                  printf("%d\t",frame[k]);
               }
            }
         } 
      }
      if(flag2==0)
      {
         pos=findLRU(time,nf);
         count++;
         faults++;
         frame[pos]=pages[i];
         time[pos]=count;
         for(k=0;k<nf;k++)
         {
            printf("%d\t",frame[k]);
         }
      }
      printf("\n");
   }
   printf("\nNumber of page faults:%d",faults);
}
/*
OUTPUT
======
Enter the number of pages:20
Enter the reference string:7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter the number of frames:3

	Ref.String	Page frames
	7		
	0		
	1		
	2		2	0	1	
	0		
	3		2	0	3	
	0		
	4		4	0	3	
	2		4	0	2	
	3		4	3	2	
	0		0	3	2	
	3		
	2		
	1		1	3	2	
	2		
	0		1	0	2	
	1		
	7		1	0	7	
	0		
	1		

Number of page faults:12
*/
