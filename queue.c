#include<stdio.h>
int A[20];
int FRONT,REAR,SIZE;
void ENQUEUE(int val)
{
	if(REAR==-1)
	{
		FRONT=0;
		REAR=0;
		A[REAR]=val;
	}
	else 
	{
		REAR++;
		A[REAR]=val;
	}
}
void DEQUEUE()
{
	if(FRONT==REAR)
	{
		printf("The last element to be dequeued is %d", A[FRONT]);
		FRONT=-1;
		REAR=-1;
	}
	else
	{
		printf("%d has been dequeued...\n", A[FRONT]);
		FRONT++;
	}
}
void DISPLAY()
{
	int i;
	if(FRONT==-1)
		printf("Nothing to display as the queue is empty...\n");
	else
	{
		for(i=FRONT;i<REAR;i++)
			printf("%d\t", A[i]);
	}
}
void main()
{
	int size,x,item;
	FRONT=-1;
	REAR=-1;
	printf("Enter queue size...");
	scanf("%d", &SIZE);
	do{
		printf("Enter choice...\n");
		printf("1) ENQUEUE\n2) DEQUEUE\n3) DISPLAY\n4) EXIT\n");
		scanf("%d", &x);
		switch(x)
		{
			case 1:
				if(REAR==SIZE-1)
					printf("Queue is FULL!");
				else
				{
					printf("Enter the element to enqueue...\n");
					scanf("%d", &item);
					ENQUEUE(item);
				}
				break;
			case 2:
				if(FRONT==-1&&REAR==-1)
					printf("Queue is EMPTY...\n");
				else
				{
					DEQUEUE();
				}
				break;
			case 3:
				printf("The items in queue are...\n");
				DISPLAY();
				break;
			case 4:
				break;
		}
	}while(x!=4);
}
