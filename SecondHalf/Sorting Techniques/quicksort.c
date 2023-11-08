#include <stdio.h>
int mid,low,high,i,j,n,temp;
int arr[20];

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void readData() {
    printf("Enter The Size : ");
    scanf("%d",&n);
    printf("Enter The Elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}


int partition(int arr[10], int low, int high) {
    i = low;
    j = high;
    int pivot = low;
    while(i<j) {
        while(arr[i]<arr[pivot])
            i++;
        while(arr[j]>arr[pivot])
            j--;
        if (i<j) {
            	swap(&arr[i],&arr[j]);
        }
    }
    return j;
}

void quickSort(int arr[10], int low, int high) {
    if(low<high) {
        j = partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

void Display() {
    printf("Sorted Array : \n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
}

void main() {
    readData();
    low=0;high-n-1;
    quickSort(arr,low,high);
    Display();
}



