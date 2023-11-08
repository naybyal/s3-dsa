#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*ptr,*head,*temp,*curr,*prev;

int item;

void insertAtFront() {
    printf("Enter the item to be inserted... ");
    scanf("%d", &item);
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->data=item;
    temp->link=head;
    head=temp;
    printf("%d inserted at front. \n", head->data);
}
void insertAtEnd() {
    printf("Enter the item to be inserted... ");
    scanf("%d", &item);
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = item;
    temp->link = NULL;
    if(head==NULL) {
        head=temp;
    }
    else {
        ptr=head;
        while(ptr->link!=NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
        printf("%d inserted at the end. \n", temp->data);
    }
}
void insertSpecifically() {
    int key;
    if(head == NULL) 
        printf("SEARCH FAILED. LinkedList is empty!\n");
    else {
        printf("Enter the key... ");
        scanf("%d", &key);
        ptr =  head;
        while(ptr->link!=NULL && ptr->data!=key) {
            ptr = ptr->link;
        }
        if(ptr->data!=key) 
            printf("SEARCH FAILED! Key not found.\n");
        else {
            temp = (struct node*)malloc(sizeof(struct node*));
            printf("Key found! Now enter the item to insert.. ");
            scanf("%d", &item);
            temp->data = item;
            temp->link = ptr->link;
            ptr->link = temp;
            printf("%d inserted. \n", temp->data);
        }
    }
}

void deleteFromFront() {
    if(head==NULL) 
        printf("Cannot Delete! LinkedList is empty!\n");
    else {
        ptr = head;
        printf("%d deleted from the front. \n", ptr->data);
        head = ptr->link;
        free(ptr);
    }
}
void deleteFromEnd() {
    if(head==NULL) 
        printf("Cannot Delete! LinkedList is empty!\n");
    else if(head->link == NULL) {
        printf("%d deleted.\n",head->data);
        head=NULL;
        free(head);
    }
    else {
        curr = head->link;
        prev = head;
        while(curr->link!=NULL) {
            prev = curr;
            curr = curr->link;
        }
        prev->link = curr->link;
        free(curr);
    }
}
void deleteSpecifically() {
    if(head == NULL)
        printf("Cannot delete! LinkedList is empty!\n");
    else {
        int key;
        printf("Enter the key.... ");
        scanf("%d", &key);
        if(head->data!=key) {
            curr = head;
            prev = head;
            while(curr->link!=NULL && curr->data!=key) {
                prev=curr;
                curr=curr->link;
            }
            if(curr->data!=key) {
                printf("Key not found.\n");
            }
            else {
                printf("%d deleted.\n", curr->data);
                prev->link = curr->link;
                free(curr);
            }
        }
        else {
            temp = head;
            printf("%d deleted.\n", temp->data);
            head = head->link;
            free(temp);
        }
    }
}

void display() {
    if(head==NULL)
        printf("LinkedList is empty.\n");
    else {
        ptr = head;
        printf("The elements in the LinkedList are... \n");
        while(ptr->link!=NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("%d", ptr->data);
        printf("\n");
    }
}

void main() {
    int op1,op2;
    do {
        printf("Enter the choice.. 1) INSERT 2) DELETE 3) DISPLAY 4) EXIT  ");
        scanf("%d", &op1);
        switch(op1) {
            case 1:
                printf("Insert to where? 1) FRONT 2) END 3) SPECIFIC LOCATION  ");
                scanf("%d", &op2);
                switch(op2) {
                    case 1:
                        insertAtFront();
                        break;
                    case 2:
                        insertAtEnd();
                        break;
                    case 3:
                        insertSpecifically();
                        break;
                    default:
                        printf("Wrong choice! Try again.\n");
                        break;
                }
                break;
            case 2:
                printf("Delete from where? 1) FRONT 2) END 3) SPECIFIC LOCATION  ");
                scanf("%d", &op2);
                switch(op2) {
                    case 1:
                        deleteFromFront();
                        break;
                    case 2:
                        deleteFromEnd();
                        break;
                    case 3:
                        deleteSpecifically();
                        break;
                    default:
                        printf("Wrong choice! Try again.\n");
                        break;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                break;
        }
    }while(op1!=4);
}
