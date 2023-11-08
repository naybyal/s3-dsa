#include<stdio.h>

int a[45], size,i;

void readArray(int n) {
    printf("Reading array...\n");
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
}
void addElement() {
    /*
        Cases : 
            1) No space in array
            2) Insert at a position
    */
    int pos,x;
    printf("Enter the position to insert the element... ");
    scanf("%d", &pos);
    if(pos>=45) {
        printf("\nInsertion not possible.\n");
    }
    else {
        size++;
        for(i=size-1;i>=pos;i--) {
            a[i]=a[i-1];
        }
        printf("Enter the item to insert... ");
        scanf("%d", &x);
        a[pos]=x;
    }

}
void removeElement() {
    int pos;
    printf("Enter the position to delete the element... ");
    scanf("%d", &pos);
    if(pos>=size) 
        printf("\nDeletion not possible.\n");
    else {
        for(i=pos;i<size;i++) {
            a[i] = a[i+1];
        }
        size--;
    }
}
void displayArray() {
    for(i=0;i<size;i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void main() {
    int opt;
    printf("Enter the array size... ");
    scanf("%d", &size);
    readArray(size);
    printf("The array is... \n");
    displayArray();
    do {
        printf("\nDo What?! 1) Add Element 2) Remove Element 3) Diplay Array 4) Exit ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                addElement();
                break;
            case 2:
                removeElement();
                break;
            case 3:
                displayArray();
                break;
            case 4:
                printf("\n---THE PROGRAM EXITED SUCCESSFULLY!---\n");
                break;
            default:
                printf("\nINVALID CHOICE!\n");
                break;
        }
    }while(opt!=4);

}