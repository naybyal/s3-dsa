#include<stdio.h>

int i,q[30],stack[30],top,front,rear,size,item;

void enq() {
    if(front==0 && rear == size-1) {
        printf("The queue is full!");
    }
    else {
        printf("Enter the item to insert... ");
        scanf("%d", &item);
        if (front==-1 && rear == -1) {
            front=0;rear=0;
            q[rear] = item;
        }
        else {
            rear++;
            q[rear]=item;
        }
    }
}
void disp() {
    if(front==-1 && rear==-1) {
        printf("The queue is empty!"); 
    }
    else {
        printf("The queue elements are... \n");
        for(i=front;i<=rear;i++) 
            printf("%d\t", q[i]);
    }
}

void rvrse() {
    top=0;
    while(top!=size) {
        stack[top]=q[front];        //DEQ+PUSH
        top++;
        front++;
    }
    top--;
    rear=0;
    while(top!=-1) {
        q[rear] = stack[top];       //POP+ENQ
        top--;
        rear++;
    }
    rear--;
    front=0;
}
void main() {
    top=-1; front=-1; rear=-1;
    int choice;
    printf("Enter the size of the queue...");
    scanf("%d", &size);
    do{
        printf("\nQueue operation : 1) ENQ  2) REV 3) DISP 4) EXIT ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                enq();
                break;
            case 2:
                rvrse();
                break;
            case 3:
                disp();
                break;
            case 4:
                printf("The program exited successfully!");
                break;
            default:
                printf("Invalid choice! Try Again.");
                break;
        }
    }while (choice!=4);
}