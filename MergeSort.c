#include<stdio.h>
#include<conio.h>
#include <time.h>

// Time complexity for all cases O(nlogn)


void merge(int Array[],int min,int mid,int max)
{
  int tmp[50000];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(Array[j]<=Array[m])
     {
         tmp[i]=Array[j];
         j++;
     }
     else
     {
         tmp[i]=Array[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=Array[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=Array[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     Array[k]=tmp[k];
}

void part(int Array[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(Array,min,mid);
   part(Array,mid+1,max);
   merge(Array,min,mid,max);
 }
}


void merge(int [],int ,int ,int );
void part(int [],int ,int );

int main()
{
 int Array[50000];
 int i;
 int size = sizeof(Array) / sizeof(Array[0]);
 srand(time(NULL));
 int l;
 for (l = 0; l < size; l++) 
 {
    Array[l] = rand();
 }
 clock_t t; 
 t = clock(); 
 part(Array,0,size-1);
 t = clock() - t;
 double time_taken = ((double)t)/CLOCKS_PER_SEC;
 for(l=0; l<size; l++)
 {
 	printf("%d ",Array[l]);
 }
 
 printf("Time taken %lf",time_taken); 
 return 0;
}
