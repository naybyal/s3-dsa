#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node *root; 

struct node *create() {
	struct node *new; int x;
	new = (struct node*)malloc(sizeof(struct node*));
	printf("Enter data : ");
	scanf("%d", &x);
	if (x==-1)
		return 0;
	new->data = x;
	printf("Enter the left child of %d", x);
	new->left = create();
	printf("Enter the right child of %d", x);
	new->right = create();
	return new;	
}

void inorder(struct node *root) {
	if (root!=NULL) {
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root) {
	if (root!=NULL) {
		printf("%d\t",root->data);
		preorder(root->left);	
		preorder(root->right);
	}
}
void postorder(struct node *root) {
	if (root!=NULL) {
		postorder(root->left);	
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
void drawTree(struct node* root, int space) {
	int i,count=10;
	if (root==NULL)
		return;
	space += count;
	drawTree(root->right, space);
	printf("\n");
	for(i=count;i<space;i++)
		printf(" ");
	printf("%d\n", root->data);
	drawTree(root->left, space);
}

void drawIt(struct node *root) {
	drawTree(root,0);
}
void main() {
	root = 0;
	root = create();
	printf("\nInorder.. \n");
	inorder(root);
	printf("\nPreorder.. \n");
	preorder(root);
	printf("\nPostorder..\n");
	postorder(root);
	printf("\n\nTREE:\n");
	drawIt(root);
}
