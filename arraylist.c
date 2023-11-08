#include<stdio.h>
void addElement(int b[20], int num)
{	
	int pos,j;
	printf("Insertion position...");
	scanf("%d", &pos);
	if(pos>=num)
	{
		printf("Element insertion not possible...\n");
	}
	else
	{
		//shifting elements forward...
		num++;
		for(j=num-1;j>=pos;j--)
		{
			b[j]=b[j-1];
		}
		
		//inserting element
		int x;
		printf("Enter the element to be inserted...");
		scanf("%d", &x);
		b[pos-1]=x;
		printf("The resultant array is...\n");
		for(j=0;j<num;j++)
		{
			printf("arr[%d] = %d", j, b[j]);
			printf("\n");
		}
	}

}
void remElement(int b[20], int num)
{
	int pos,j;
	printf("Deletion position...");
	scanf("%d", &pos);
	if(pos>=num)
		printf("Element deletion not possible...\n");
	else
	{
		for(j=pos;j<num;j++)
		{
			b[j]=b[j+1];
		}
		//printing the resultant array
		printf("The resultant array is...\n");
		for(j=0;j<num-1;j++)
		{
			printf("arr[%d] = %d", j, b[j]);
			printf("\n");
		}
	}
}
void main()
{
	//Objective is to add element to/remove element from array using switch.
	int n,i,a[20],pos;
	printf("Enter the number of elements in array...\n");
	scanf("%d", &n);
	printf("Reading the array...\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//Displaying the array...
	printf("The array elements are...\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d] = %d",i,a[i]);
		printf("\n");
	}
	int c;
	printf("Do What?!\n1 : Add element to the array\n2 : Remove element from array");
	scanf("%d", &c);
	switch(c)
	{
		case 1:
			{
				addElement(a,n);
				break;
			}
		case 2:
			{
				remElement(a,n);
				break;
			}
	}
}
