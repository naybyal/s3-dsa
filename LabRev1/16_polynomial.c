//Menu driven program for polynomial representation, addition, multiplication and subtraction.
#include<stdio.h>

struct poly {
    int exp;
    int coeff;
}p1[10],p2[10],p3[10];

//t - num(terms)

int readPoly(struct poly p[10]) {
    int i,t;
    printf("Enter the number of term... ");
    scanf("%d", &t);
    for(i=0;i<t;i++) {
        printf("Term %d (coeff,expo)\n", i+1);
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }
    return t;
}

void displayPoly(struct poly p[10], int t) {
    int j;
    printf("\n");
    for(j=0;j<t-1;j++) {
        printf("%d(x^%d) + ", p[j].coeff,p[j].exp);
    }
    printf("%d(x^%d)", p[t-1].coeff, p[t-1].exp);
}

//Addition
int addPoly(struct poly p1[10], int t1, struct poly p2[10], int t2) {
    //initialize i,j,k with 0
    int i=0,j=0,k=0;
    while(i<t1 && j<t2) {
        if(p1[i].exp == p2[j].exp) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++; j++; k++;
        }
        
        else if (p1[i].exp > p2[j].exp) {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++; k++;
        }
        else {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            i++; k++;
        }
    }
    while(i<t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++; k++;
    }
    while(j<t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++; k++;
    }
    int t = k;
    return t;
}

void main() {
    int t1,t2,t3;
    t1=readPoly(p1);
    printf("\n");
    displayPoly(p1,t1);
    printf("\n");
    t2=readPoly(p2);
    printf("\n");
    displayPoly(p2,t2);
    printf("\n");
    t3=addPoly(p1,t1,p2,t2);
    printf("The result is...\n");
    displayPoly(p3,t3);
    printf("\n");
}