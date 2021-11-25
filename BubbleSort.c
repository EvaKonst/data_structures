#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

//Worst case time complexity O(n*n)
void swap(int *n1, int *n2) 
{ 
    int temp = *n1; 
    *n1 = *n2; 
    *n2 = temp; 
} 
  
// Function that runs BubbleSort
void BubbleSort(int Array[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
           
       for (j = 0; j < n-i-1; j++)  
           if (Array[j] > Array[j+1]) 
              swap(&Array[j], &Array[j+1]); 
} 
  
// Function that prints the Array
void printArray(int Array[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", Array[i]); 
     
} 
  

int main() 
{ 
    int Array[50000]; 
    int n = sizeof(Array) / sizeof(Array[0]);
    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++) 
	{
    	Array[i] = rand();
    }
    clock_t t; 
    t = clock();  
    BubbleSort(Array, n); 
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printArray(Array, n); 
    printf("Time taken %lf",time_taken);
    return 0; 
}
