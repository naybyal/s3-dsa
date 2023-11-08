#include<stdio.h>
void insert(int arr[], int size)
{
	int x,pos,j;
	printf("Enter the index of insertion...");
	scanf("%d", &pos);
	//Shifting elements after pos to the right.
	if(pos<size)
	{
		int count = pos-1;
		int end = size-1;
		while(end!=count)
		{
			arr[end+1]=0;
			arr[end+1]=arr[end];
			end--;
		}
		//Inserting the element
		printf("Enter the element to insert...");
		scanf("%d", &x);
		arr[pos]=x;
		//Displaying the manipulated array...
		printf("\n The new array is...\n");
		for(j=0;j<size+1;j++)
		{
			printf("%d\t", arr[j]);
		}
	}
	else
		printf("\nINSERTION is not possible!\n");
}
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
	printf("The array is...\n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	insert(a,n);

}
