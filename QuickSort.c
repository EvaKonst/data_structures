#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//Worst case complexity O(n^2)

void quick_sort(int list[],int first,int last);

int main()
{
	int list[50000];
	int n = sizeof(list) / sizeof(list[0]);
	int i,menu,k;
	srand(time(NULL));
	for (k = 0; k < n; k++) 
	{
    	list[k] = rand();
    }
    clock_t t; 
    t = clock(); 
	quick_sort(list,0,n-1);
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 	
    printf("quick sorted list: \n");
    for ( i = 0 ; i < n ; i++ )
            printf("%d ", list[i]);
        printf("\n");
        printf("Time taken %lf",time_taken);    
}

void quick_sort(int list[],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(list[i]<=list[pivot]&&i<last) //Iterates the list from left to right
                i++;
            while(list[j]>list[pivot])//Iterates the list from right to left
                j--;
            if(i<j)//Swap list[i] and list[j]
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }

        temp=list[pivot];
        list[pivot]=list[j];
        list[j]=temp;
        quick_sort(list,first,j-1); //Sort the elements that are smaller than list[pivot]
        quick_sort(list,j+1,last); //Sort the elements that are larger than list[pivot]

    }
}
