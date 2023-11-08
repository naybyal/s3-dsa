#include<stdio.h>
void sort(int arr[],int size)
{
	int p,j,temp;
	for(p=0;p<size;p++)
	{
		for(j=0;j<size-p-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}	
		}
	}
}
void main()
{
	int i,n,a[20],mid,low,high;
	printf("Enter array size...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	sort(a,n);

	//Displaying the sorted array
	printf("\n------------------------\n");
	printf("The sorted array is...\n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	
	//Binary search
	int x;
	printf("\nEnter the element to search...");
	scanf("%d", &x);
	low=0;
	high=n-1;
	mid = (low+high)/2;

	while(low <= high)
	{
		if(a[mid] < x)
		{
			low = mid+1;
			mid = (low+high)/2;
		}
		else if(a[mid] == x)
		{
			printf("\n%d found at position %d\n", x, mid+1);
			break;
		}
		else 
		{
			high = mid-1;
			mid = (low+high)/2;
		}
	}
	if(low>high)
		printf("\nElement not found!\n");	
}	
