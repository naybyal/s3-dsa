#include<stdio.h>
void main()
{
	int i,n,a[20], flag=0, pos,x;
	printf("enter the number of elements in array...");
	scanf("%d", &n);
	//reading array...
	printf("reading array...\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//searching the element...
	printf("Enter the element to search...");
	scanf("%d", &x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			pos=i+1;
			printf("\nElement %d found at position %d.\n",x,pos);
			flag++;
		}
		if(i==n)
			break;
	}

	if(flag==0)
		printf("\nElement not found!\n");
}
