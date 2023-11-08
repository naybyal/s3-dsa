#include <stdio.h>

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i=1; i<n; i++) {
		key = arr[i];
		j = i-1;
		while (j>=0 && arr[j]>key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	printf("The array is...\n");
	for (i=0;i<n;i++)
		printf("%d\t ", arr[i]);
	printf("\n");
}


void main()
{
	int arr[10];
	int i,n;
	printf("Enter array size....");
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printArray(arr,n);
	insertionSort(arr, n);
	printf("After sort...\n");
	printArray(arr, n);
}

