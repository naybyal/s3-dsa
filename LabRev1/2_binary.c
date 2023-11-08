#include<stdio.h>
void main() {
    int a[10], low, mid, high,n,i,j;
    int x,flag=0;
    printf("Enter the size of the array... ");
    scanf("%d", &n);
    printf("Reading array...\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    low = 0, high = n-1;
    printf("Enter the item to search for... ");
    scanf("%d", &x);
    while(low<=high) {
        mid = (low+high)/2;
        if(a[mid] == x) {
            flag=1;
            break;
        }
        else if (a[mid] < x) {
            low = mid+1;
        }
        else {
            high =  mid-1;
        }
    }
    if(flag==1)
        printf("Item found at position %d.", mid);
    else 
        printf("Item not found.");
}