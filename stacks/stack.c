#include<stdio.h>

#define MAX_SIZE 4
int TOP=-1;
int stack[MAX_SIZE];
void Push()
{
	if(TOP==MAX_SIZE)
		printf("\nOverflow!\n");
	else
	{
		int x;
		TOP++;
		printf("\nEnter element... ");
		scanf("%d", &x);
		stack[TOP]=x;
		printf("\nElement added to the stack!\n");
	}
}
void Pop()
{
	if(TOP==-1)
		printf("\nStack is empty!\n");
	else
	{
		TOP--;
		printf("Element removed!");
	}
}
void Display()
{
	 int i;
	 if(TOP==-1)
	 {
		 printf("\nThe stack is empty!\n");		
	 }
	 else
	 {
	 	printf("/nThe items in the stack are...\n");
	  	for(i=0;i<=TOP;i++)
		printf("%d\t",stack[i]);
	 }
}
int main()
{
	int i,choice;
	printf("----STACK OPERATIONS----\n");
	printf("1) PUSH\n2) POP\n3) DISPLAY\n4) Exit\n");
	
	do{
		printf("Choice?..");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				Push();
				break;
			case 2:
				Pop();
				break;
			case 3:
				Display();
				break;
			case 4:
				printf("The program exited successfully!\n");
				break;
			
			default:
				printf("Try again (1/2/3/4)\n");
			
		}
	}while(choice!=4);
	return 0;
}
