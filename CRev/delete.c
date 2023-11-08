#include<stdio.h>
void delete(int arr[], int size)
{
	int j,pos;
	printf("\nEnter the index to delete...");
	scanf("%d", &pos);
	if(pos<size)
	{
		while(pos!=size)
		{
			arr[pos]=arr[pos+1];
			pos++;
		}
	}
	else
		printf("\nElement DELETION not possible!\n");
}
void main()
{
	int n,i,a[20];
	printf("Enter array size...");
	scanf("%d", &n);
	printf("Reading array...\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("The array is...");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	delete(a,n);
	//Displaying the manipulated matrix...
	for(i=0;i<n-1;i++)
		printf("%d\t", a[i]);
	printf("\n");
}
