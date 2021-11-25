#include<stdio.h> 
#include <time.h>
/*
average complexity (for uniformly distributes values) --> O(loglogn) 
worst case (the numerical values of the keys increase exponentially) -->  O(n) */
  
//if the key exists in our array it returns its position, and -1 otherwise.
int interp_Search(int a[], int n, int key) 
{ 
    int low = 0, high = (n-1);
    
    while (low <= high && key >= a[low] && key <= a[high]) 
    { 
        if (low == high)
		{ 
            if (a[low] == key) 
			return low; 
			
        	return -1; 
        } 
        
    int next = low + (((double)(high-low) / (a[high]-a[low]))*(key - a[low])); 
  
        //If our key is located in position next, we return next as position
        if (a[next] == key) 
            return next; 
  
        //If key is larger than next we'll search from next + 1 till highest element
        if (a[next] < key) 
            low = next + 1; 
  
    	//If key is smaller than next we'll search from lowest element till next - 1
		else
            high = next - 1; 
    } 
    return -1; 
} 
  

int main() 
{ 
     
    int a[500000]; 
    int i;
    int n = sizeof(a)/sizeof(a[0]); 
    for (i = 0; i < n; i++) 
	{
    	a[i] = i;
    }
    int key;
    
	 printf("What number are you searching for?\n");
     scanf("%d", &key);
    clock_t t; 
    t = clock(); 
    int idx = interp_Search(a, n, key); 
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
   
    //If value -1 isn't returned(value has been found)
    if (idx != -1) 
    {
        printf("Number %d found at location %d of your array.\n", key ,idx); 
        printf("Time taken %lf",time_taken);
	}        
    else
    {
        printf("Couldn't find %d in your array.\n", key); 
        printf("Time taken %lf",time_taken);
	}
        
    return 0; 
} 
