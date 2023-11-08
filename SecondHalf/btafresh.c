#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};

struct node *create() {
    int x;
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &x);
    if(x==-1) {
        return NULL;
    }
    new->data = x;
    printf("Enter left child of %d..  ", x);
    new->left = create();
    printf("Enter the right child of %d.. ", x);
    new->right = create();
    return new;
}
void preorder(struct node *root) {
    if(root!=NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}
void main() {

    struct node *root;
    root=NULL;
    root = create();
    printf("Preorder  : ");
    preorder(root);
    printf("\n");
    printf("Inorder   : ");
    inorder(root);
    printf("\n");
    printf("Postorder : ");
    postorder(root);
    printf("\n");
}