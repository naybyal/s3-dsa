#include<stdio.h>
#include<stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

struct node *root = NULL;
struct node *new;

struct node *newNode (int item) {
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void create (struct node *temp) {
	struct node *ptr, *prev = temp;
	ptr = (struct node*)malloc(sizeof(struct node*));
	printf("\nEnter data : ");
	scanf("%d", &ptr->key);

	ptr->left = NULL; ptr->right = NULL;
	
	if (temp == NULL) {
		root = ptr;
		return;
	}

	while (temp != NULL) {
		prev = temp;
		if(temp->key > ptr->key) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}

	if (prev->key > ptr->key) {
		prev->left = ptr;
	}
	else {
		prev->right = ptr;
	}
}


void inorder (struct node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d\t", root->key);
		inorder(root->right);
	}
}

struct node *insert (struct node *node, int key) {
	if (node==NULL)
		return newNode(key);
	if (key < node->key) 
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}

struct node *minValueNode (struct node *node,int key) {
	struct node *curr = node;
	while (curr!=NULL && curr->left != NULL)	
		curr = curr->left;
	return curr;
}

struct node *delete(struct node *node, int key) {
	if(node == NULL)
		return node;
	else if (key < node->key) 
		node->left = delete(node->left,key);
	else if (key > node->key)
		node->right = delete(node->right, key);
	else {
		if (node->left == NULL) {
			struct node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			struct node *temp = node->right;
			free(node);
			return temp;
		}
		struct node *temp = minValueNode(node->right,key);
		node->key = temp->key;
		node->right = delete(node->right, key);
	}
	return node;
}
void print2DUtil(struct node* root, int space) {
	int COUNT=10;
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->right, space);
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->key);
	print2DUtil(root->left, space);
}

void print2D(struct node* root) {
	print2DUtil(root, 0);
}
void main() {
	int x,y;
	do {
		create(root);
		printf("Wanna continue?! (1/0)");
		scanf("%d", &y);
	} while (y!=0);

	
	print2D(root);
	printf("\n\n\n");
	printf("================================");
	printf("\nInorder traversal : \n");
	inorder(root);
	printf("Enter the element to delete.. ");
	scanf("%d", &x);
	root = delete(root, x);
	printf("After deletion...\n");
	inorder(root);
	printf("\n");
	
}
