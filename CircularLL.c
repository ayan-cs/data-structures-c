/*QUEUE  USING  SINGLY  LINKED  LIST*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
void insert(Node **);
void display(Node *);
void delet(Node **);
void search(Node *);
void main()
{
	int choice,n;
	Node *front=NULL;
	Node *rear=NULL;
	printf("Implementation of CIRCULAR LL\n");
	while(1)
	{
		printf("\nAvailable operations\n1. Insertion of integer\n2. Deletion of integer\n3. Displaying the elements\n4. Search\n5. Exit\nEnter your choice here -> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\nInsertion of an integer\n");
					insert(&front);
					break;
			case 2 : printf("\nDeletion of the first element\n");
					delet(&front);
					break;
			case 3 : printf("\nDisplaying the elements of the queue\n");
					display(front);
					break;
            case 4 : search(front); break;
			case 5 : exit(0);
			default : printf("\nPlease enter a valid choice (1-4)\n\n");
		}
	}
}


void insert(Node **front)
{
	Node *tempf=*front, *nw;
	int n;
	printf("Enter an integer\n");
	scanf("%d",&n);
	nw=(Node *)malloc(sizeof(Node));
	nw->data=n;
	nw->next=*front;
	if(tempf==NULL)
	{
		tempf=nw;
        nw->next = nw;
	}
	else
	{
		Node *head = (*front)->next;
        while(head->next != *front)
            head = head->next;
        head->next = nw;
	}
	*front=tempf;
	printf("The new element has been successfully added\n\n");
}

void delet(Node **front)
{
	if(*front==NULL){
		printf("LL is empty\n");
        return;
    }
    int data;
    printf("Enter the element to delete : ");
    scanf("%d",&data);
    Node *head=*front;
    if(*front == (*front)->next && (*front)->data == data){ // LL Contains only 1 element that matches key
        *front = NULL;
        free(head);
        printf("The Element has been successfully deleted\n\n");
        return;
    }
    if(head->data == data){ // Multiple elements but First element matches key
        while(head->next!=*front)
            head = head->next;
        *front = (*front)->next;
        head->next = *front;
        printf("The Element has been successfully deleted\n\n");
        return;
    }
    // LL has multiple elements and key is in between
    Node *prev = NULL;
    while(head->next != *front){
        if(head->data == data){
            prev->next = head->next;
            printf("The Element has been successfully deleted\n\n");
            return;
        }
        else{
            prev = head;
            head = head->next;
        }
    }
    if(head->data == data){ // LL has multiple items and key is last element
        prev->next = head->next;
        printf("The Element has been successfully deleted\n\n");
        return;
    }
    printf("Element not found\n");
}

void display(Node *front)
{
	if(front==NULL)
		printf("LL is empty\n\n");
	else
	{
        Node *f = front;
		while(f->next != front)
		{
			printf("%d ",f->data);
			f=f->next;
		}
        printf("%d\n\n", f->data);
	}
}

void search(Node *head){
    if (head == NULL){
        printf("LL is empty\n");
    }
    else {
        int srch, i=1, flag=0;
        Node *f = head;
        printf("Enter search key : ");
        scanf("%d",&srch);
        while(head->next != f){
            if(head->data == srch){
                printf("Element found at position %d\n",i);
                flag=1;
                break;
            }
            head = head->next;
            i+=1;
        }
        if(head->next == f){
            if(head->data == srch){
                printf("Element found at position %d\n",i);
                flag=1;
            }
        }
        if(flag==0)
            printf("Element not found\n");
    }
}