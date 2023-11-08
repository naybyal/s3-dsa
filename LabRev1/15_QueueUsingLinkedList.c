#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
}*ptr, *new;

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    int item;
    printf("Enter the item to enqueue.... ");
    scanf("%d", &item);
    new = (struct node*)malloc(sizeof(struct node*));
    new->data = item;
    new->link = NULL;
    if(front==NULL && rear==NULL) {
        front=rear=new;
    }
    else {
        rear->link = new;
        rear = new;
    }
    printf("%d enqueued.\n", new->data);
}
void dequeue() {
    if(front==NULL)
        printf("Queue is empty!\n");
    else {
        ptr=front;
        printf("%d dequeued. \n", front->data);
        front = front->link;
        if(front==NULL)
            rear=NULL;
        free(ptr);
    }
}
void display() {
    ptr = front;
    if(front==NULL && rear==NULL)
        printf("Queue is empty!\n");
    else {
        printf("The elements in queue are... \n");
        while(ptr!=rear->link) {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
}
void main() {
    int opt;
    do {
        printf("Enter choice... 1) ENQ 2) DEQ 3) DISP 4) EXIT  ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(opt!=4);
}