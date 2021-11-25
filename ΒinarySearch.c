#include <stdio.h>
#include <time.h>
//average complexity --> O(logN)

int main()
{
   int c, first, last, mid , srch,k;
   int a[500000];
   int n = sizeof(a) / sizeof(a[0]);
   for (k = 0; k < n; k++) 
	{
    	a[k] = k;
    }
			     
   printf("What number are you searching for?\n");
   scanf("%d",&srch);

   first = 0;
   last = n - 1;
   mid = (first+last)/2;
	clock_t t; 
    t = clock();  
   while( first <= last )
   {  
      //If the element we are looking for is larger that the median, I search in the second half of the array
      if (a[mid] < srch) 
      
         first = mid + 1;
      
	  //If the element we're looking for is the median we stop here.  
      else if ( a[mid] == srch )
      {
         printf("Number %d found at location %d of your array.\n", srch, mid+1);
         break;
      }
      
      //Or else, we look in the first half of the array
      else
         last = mid - 1;

      mid = (first + last)/2; //I replace mid for new first and last 
   }
   if ( first > last )//I have iterated the entire array
      printf("Couldn't find %d in your array.\n", srch);
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken %lf",time_taken);
   return 0;
}
