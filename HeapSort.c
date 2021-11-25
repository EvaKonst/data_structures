#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//worst case complexity --> O(nlogn)

//Values of the Heap that will be constructed based on the array (a /*array) of the elements 
struct Heap
{
    int size;
    int* array;
};

// Function for swapping values
void swap(int* a, int* b) 
{
	int t = *a; 
	*a = *b;  
	*b = t; 
}

// Function that will heapify our heap. Any element under the root (pointer i) is already heapified.
void Heapify(struct Heap* heap, int i)
{
    int max = i;  // Initializing: Largest element ---> root
    int leftChild = (i << 1) + 1;  // leftChild = 2*i + 1
    int rightChild = (i + 1) << 1; // rightChild = 2*i + 2

    // Checking if the leftChild of the root exists and is larger that the root
    if (leftChild < heap->size && heap->array[leftChild] > heap->array[max])
        max = leftChild;

    if (rightChild < heap->size && heap->array[rightChild] > heap->array[max])
        max = rightChild;

    // Changing the root if it's not the largest number in the heap and heapify again
    if (max != i)
    {
        swap(&heap->array[max], &heap->array[i]);
        Heapify(heap, max);
    }
}

// This function will build a heap with given size 
struct Heap* makeHeap(int *array, int size)
{
    int i;
    struct Heap* heap = (struct Heap*) malloc(sizeof(struct Heap));
              
    heap->size = size;   
    heap->array = array; // Adress of the first element in the array
    
    // Starting from the right-most leaf and heapify moving upwards, until there are either no more heapifying operations needed or I've reached the root
    for (i = (heap->size - 2) / 2; i >= 0; --i)
        Heapify(heap, i);
        
    return heap;
}

// The fuction that will sort the array
void heapSort(int* array, int size)
{
    // Building a heap off my elements
    struct Heap* heap = makeHeap(array, size);

    while (heap->size > 1) //The last element of my heap will be the smallest one
	    {
        /* The largest element of the heap will be located in the root. I swap the root with the smallest element in the heap(array[0]) and 
		reduce the size of the heap by one*/
        swap(&heap->array[0], &heap->array[heap->size - 1]);
        --heap->size;  

        //I heapify with my new root
        Heapify(heap, 0);
    }
}

void printArray(int* array, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", array[i]);
}

/* Driver program to test above functions */
int main()
{
    int a[50000];
    int size = sizeof(a)/sizeof(a[0]);
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++) 
	{
    	a[i] = rand();
    }
    clock_t t; 
    t = clock(); 
    heapSort(a, size);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printArray(a, size);
    printf("Time taken %lf",time_taken);
    return 0;
}
