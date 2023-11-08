#include<stdio.h>
int i,j,a[10][10], temp[10][10], m,n;
void upperTriangular(int mat[][10]) {
    if(m!=n)
        printf("\n(upperTriangular)Not a square matrix.\n");
    else {
        int flag = 0;
        for(i=1;i<m;i++) {
            for(j=0;j<i;j++) {
                if(a[i][j]!=0)
                    flag=1;
            }
        }
        if(flag==1)
            printf("\nNot an upper triangular matrix. \n");
        else
        {
            printf("\nIs an upper triangular matrix.\n");
        }
    }
}
void lowerTriangular(int mat[][10]) {
    if(m!=n)
        printf("\n(lowerTriangular)Not a square matrix.\n");
    else {
       int flag = 0;
        for(i=0;i<m;i++) {
            for(j=i+1;j<m;j++) {
                if(a[i][j]!=0)
                    flag=1;
            }
        }
        if(flag==1)
            printf("\nNot a lower triangular matrix. \n");
        else
        {
            printf("\nIs a lower triangular matrix.\n");
        } 
    }
}
void identityMatrix(int mat[][10]) {
    if(m!=n)
        printf("\n(identityMatrix)Not a square matrix.\n");
    else {
        int flag = 0;
        for(i=0;i<m;i++) {
            for(j=i+1;j<m;j++) {
                if(a[i][j]!=0)
                    flag=1;
            }
        }
        for(i=1;i<m;i++) {
            for(j=0;j<i;j++) {
                if(a[i][j]!=0)
                    flag=1;
            }
        }
        for(i=0;i<m;i++) {
            if(a[i][i]!=1)
                flag=1;
        }
        if(flag==1) 
            printf("\nNot an identity matrix.\n");
        else
        {
            printf("\nIs an Identity Matrix!\n");
        }
    }
}
void diagonalMatrix(int mat[][10]) {
    if(m!=n) {
        printf("\n(diagonalMatrix) Not a square matrix.\n");
    }
    else {
        int flag=0;
        for(i=0;i<m;i++) {
            for(j=i+1;j<m;j++) {
                if(a[i][j]!=0)
                    flag=1;
            }
        }
        for(i=1;i<m;i++) {
            for(j=0;j<i;j++) {
                if(a[i][j]!=0)
                    flag=1;
            }
        }
        if(flag==0)
            printf("\nIs a Diagonal Matrix!\n");
        else {
            printf("\nNot a diagonal matrix.\n");
        }
    }
}
void symmetricMatrix(int mat[][10]) {
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            temp[j][i] = a[i][j];
        }
    }
    int flag=0;
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            if(temp[i][j]!=a[i][j])
                flag=1;
        }
    }
    if(flag==1)
        printf("\nNot a symmetric matrix.\n");
    else {
        printf("\nIs a Symmetric Matrix!\n");
    }
}
void main() {
    
    printf("Enter the order of the matrix... ");
    scanf("%d%d",&m,&n);
    printf("Reading matrix.. \n");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++)
          scanf("%d", &a[i][j]);
    }
    printf("Displaying the matrix... \n");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    } 
    upperTriangular(a);
    lowerTriangular(a);
    identityMatrix(a);
    diagonalMatrix(a);
    symmetricMatrix(a);  
}