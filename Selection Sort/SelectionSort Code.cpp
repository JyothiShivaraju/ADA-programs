#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform selection sort on an array
void selectionSort(int arr[],int n){
    int i,j,min_idx;
    
    // Loop through the array
    for(i=0;i<n-2;i++){
        // Assume the current element is the minimum
        min_idx=i;
        
        // Find the index of the minimum element in the unsorted part of the array
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min_idx])
                min_idx=j;
        
        // Swap the current element with the minimum element found
        if(min_idx!=i){
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
    }
}

int main(){
    int n,i;
    clock_t start,end;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Repeat until the user enters 0
    do{
        // Prompt the user to enter the number of inputs
        printf("ENTER THE NUMBER OF INPUTS (0 to exit): ");
        scanf("%d",&n);

        // If the user enters 0, exit the loop
        if (n==0)
          break;

        // Declare an array of size n
        int arr[n];
        
        // Fill the array with random numbers between 0 and 99
        for(i=0;i<n;i++){
            arr[i]=rand()%100;
        }

        // Record the starting time
        start=clock();
        
        // Perform selection sort on the array
        selectionSort(arr,n);
        
        // Record the ending time
        end=clock();

        // Calculate the time taken to sort the array
        double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
        
        // Print the time taken
        printf("Time taken: %.3f seconds\n",time_taken);
    }while (1);
    
    return 0;
}
