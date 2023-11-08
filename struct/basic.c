#include<stdio.h>
#include<string.h>
struct student{
	char name[100];
	int roll;
	int age;
	char course[5];
}s[10],temp[20];

void main()
{
	int i,j,n;
        printf("Enter the number of students...");
	scanf("%d",&n);
	printf("\n------------------------------");
	for(i=0;i<n;i++)
	{
		printf("\nReading details of Student %d\n", i+1);
		printf("Name?..");
		scanf("%s", s[i].name);
		printf("Roll No?..");
		scanf("%d", &s[i].roll);
		printf("Age?..");
		scanf("%d", &s[i].age);
		printf("Course?..");
		scanf("%s", s[i].course);
	}
	//Sorting by ascending name order
	
		for(i=0;i<n-1;i++)
		{
			
			for(j=i+1;j<n;j++)
			{
				if(strcmp(s[i].name,s[j].name)>0)
				{	
					temp[0]=s[i];
					s[i]=s[j];
					s[j]=temp[0];
				}
			}
			
		}
	
	
	printf("-----Data fetched successfully!-------\n");
	printf("The sorted list is...\n");
	for(i=0;i<n;i++)
	{
		printf("=================================\n");
		printf("Student %d\n", i+1);
		printf("Name : %s\n", s[i].name);
		printf("Roll num : %d\n", s[i].roll);
		printf("Age : %d\n", s[i].age);
		printf("Course : %s", s[i].course);
		printf("\n");
	}

}
