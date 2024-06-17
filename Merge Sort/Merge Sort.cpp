#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

// Function to merge two sorted parts of an array a
void merge(int a[],int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int h=low;
	
	// Temporary array to store sorted elements
	int b[MAX];
	int k;
	
	// Compare the elements of both the array parts and transfer the elements in ascending order to array b
	while(h<=mid&&j<=high)
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h=h+1;
		}
		else
		{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	
	//Transfer the remaining elements from two sorted subparts of array a to array b
	if(h>mid)
	{
		for(k=j;k<=high;k++){
			b[i]=a[k];
			i=i+1;
		}
	}
	else
	{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i=i+1;
		}
	}
	
	// Transfer all the content from array a to array b
	for(k=low;k<=high;k++){
		a[k]=b[k];
	}
}

// Sort and merge the subproblems
void sort(int a[],int low,int high)
{
	// To check overflow condition
	if(low<high)
	{
		// Divide the problem into subproblems
		int mid=(low+high)/2;
		
		// Solve the subproblems
		sort(a,low,mid);
		sort(a,mid+1,high);
		
		// Combine the solution
		merge(a,low,mid,high);
	}
}

int main()
{
	int n,i;
	clock_t start,end;
	
	// Seed the random number generator with the current time
	srand(time(NULL));
	
	// Repeat until the user enters 0
	do
	{
		// Prompt the user to enter the number of inputs
		printf("Enter the number of Inputs(0 to exit): ");
		scanf("%d",&n);
		
		// If the user enters 0, exit the loop
		if(n==0)
		break;
		
		// Declare an array of size n
		int a[n];
		
		// Fill the array with random numbers between 0 and 99
		for(i=0;i<n;i++){
			a[i]=rand()%100;
		}
		
		// Record the starting time
		start=clock();
		
		// Perform merge sort on the array
		sort(a,0,n-1);
		
		// Record the ending time
		end=clock();
		
		// Calculate the time taken to sort the array
		double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
		
		// Print the time taken
		printf("Time taken: %f seconds\n",time_taken);
	}while(1);
	return 0;
}
