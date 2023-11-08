#include<stdio.h>

int a[60],front,rear,size;

void enq() {
    if(front == 0 && rear == size-1) {
        printf("Queue is FULL!\n");
    }
    else {
        int item;
        printf("Enter the item to enqueue... ");
        scanf("%d", &item);
        if(front==-1&&rear==-1) {
            front++;
            rear++;
            a[rear] = item;
            printf("%d inserted.\n", a[rear]);
            printf("(%d,%d)\n", front,rear);
        }
        else {
            rear++;
            a[rear] = item;
            printf("%d inserted.\n",a[rear]);
            printf("(%d,%d)\n", front,rear);
        }
    }
}

void deq() {
    if(front==-1 && rear==-1) {
        printf("Queue is EMPTY!\n");
        printf("(%d,%d)\n", front,rear);
    }
    else if(front==rear) {
        printf("\n%d dequeued.\n", a[front]);
        front=rear=-1;
        printf("(%d,%d)\n", front,rear);
    }
    else {
        printf("\n%d dequeued.\n", a[front]);
        front++;
        printf("(%d,%d)\n", front,rear);
    }
}

void disp() {
    if(front==-1 && rear==-1) {
        printf("Queue is empty. There's nothing to display.");
    }
    else {
        int i;
        printf("The elements in queue are...\n");
        for(i=front;i<=rear;i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
}
void main() {
    front = rear = -1;
    int opt;
    printf("Enter queue size... ");
    scanf("%d", &size);
    do {
        printf("Options : 1) ENQ 2) DEQ 3) DISP 4) EXIT ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                disp();
                break;
            case 4:
                printf("----PROGRAM EXITED SUCCESSFULLY!----\n");
                break;
            default:
                printf("Invalid choice. Try Again!\n");
                break;
        }
    }while(opt!=4);
}