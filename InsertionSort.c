#include<stdio.h>
#include<math.h>
#include <time.h>

// Worst case time complexity O(2n)
  
void insertionSort(int a[], int n) 
{
	int i; 
	for (i = 1; i < n; i++)
	// insert a[i] into a[0:i-1]
	{
 		int t = a[i];
 		int j;
 		for (j = i - 1; j >= 0 && t < a[j]; j--)
 		{ //I insert the largest element of the position before j to position j+1 and I check for element j-1
  			a[j + 1] = a[j];
 		}
 		a[j + 1] = t;
	}	
}
  
// Function that prints the Array
void printArray(int a[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int a[50000]; 
    int n = sizeof(a) / sizeof(a[0]);
	srand(time(NULL));
    int i;
    for (i = 0; i < n; i++) 
	{
    	a[i] = rand();
    }
	clock_t t; 
    t = clock(); 
    insertionSort(a, n);
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printArray(a, n); 
	printf("Time taken %lf",time_taken); 
    return 0; 
} 
