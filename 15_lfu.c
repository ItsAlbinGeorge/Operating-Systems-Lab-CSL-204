/*
                                                                   Program.No:15
                                                            LEAST FREQUENTLY USED PAGE
                                                              REPLACEMENT ALGORITHM
                                                            ==========================      
*/
#include<stdio.h>
void print(int frameno,int frame[])
{
    int j;
    for(j=0;j<frameno;j++)
        printf("%d\t",frame[j]);
    printf("\n");
}
void main()
{
    int i,j,k,n,page[50],frameno,frame[10],move=0,flag,count=0,count1[10]={0},repindex,leastcount;
    float rate;
    printf("Enter the number of pages:");
    scanf("%d",&n);
    printf("Enter the page reference string:");
    for(i=0;i<n;i++)
        scanf("%d",&page[i]);
    printf("Enter the number of frames:");
    scanf("%d",&frameno);
    for(i=0;i<frameno;i++)
        frame[i]=-1;
    printf("\n\n\tReference String\tPage Frames\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d\t\t",page[i]);
        flag=0;
        for(j=0;j<frameno;j++)
        {
            if(page[i]==frame[j])
            {
                flag=1;
                count1[j]++;
                printf("No replacement\n");
                break;
            }
        }
        if(flag==0&&count<frameno)
        {
            frame[move]=page[i];
            count1[move]=1;
            move=(move+1)%frameno;
            count++;
            print(frameno,frame);
        }
        else if(flag==0)
        {
            repindex=0;
            leastcount=count1[0];
            for(j=1;j<frameno;j++)
            {
                if(count1[j]<leastcount)
                {
                    repindex=j;
                    leastcount=count1[j];
                }
            }frame[repindex]=page[i];
            count1[repindex]=1;
            count++;
            print(frameno,frame);
        }
    }
    rate=(float)count/(float)n;
    printf("Number of page faults= %d\n",count);
    printf("Fault rate = %f\n",rate);
}
/*
OUTPUT
======
Enter the number of pages:20
Enter the page reference string:7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter the number of frames:3


	Reference String	Page Frames
	7		7	-1	-1	
	0		7	0	-1	
	1		7	0	1	
	2		2	0	1	
	0		No replacement
	3		3	0	1	
	0		No replacement
	4		4	0	1	
	2		2	0	1	
	3		3	0	1	
	0		No replacement
	3		No replacement
	2		3	0	2	
	1		3	0	1	
	2		3	0	2	
	0		No replacement
	1		3	0	1	
	7		3	0	7	
	0		No replacement
	1		3	0	1	
Number of page faults= 14
Fault rate = 0.700000
*/
