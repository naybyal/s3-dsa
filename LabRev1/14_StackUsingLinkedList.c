#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
}*top, *ptr, *new;

void push() {
    int item;
    printf("Enter the item to push... ");
    scanf("%d", &item);
    new = (struct node*)malloc(sizeof(struct node*));
    new->link = top;
    new->data = item;
    top = new;
}
void pop() {
    if(top==NULL) {
        printf("Stack is EMPTY!\n");
    }
    else {
        ptr = top;
        top = ptr->link;
        free(ptr);
    }
}
void display() {
    if(top==NULL)
        printf("Stack is empty!\n");
    else {
        printf("The stack items are.. \n");
        ptr=top;
        while(ptr!=NULL) {
            printf("%d\t",ptr->data);
            ptr = ptr->link;
        }
    }   
}
void main() {
    int opt;
    do {
        printf("Enter choice... 1) PUSH 2) POP 3) DISPLAY 4) EXIT   ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!");
                break;
        }
    }while(opt!=4);
}