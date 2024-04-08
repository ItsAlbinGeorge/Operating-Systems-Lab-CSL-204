/*
                                                                   Program.No:11
                                                          WORST FIT STORAGE ALLOCATION
                                                         ==============================
*/
#include<stdio.h>
int main()
{
  int i,j,nb,np,temp,fragments[10],b[10],p[10],top=0;
  static int block[10],process[10];
  printf("Enter the number of blocks:");
  scanf("%d",&nb);
  for(i=1;i<=nb;i++)
  {
     printf("Enter the size of block %d:",i);
     scanf("%d",&b[i]);
  }
  printf("Enter the number of processes:");
  scanf("%d",&np);
  for(j=1;j<=np;j++)
  {
     printf("Enter the size of process %d:",j);
     scanf("%d",&p[j]);
  }
  for(i=1;i<=np;i++)
  {
     for(j=1;j<=nb;j++)
     {
        if(block[j]!=1)
        {
           temp=b[j]-p[i];
           if(temp>=0)
           {
              if(top<=temp)
              {
                 process[i]=j;
                 top=temp;
              }  
           }
        }
     }
     fragments[i]=top;
     block[process[i]]=1;
     top=0;
  }
  printf("Process.No\tProcess Size\tBlock.No\tBlock Size\tFragment\n");
  for(i=1;i<=np&&process[i]!=0;i++)
  {
     printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,p[i],process[i],b[process[i]],fragments[i]);
  }
  return 0;
}
/*
OUTPUT
======
Enter the number of blocks:3
Enter the size of block 1:2 
Enter the size of block 2:9
Enter the size of block 3:5
Enter the number of processes:3
Enter the size of process 1:2
Enter the size of process 2:1
Enter the size of process 3:2
Process.No	Process Size	Block.No	Block Size	Fragment
1		2		2		9		7
2		1		3		5		4
3		2		1		2		0
*/
