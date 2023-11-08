#include<stdio.h>

int size, front, rear;

struct p {
    int item;
    int priority;
}temp,a[20];

void enq(int x, int y) {
    if(front==-1 && rear ==-1) {
        front=0; rear=0;
        a[rear].item = x;
        a[rear].priority = y;
        printf("Enqueued... \n(front,rear) = (%d,%d)\n",front,rear);
    }
    
    else if (front>0 && rear==size-1) { /*There's space at front*/
        int i,j;
        //Shift elements to the left
        for(i=front;i<=rear;i++) {
            a[i-1] = a[i];
        }
        //Decrement front by 1
        front--;
        //Insert item and priority
        a[rear].item = x;
        a[rear].priority = y;
        printf("Enqueued...\n(front,rear) = (%d,%d)\n",front,rear);
        //Bubble sorting by priority
        for(i=front;i<=rear;i++){
            for(j=0;j<=rear-i-1;j++) {
                if(a[j].priority > a[j+1].priority) {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }

    else {
        int i,j;
        //increment rear by 1
        rear++;
        a[rear].item = x;
        a[rear].priority = y;
        printf("Enqueued... \n(front,rear) = (%d,%d)\n",front,rear);
        //Bubble sort by priority
        for(i=front;i<=rear;i++) {
            for(j=0;j<=rear-i-1;j++) {
                if(a[j].priority>a[j+1].priority)  {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }

}

void deq() {
    if(front==-1 && rear==-1) {
        printf("Priority Queue is empty!\n");
        printf("(front,rear)=(%d,%d)\n",front,rear);
    }
    else if (front==rear) {
        printf("%d dequeued with priority %d.",a[front].item,a[front].priority);
        front=rear=-1;
        printf("(front,rear)=(%d,%d)\n",front,rear);
    }
    else {
        printf("%d dequeued with priority %d.",a[front].item,a[front].priority);
        front++;
        printf("(front,rear)=(%d,%d)\n",front,rear);
    }
}

void disp() {
    if(front==-1 && rear==-1) {
        printf("Priority Queue is EMPTY!\n");
        printf("(front,rear)=(%d,%d)\n",front,rear);
    }
    else {
        int i;
        printf("The elements and their respective priorities are...\n");
        printf("\tITEM\tPRIORITY\n");
        for(i=front;i<=rear;i++) {
            printf("\t%d\t%d\n", a[i].item,a[i].priority);
        }
    }
}

void main() {
    int opt, it, prio;
    front=-1; rear=-1;
    printf("Enter the size of the Priority Queue... ");
    scanf("%d", &size);
    do {
        printf("Enter choice... 1) ENQ 2) DEQ 3) DISP 4) EXIT   ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                if(front==0 && rear==size-1) {
                    printf("OVERFLOW!\n");
                }
                else {
                    printf("Reading item and priority... \n");
                    scanf("%d%d", &it, &prio);
                    enq(it,prio);                
                }
                break;
            case 2:
                deq();
                break;
            case 3:
                disp();
                break;
            case 4:
                break;
            default:
                printf("\n---INVALID CHOICE!---\n");
                break;
        }

    }while(opt!=4);
}