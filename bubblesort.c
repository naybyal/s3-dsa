#include<stdio.h>
void main()
{
	int n,i,j,a[20],temp;
	printf("enter the number of elements...");
	scanf("%d", &n);
	printf("reading array...");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//sorting...
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{	
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

			}
		}
	}
	//printing the array
	printf("The sorted array is...\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}
