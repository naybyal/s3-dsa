#include<stdio.h>
void delete(int arr[], int size)
{
	int x,flag=0,pos,j;
	printf("\nEnter the element to delete...");
	scanf("%d", &x);
	for(j=0;j<size;j++)
	{
		if(arr[j]==x)
		{
			flag = 1;
			pos=j+1;
			break;
		}
	}
	if(flag==1)
	{
		while(pos!=size)
		{
			arr[pos-1]=arr[pos];
			pos++;
		}
	}
}
void main()
{
	int n,i, a[20];
	printf("Reading array size...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("The array is...\n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	delete(a,n);
	printf("\nThe manipulated array is...\n");
	for(i=0;i<n-1;i++)
		printf("%d\t", a[i]);
	printf("\n");
}
