
#include<stdio.h>

/***********************variable initialize************************/

int max[50][50];//maximum resource
int alloc[50][50];//allocated resource
int need[50][50];//need resource
int avail[50];//available resource
int n,r;//process number and resource number


void calculation();
int main()
{
  /*
   * In this section,please input processes,resource instances, allocation matrix,available resources
   * that represnet state of the given system 
   */
  int i,j;
  printf("<<<====================== Deadlock Detection Algorithm start... ========================>>>\n");
  printf("Enter the number of Processes:");
  scanf("%d",&n);
  printf("Enter the number of resources:");
  scanf("%d",&r);
  printf("Enter the Process Matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&max[i][j]);
     }
  }
  printf("Enter the Allocation Matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&alloc[i][j]);
    }
  }
  printf("Enter the available Resources\n");
  for(j=0;j<r;j++)
  {
    scanf("%d",&avail[j]);
  }
  
  /*
   * In this section,display available process,resource list.
   * 
   */
          
  printf("Process\t Allocation\t Max\t Available\t");
  for(i=0;i<n;i++)
  {
    printf("\nP%d\t   ",i+1);//display give system process
    for(j=0;j<r;j++)
    {
      printf("%d ",alloc[i][j]);//display allocated resource list
    }
    printf("\t");
    for(j=0;j<r;j++)
    {
      printf("%d ",max[i][j]); //display maximum resource list
    }
    printf("\t");
    if(i==0)
    {
      for(j=0;j<r;j++)
      printf("%d ",avail[j]);//display availabe resource list
    }
  }
  calculation();
  return 0;
}

/*
   * In this section,calculate dead process and safe process
   *  
   */

void calculation()
{
  int finish[50],temp,need[50][50],flag=1,k,c1=0;
  int dead[50];//dead process
  int safe[50];//safe process
  int i,j;
  for(i=0;i<n;i++)
  {
    finish[i]=0;
  }
  //find need matrix
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }
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
           
            if(finish[i]==1)
            {
              i=n;
            }
	    
	  }
	  
	}
	
      }
      
    }
  }
  j=0;
  flag=0;
  for(i=0;i<n;i++)
  {
    if(finish[i]==0)
    {
      dead[j]=i;
      j++;
      flag=1;
    }
  }
  if(flag==1)
  {
    printf("\n\n now,System is in Deadlock and the Deadlock process are\n");
    for(i=0;i<n;i++)
    {
      printf("P%d\t",dead[i]);
    }
  }
  else
  {
    printf("\nNo Deadlock Occur\n");
  }  
}
