#include<stdio.h>
void insert(int arr[], int size)
{
	int pos,x;
	printf("\nEnter the position to insert...");
	scanf("%d", &pos);
	

		if(pos>size)
			printf("\nElement INSERTION not possible.");
		else
		{
			int y;
			for(y=size;y>=pos;y--)
			{
				arr[y+1]=arr[y];
			}
			printf("Enter the element to insert...");
			scanf("%d", &x);
			arr[pos]=x;
			printf("\nThe manipulated array is...\n");
			for(y=0;y<size+1;y++)
				printf("%d\t", arr[y]);
			printf("\n");
		}
	
}
void delete(int arr[], int size)
{
	int j,pos, temp;
	for(j=0;j<size;j++)
		printf("\narr[%d] = %d\n", j,arr[j]);
	printf("Enter the index to delete...");
	scanf("%d", &pos);
	if(pos>=size)
		printf("\nElement DELETION is not possible.\n");
	else
	{
		for(j=pos;j<size;j++)
		{
			temp = arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		printf("\nThe manipulated array is...\n");
		for(j=0;j<size-1;j++)
			printf("%d\t", arr[j]);
		printf("\n");
	}
}
void traverse(int arr[],int size)
{
	int x;
	printf("\nThere are %d elements in the array.\n", size);
	printf("Enter the index to display...");
	scanf("%d", &x);
	printf("The element at position %d is %d", x, arr[x]);
}
void main()
{
	int n,i,a[20],choice;
	printf("Reading size...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	do{
		printf("\nDo What?!\n1) Insert element \n2) Delete element \n3) Traverse\n4) EXIT\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				insert(a,n);
				break;		
			}
			case 2:
			{
				delete(a,n);
				break;
			}
			case 3:
			{
				traverse(a,n);
				break;
			}			
			case 4:
			{
				printf("\nProgram exited successfully!\n");
				break;
			}
			default:
			{
				printf("\nTry Again! (1/2/3)\n");
			}
		}

	} while (choice!=4);


}
