#include<stdio.h>
void main()
{
	int n,a[20],pos, x,i,flag=0;
	printf("Enter array size...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d", &a[i]);
	}
	printf("Array read successfully!\n");
	printf("\nEnter the element to search for...");
	scanf("%d", &x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			pos = i;
			printf("\nElement found at position %d!\n", pos);
		}
		else
			printf("\nElement not found at %d!\n", i);
	}
	printf("\n---COMPLETE!---\n");
}
