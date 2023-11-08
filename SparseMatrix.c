#include<stdio.h>
#include<stdlib.h>
void main(){
   int a[10][10],m,n,i,j;
   printf("Enter number of rows and coloumns : ");
   scanf("%d%d",&m,&n);
   printf("Enter matrix elements : ");
   for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
   printf("Matrix : \n");
   for(i=0;i<m;i++)
      {for(j=0;j<n;j++)
         printf("%d ",a[i][j]);
         printf("\n");
        }
    int k=1,s[10][10];
    s[0][0] = m;
    s[0][1] =n;
    for(i=0;i<m;i++)
      {for(j=0;j<n;j++)
         {
           if(a[i][j]!=0)
           {
             s[k][0] = i;
             s[k][1] = j;
             s[k][2] = a[i][j];
             k++;
            }}}
    s[0][2] = k-1;
    printf("Row Major Form : \n");
    for(i=0;i<=s[0][2];i++)
     { for(j=0;j<3;j++)
        printf("%d\t",s[i][j]);  
        printf("\n");        
        }}
