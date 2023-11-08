/*Write a C program to count the number of palindromes in a collection of words stored as linked list.*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>

int i,n,pal=0;

struct node {
    char data[20];
    struct node *link;    
}*root,*ptr,*new;

char temp[20];

void insert(char name[20]) {
    root = (struct node*)malloc(sizeof(struct node*));
    new = (struct node*)malloc(sizeof(struct node*));
    int len;
    len = strlen(name);
    for(i=0;i<len;i++) {
        new->data[i]=name[i];
    }
    if(root == NULL) {
        root=new;
    }
    else {
        ptr=root;
        while(ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = new;
        free(ptr);
    }
}

void readNames() {
    char a[20];
    printf("Enter the number of names.... ");
    scanf("%d", &n);
    int i;
    for(i=0;i<n;i++) {
        scanf("%s", a);
        insert(a);
    }
}

void checkPalindrome() {
    int res,len=0;
    char rev = "";
    ptr = root;
    while(ptr!=NULL) {
        len=strlen(ptr->data);
        for(i=len-1;i>0;i--) {
            rev+=ptr->data[i];
        }
        res = strcmp(temp,ptr->data);
        if(res==0)
            pal++;
        ptr = ptr->link;
        rev = "";
        len = 0;
    }
}

void main() {
    readNames();
    checkPalindrome();
    printf("\nThe total palindromes in the LINKEDLIST = %d\n", pal);
}
