#include<stdio.h>
void main()
{
	int i,j,n,a[20],temp;
	printf("\nArray size?!...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
	{
		printf("arr[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("The array is...\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\nThe sorted array is...\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n---COMPLETE!---\n");
}
