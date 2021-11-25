#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>

int bis(int Array[],int x)
{
	int i;
	int hitpos;
	int left = 1;
	int right = sizeof(Array)/sizeof(Array[0]);
	int size = right - left + 1;
	int next;
	int a = x - Array[left];
	int b = Array[right]-Array[left];
	int c = right - left + 1;
	int d = (int)(i*sqrt(size));
	next = (size*a/b+1);
	do
	{
		i=0;
		size = right - left +1;
		if(x >= Array[next])	
		{
			do
			{
				i = i+1; //  i= 2*i
				right = next + i*sqrt(size);
				left = next + (i-1)*sqrt(size);
				
			}
			while(x > Array[next + d -1]);
		}
		else if(x < Array[next])
		{
			do
			{
				i = i+1;  //  i= 2*i
				right = next -(i-1)*sqrt(size);
				left = next - i*sqrt(size);
				next = left + (c*a/b);
			}
			while(x < Array[next - d + 1]);
		}
		else if(x == Array[next])
		{
			return next;
		}
		else
		{
			return -1;
		}	
	}
	while (x != Array[next]);
	
	
}

int main()
{
	int k;
	int Array[500000];
	int n = sizeof(Array) / sizeof(Array[0]);
	for (k = 0; k < n; k++) 
	{
    	Array[k] = k;
    }
	printf("Please provide a number for binary interpolation search\n");
	int x;
	scanf("%d", &x);
	int hit;
	clock_t t; 
    t = clock();
	hit = bis(Array,x);
	if (hit != -1) 
	{
        printf("Element found at index %d\n", hit); 
    }
    else
        printf("Element not found.\n");
	
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken %lf",time_taken); 
    return 0;
	
}
