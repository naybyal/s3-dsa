#include<stdio.h>

int a[60],top,size;

void push() {
    if(top==size-1) {
        printf("Stack is full!");
    }
    else {
        int item;
        top++;
        printf("\nEnter item to push to the stack... ");
        scanf("%d", &item);
        a[top] = item;
    }
}
void pop() {
    if(top==-1)
        printf("\nStack is empty. There's nothing to pop.\n");
    else if (top==0) {
        printf("\nLast item, %d has been popped and the stack is now empty!",a[top]);
        top=-1;
    }
    else {
        printf("\n%d popped.",a[top]);
        top--;
    }
}
void display() {
    if(top==-1) 
        printf("\n There's nothing here to display as the stack is empty.\n");
    else {
        int i;
        printf("Stack elements are...\n");
        for(i=0;i<=top;i++) {
            printf("%d\t",a[i]);
        }
    }
}
void status() {
    if(top==size-1) {
        printf("\n100%% : Stack is FULL!\n");
    }
    else {
        float free;
        free = (float)(size-top-1)*100/size;
        printf("%0.2f%% : Left to use.\n", free);
    }
}
void main() {
    printf("Enter stack size... ");
    scanf("%d", &size);
    int opt;
    top=-1;
    do{
        printf("\nOptions : 1) PUSH 2) POP 3) STATUS 4) DISPLAY 5) EXIT ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                status();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("---PROGRAM EXITED SUCCESSFULLY!---");
                break;
            default:
                printf("Wrong choice. Try Again!");
                break;
        }
    }while(opt!=5);
}