#include<stdio.h>
int a[40],i,front,rear,size;
void push() {
    if(front ==0 && rear==size-1)
        printf("dEQUE is Full!");
    else {
        int item;
        printf("Enter item to push... ");
        scanf("%d", &item);
        if (front==-1 && rear==-1) {
            front=0; rear=0;
            a[front] = item;
        }
        else if(front>0) {
            front--;
            a[front] = item;
        }
        else {
            for(i=rear;i>=front;i--) 
                a[i+1] = a[i];
            a[front] = item;
            rear++;
        }

    }
}
void display() {
    if (front==-1 && rear==-1)
        printf("DEQUE is empty!\n");
    else {
        for(i=front;i<=rear;i++)    
            printf("%d\t", a[i]);
    }
}
void pop() {
    if(front==-1 && rear==-1)
        printf("The deque is empty!");
    else if (front==rear) {
        printf("The last item, %d has been popped.\n", a[front]);
        front=-1; rear=-1;
    }
    else {
        printf("%d popped.\n", a[front]);
        front++;
    }
}
void inject() {
    if(front==0 && rear==size-1) 
        printf("The deque is full! \n");
    else {
        int item;
        printf("Reading item... ");
        scanf("%d", &item);
        if(front==-1 && rear==-1) {
            front=0; rear=0;
            a[rear] = item;
        }
        else if (rear<size-1) {
            rear++;
            a[rear] = item;
        }
        else {
            for(i=front;i<=rear;i++) {
                a[i-1] = a[i];
            }
            front--;
            a[rear] = item;
        }
    }
}
void eject() {
    if(front==-1 && rear==-1)
        printf("The deque is empty!\n");
    else if (front==rear) {
        printf("The last item, %d ejected.\n", a[rear]);
    }
    else {
        printf("%d ejected.\n", a[rear]);
        rear--;
    }
}
void main() {
    front=-1,rear=-1;
    printf("Enter deque size... ");
    scanf("%d", &size);
    int op;
    do {
        printf("\nChoice : 1) PUSH 2) POP 3)INJECT 4) EJECT 5) DISP 6) EXIT    ");
        scanf("%d", &op);
        switch(op) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                inject();
                break;
            case 4:
                eject();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice.");
                break;
        }
    }while(op!=6);
}
