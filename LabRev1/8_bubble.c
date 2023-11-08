#include<stdio.h>
void main() {
    int arr[20],n,x,y,temp;
    printf("Enter array size.. ");
    scanf("%d", &n);
    printf("Reading array...\n");
    for(x=0;x<n;x++)
        scanf("%d", &arr[x]);
    printf("\n---BEFORE SORT---\n");
    for (x=0;x<n;x++)
        printf("%d\t", arr[x]);
    //Bubble Sort..
    for(x=0;x<n;x++) {
        for(y=0;y<n-x-1;y++) {
            if (arr[y]>arr[y+1]) {
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
    printf("\n---AFTER SORT---\n");
    for (x=0;x<n;x++)
        printf("%d\t", arr[x]);
}