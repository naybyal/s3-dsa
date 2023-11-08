#include<stdio.h>
int a[20],size,front,rear;
void enq(int y){
	if((rear+1)%size==front)
		printf("\nQueue is FULL!\n");
	else if(front==-1&&rear==-1){
		front=0;
		rear=0;
		a[rear]=y;
	}
	else{
		rear = (rear+1)%size;
		a[rear]=y;
	}
}
void deq(){
	if(front==-1&&rear==-1)
		printf("\nQueue is EMPTY.\n");
	else if(front==rear){
		printf("%d dequeued\n", a[front]);
		front=rear=-1;
	}
	else{
		printf("%d dequeued.\n",a[front]);
		front=(front+1)%size;
	}
}
void display(){
	int i;
	if(front==-1&&rear==-1)
		printf("Queue is EMPTY!\n");
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
void main(){
	int item,x;
	front=-1; rear=-1;
	printf("Enter the size of queue..");
	scanf("%d", &size);
	do{
		printf("Enter choice!");
		printf("\n1) ENQUEUE\n2) DEQUEUE\n3) DISPLAY\n4)EXIT\n");
		scanf("%d", &x);
		switch(x){
			case 1:
				printf("Enter the item...");
				scanf("%d", &item);
				enq(item);
				break;
			case 2:
				deq();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("\nInvalid Choice!\n");
				break;
		}
	}while(x!=4);
	
}
