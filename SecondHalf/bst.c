#include <stdio.h>
#include <stdlib.h>
struct node{
  	int key;
  	struct node *left, *right;
};
struct node *root=NULL;
struct node *new;
struct node *newNode(int item){
  	struct node *temp = (struct node *)malloc(sizeof(struct node));
  	temp->key = item;
  	temp->left = temp->right = NULL;
  	return temp;
}
void CreateTree(struct node *temp){
	    int mode,data;
	    new=malloc(sizeof(struct node));
	    new->left=new->right=NULL;
	    if(root==NULL) {
			printf("Enter Root Data : ");
			scanf("%d",&data);
			new->key=data;
			root=new;
			CreateTree(root);
	    }
	    else {
		    printf("Enter the Data : ");
		    scanf("%d",&data);
		    new->key=data;
		    printf("Left Child : (1/0) ");
		    scanf("%d",&mode);
		    if(mode==1) {
				temp->left=new;
				temp=temp->left;
				CreateTree(temp);
		    }
		    
		    else if (mode==2)
		    	return;
		    	
		    printf("Right Child : (1/0) ");
		    scanf("%d",&mode);
		    if(mode==1) {
			temp->right=new;
			temp=temp->right;
			CreateTree(temp);
		    }
		    
		    else if (mode==2)
		    	return;
	}
}
void inorder(struct node *root){
  	if (root != NULL){
  	  	inorder(root->left);
  	  	printf("%d\t", root->key);
  	  	inorder(root->right);
  	}
}
struct node *insert(struct node *node, int key){
  	if (node == NULL)
  		return newNode(key);
  	if (key < node->key)
    		node->left = insert(node->left, key);
  	else
    		node->right = insert(node->right, key);
  	return node;
}
struct node *minValueNode(struct node *node){
  	struct node *current = node;
  	while (current && current->left != NULL)
    		current = current->left;
  	return current;
}
struct node *deleteNode(struct node *root, int key){
  	if (root == NULL)
  		return root;
  	if (key < root->key)
    		root->left = deleteNode(root->left, key);
  	else if (key > root->key)
    		root->right = deleteNode(root->right, key);
  	else {
    		if (root->left == NULL){
      			struct node *temp = root->right;
      			free(root);
      			return temp;
    		} 
    		else if (root->right == NULL){
      			struct node *temp = root->left;
      			free(root);
      			return temp;
    		}
    		struct node *temp = minValueNode(root->right);
    		root->key = temp->key;
    		root->right = deleteNode(root->right, temp->key);
  	}
  	return root;
}
void main(){
  	int del;
  	CreateTree(root);
  	printf("Inorder traversal: ");
  	inorder(root);
  	printf("\nEnter the element to be deleted:");
  	scanf("%d",&del);
  	printf("After deleting %d\n",del);
 	root = deleteNode(root, del);
 	printf("Inorder traversal: ");
  	inorder(root);
  	printf("\n");
}
