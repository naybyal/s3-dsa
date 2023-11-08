#include<stdio.h>

struct student{
	int id;
	int phy;
	int chem;
	int math;
}s[20];

void main()
{
	int n,i;
	int phyTotal=0,chemTotal=0,mathTotal=0;
	int stuTotal[20];
	printf("Enter the number of students...");
	scanf("%d", &n);
	//Reading student data
	printf("Reading student data...\n");
	printf("------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Student ID :");
		scanf("%d", &s[i].id);
		printf("Their marks in Physics?..");
		scanf("%d", &s[i].phy);
		printf("Their marks in Chemistry?..");
		scanf("%d", &s[i].chem);
		printf("Thier marks in Mathematics?..");
		scanf("%d", &s[i].math);
		printf("\n");
	}
	printf("----Data Fetched Successfully!----\n");
	//Analyzing scores...
	for(i=0;i<n;i++)
	{
		phyTotal=phyTotal+s[i].phy;
		chemTotal=chemTotal+s[i].chem;
		mathTotal=mathTotal+s[i].math;
		stuTotal[i]= s[i].phy + s[i].chem + s[i].math;
	}
	//Displaying the scores..
	printf("=======================\n");
	printf("----Grade analysis!----\n");
	for(i=0;i<n;i++)
	{
		printf("Grades of Student %d\n", i+1);
		printf("\nID : %d\n",s[i].id);
		printf("Physics : %d/100\n", s[i].phy);
		printf("Chemistry : %d/100\n",s[i].chem);
		printf("Mathematics : %d/100\n",s[i].math);
		printf("\nTotal Score : %d/300\n",stuTotal[i]);
		printf("=========================\n");

	}
	int outta = n*100;
	printf("Subject-wise scores of the entire class...\n");
	printf("\nPhysics : %d/%d\n", phyTotal,outta);
	printf("Chemistry : %d/%d\n", chemTotal,outta);
	printf("Mathematics : %d/%d\n",mathTotal,outta);
	
	printf("\n-----COMPLETE!-----\n");
}
