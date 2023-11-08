#include <stdio.h>
int m,n,p,q;
int s1[10][10], s2[10][10],t1[10][10],t2[10][10],sum[10][10];

void sparse(int ar[10][10], int r, int c,int out[10][10]) {
	int i,j,k=1;
	out[0][0]=r;out[0][1]=c;
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			if(ar[i][j]!=0) {
				out[k][0]=i;
				out[k][1]=j;
				out[k][2]=ar[i][j];
				k++;
			}
		}
	}
	out[0][2] =  k-1;
	for(i=0;i<=out[0][2];i++) {
		for(j=0;j<3;j++) {
			printf("%d\t", out[i][j]);
		}
		printf("\n");
	}

}

void transpose(int in[10][10],int out[10][10]) {
	out[0][0] = in[0][1];
	out[0][1] = in[0][0];
	out[0][2] = in[0][2];
	int i,j;
	int z = 1, m = in[0][1], n = in[0][2];
	for(i=0;i<m;i++) {
		for(j=1;j<=n;j++) {
			if(in[j][1]==i) {
				out[z][0]=in[j][1];
				out[z][1]=in[j][0];
				out[z][2]=in[j][2];
				z++;
			}
		}
	}
	printf("The transpose of the given matrix is \n");
	for(i=0;i<=out[0][2];i++) {
		for(j=0;j<3;j++) {
			printf("%d\t", out[i][j]);
		}
		printf("\n");
	}
}
void add(int a[10][10], int b[10][10], int c[10][10]) {
	int i,j,k;
	int r1 = a[0][0], c1 = a[0][1], r2 = b[0][0], c2 = b[0][1];
	if(r1!=r2 && c1!=c2) 
		printf("\nAddition IMPOSSIBLE!\n");
	else {
		c[0][0] = a[0][0];
		c[0][1] = a[0][1];
		m=1,n=1,k=1;
		for(i=0;i<r1;i++) {
			for(j=0;j<c1;j++) {
				if(a[m][0]==i && a[m][1]==j && b[n][0]==i && b[n][1]==j) {
					c[k][0] = a[m][0];
					c[k][1] = a[m][1];
					c[k][2] = a[m][2]+b[n][2];
					m++;
					n++;
					k++;
				}
				else if (a[m][0]==i && a[m][1]==j) {
					c[k][0] = a[m][0];
					c[k][1] = a[m][1];
					c[k][2] = a[m][2];
					m++;
					k++;
				}
				else if(b[n][0]==i && b[n][1]==j) {
					c[k][0] = b[n][0];
					c[k][1] = b[n][1];
					c[k][2] = b[n][2];
					n++;
					k++;
				}
			}
		}
		c[0][2] = k-1;
		printf("\n---THE SUM TUPLE IS ... ---\n");
		for(i=0;i<k;i++) {
			for(j=0;j<3;j++) {
				printf("%d\t", c[i][j]);
			}
			printf("\n");
		}
	}

}
void main() {
	int i,j,opt,op;
	int a[10][10],b[10][10];
	printf("Enter the order of 1st matrix...");
	scanf("%d%d", &m, &n);
	printf("Enter the order of 2nd matrix...");
	scanf("%d%d", &p,&q);
	//Read the matrices
	printf("Reading 1st matrix..\n");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Reading the 2nd matrix...\n");
	for(i=0;i<p;i++) {
		for(j=0;j<q;j++) {
			scanf("%d", &b[i][j]);
		}
	}
	printf("Sparse matrix of matrix 1 is \n");
	sparse(a,m,n,s1);
	printf("Sparse matrix of matrix 2 is \n");
	sparse(b,p,q,s2);
	do{
		printf("Enter option... 1) Transpose 2) Addition 3) EXIT  \n");
		scanf("%d", &opt);
		switch(opt) {
			case 1:
				printf("Choose the matrix to determine the transpose... ");
				scanf("%d", &op);
				switch(op) {
					case 1:
						transpose(s1,t1);
						break;
					case 2:
						transpose(s2,t2);
						break;
					default:
						printf("\nINVALID CHOICE!\n");
						break;
				}
				break;
				
			case 2:
				add(s1,s2,sum);
				break;
			case 3:
				break;
			default:
				printf("Not the right choice!");
				break;
		}
	}while(opt!=3);
}
