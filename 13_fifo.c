/*
                                                                   Program.No:13
                                                                FIRST IN FIRST OUT
                                                                 PAGE REPLACEMENT
                                                                ==================
*/
#include<stdio.h>
void main()
{
   int i,j,k,np,nf,avail,count=0,pages[50],frame[10];
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
   j=0;
   printf("\n\tRef.String\tPage frames\n");
   for(i=0;i<np;i++)
   {
      printf("\t%d\t\t",pages[i]);
      avail=0;
      for(k=0;k<nf;k++)
      {
         if(frame[k]==pages[i])
         {
            avail=1;
         }
      }
      if(avail==0)
      {
         frame[j]=pages[i];
         j=(j+1)%nf;
         count++;
         for(k=0;k<nf;k++)
         {
            printf("%d\t",frame[k]);
         }
      }
      printf("\n");
   }
   printf("\nNumber of page faults:%d",count);
}
/*
OUTPUT
======
Enter the number of pages:20
Enter the reference string:7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter the number of frames:3

	Ref.String	Page frames
	7		7	-1	-1	
	0		7	0	-1	
	1		7	0	1	
	2		2	0	1	
	0		
	3		2	3	1	
	0		2	3	0	
	4		4	3	0	
	2		4	2	0	
	3		4	2	3	
	0		0	2	3	
	3		
	2		
	1		0	1	3	
	2		0	1	2	
	0		
	1		
	7		7	1	2	
	0		7	0	2	
	1		7	0	1	

Number of page faults:15
*/
