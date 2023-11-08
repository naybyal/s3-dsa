#include<stdio.h>

int a[60],front,rear,size;

void enq() {
    if(front == (rear+1)%size) {
        printf("Circular Queue is FULL!\n");
    }
    else {
        int item;
        printf("Enter the item to enqueue... ");
        scanf("%d", &item);
        if(front==-1&&rear==-1) {
            front = 0;
            rear = 0;
            a[rear] = item;
            printf("%d inserted.\n", a[rear]);
        }
        else {
            rear=(rear+1)%size;
            a[rear] = item;
            printf("%d inserted.\n",a[rear]);
        }
    }
}

void deq() {
    if(front==-1&&rear==-1) {
        printf("Circular Queue is EMPTY!\n");
    }
    else if(front==rear) {
        printf("\n%d dequeued.\n", a[front]);
        front=rear=-1;
    }
    else {
        printf("\n%d dequeued.\n", a[front]);
        front = (front+1)%size;
    }
}

void disp() {
    int i;
    if(front==-1&&rear==-1) {
        printf("Queue is empty. There's nothing to display.");
    }
    else if(front<=rear){
		for(i=front;i<=rear;i++){
			printf("%d\t", a[i]);
		}
	}
	else{
		for(i=front;i<size;i++){
			printf("%d\t",a[i]);
		}
		for(i=0;i<=rear;i++){
			printf("%d\t",a[i]);
		}
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