#include <stdio.h>
#include <time.h>
//complexity --> O(N)

int main()
{
   int a[500000];
   int n = sizeof(a)/sizeof(a[0]);
   int srch, i,k;
   for (k = 0; k < n; k++) 
	{
    	a[k] = k;
    }
   
   printf("What number are you searching?\n");
   scanf("%d", &srch);
	clock_t t; 
    t = clock(); 
   // I iterate through the array and search for each element
   for (i= 0; i< n; i++)
   {
      if (a[i] == srch)     //If the element I'm searching for is found
      {
         printf("Number %d is located in position %d of the array.\n", srch, i+1);
         break;
      }
   }
   if (i== n)
      printf("Couldn't find number %d in array.\n", srch);

	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken %lf",time_taken);
   return 0;
}


