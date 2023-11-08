#include<stdio.h>
void sort(int arr1[], int size)
{
	int temp,p,q;
	for(p=0;p<size;p++)
	{
		for(q=0;q<size-p-1;q++)
		{
			if(arr1[q]>arr1[q+1])
			{
				temp=arr1[q];
				arr1[q]=arr1[q+1];
				arr1[q+1]=temp;
			}
		}
	}
}
int search(int arr[], int start, int end, int el)
{
	int mid;
	if(end>=start)
	{
		mid = (start+end)/2;
		if(arr[mid] == el)
		{
			return mid+1;
		}
		else if(arr[mid]<el)
		{	
			return search(arr,mid+1,end,el);
		}
		else
		{
			return search(arr,start,mid-1,el);
		}
	}
	else
		return 0;
}
void main()
{
	int n,i,a[20],x,psn;
	printf("Reading array size...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	sort(a,n);
	printf("\nThe array has been read and sorted...\n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	printf("\nEnter the element to search...");
	scanf("%d", &x);
	psn=search(a,0,n-1,x)-1;
	if(psn != -1)
		printf("\nElement %d found at position %d\n", x, psn);
	else
		printf("\nElement not found.\n");
}

















