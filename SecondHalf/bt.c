#include <stdio.h>
#include <stdlib.h>

int data;
struct node {
    int data;
    struct node *left,*right;
};

struct node *root=NULL;
struct node *new;

void createTree(struct node *temp)
{
	    int mode;
	    new=malloc(sizeof(struct node));
	    new->left=new->right=NULL;
	    if(root==NULL) {
			printf("Enter Root Data : ");
			scanf("%d",&data);
			new->data=data;
			root=new;
			createTree(root);
	    }
	    else {
		    printf("Enter The Data : ");
		    scanf("%d",&data);
		    new->data=data;
		    printf("Left Child : (1/0) ");
		    scanf("%d",&mode);
		    if(mode==1) {
				temp->left=new;
				temp=temp->left;
				createTree(root);
		}
		    
		else if (mode==2)
		    return;
		    	
		printf("Right Child : (1/0) ");
		scanf("%d",&mode);
		if(mode==1) {
			temp->right=new;
			temp=temp->right;
			createTree(root);
		}
		    
		else if (mode==2)
		    	return;
	}
}

void in(struct node *x) {
	if(x!=NULL) {
	    in(x->left);
	    printf("%d\t",x->data);
	    in(x->right);
	}
}
void post(struct node *x) {
	if(x!=NULL) {
	    post(x->left);
	    post(x->right);
	    printf("%d\t",x->data);
	}
}
void pre(struct node *x) {
	if(x!=NULL) {
	    printf("%d\t",x->data);
	    pre(x->left);
	    pre(x->right);
	}
}

void main()
{
    createTree(root);
    printf("Inorder : ");
    in(root);
    printf("\n");
    printf("Preordr : ");
    pre(root);
    printf("\n");
    printf("Pstordr : ");
    post(root);
    printf("\n");
}