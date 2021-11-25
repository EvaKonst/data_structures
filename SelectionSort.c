#include <stdio.h> 
#include<time.h>

//Worst case complexity O(n*n)

//Swap function  
void swap(int *l1, int *l2) 
{ 
    int temp = *l1; 
    *l1 = *l2; 
    *l2 = temp; 
} 
  
void SelectionSort(int list[], int n)
{
    int i,j,swap,position;

    for ( i = 0 ; i < ( n - 1 ) ; i++ )
    {

        position = i;

        for ( j = i + 1 ; j < n ; j++ )
        {
            if ( list[position] > list[j] )
                position = j; //Retain in memory the position of the most recent smallest number
        }
        if ( position != i )
        {
            swap = list[i];
            list[i] = list[position];
            list[position] = swap;
        }
    }


}
// Function that prints the Array
void printlist(int list[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", list[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int list[50000]; 
    int n = sizeof(list)/sizeof(list[0]); 
    srand(time(NULL));
    int k;
	for (k = 0; k < n; k++) 
	{
    	list[k] = rand();
    }
    clock_t t; 
    t = clock(); 
    SelectionSort(list, n); 
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printlist(list, n);
	printf("Time taken %lf",time_taken);  
    return 0; 
} 

