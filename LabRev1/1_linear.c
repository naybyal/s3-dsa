#include<stdio.h>
void main() {
    int a[10];
    int x, i, n,flag=0, pos=0;
    printf("Enter array size.. ");
    scanf("%d",&n);
    printf("Reading array...\n");
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter key to search... ");
    scanf("%d", &x);
    for(i=0;i<n;i++) {
        if(a[i] == x) {
            flag = 1;
            pos += i;
            break;
        }
    }
    if(flag == 1) 
        printf("%d found at index, %d.\n", x,pos);
    else
        printf("%d not found.\n", x);
}