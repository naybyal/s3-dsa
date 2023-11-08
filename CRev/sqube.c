#include<stdio.h>
void main()
{
	int n,i, a[20];
	printf("Enter array size...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
			printf("Square of %d is %d.\n",a[i],a[i]*a[i]);
		else
			printf("Cube of %d is %d.\n",a[i],a[i]*a[i]*a[i]);
	}
}
