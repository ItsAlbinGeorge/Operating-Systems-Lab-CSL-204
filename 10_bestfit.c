/*
                                                                   Program.No:10
                                                             BEST FIT STORAGE ALOCATION
                                                            ============================
*/
#include<stdio.h>
int main()
{
  int i,j,nb,np,temp,fragments[10],b[10],p[10],lowest=9999;
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
              if(lowest>temp)
              {
                 process[i]=j;
                 lowest=temp;
              }  
           }
        }
     }
     fragments[i]=lowest;
     block[process[i]]=1;
     lowest=10000;
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
Enter the size of block 1:9
Enter the size of block 2:3
Enter the size of block 3:6
Enter the number of processes:3
Enter the size of process 1:8
Enter the size of process 2:4
Enter the size of process 3:2
Process.No	Process Size	Block.No	Block Size	Fragment
1		8		1		9		1
2		4		3		6		2
3		2		2		3		1
*/
