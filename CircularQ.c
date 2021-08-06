/*CIRCULAR QUEUE*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
void insert(Node **,Node **);
void display(Node *, Node *);
void delet(Node **, Node **);
void search(Node *, Node *);
void main()
{
	int choice,n;
	Node *front=NULL;
	Node *rear=NULL;
	printf("Implementation of CIRCULAR QUEUE\n\n");
	while(1)
	{
		printf("\nAvailable operations\n1. Insertion of integer\n2. Deletion of integer\n3. Displaying the elements\n4. Search\n5. Exit\nEnter your choice here -> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\nInsertion of an integer\n");
					insert(&front,&rear);
					break;
			case 2 : printf("\nDeletion of the first element\n");
					delet(&front, &rear);
					break;
			case 3 : printf("\nDisplaying the elements of the queue\n");
					display(front, rear);
					break;
            case 4 : search(front, rear); break;
			case 5 : exit(0);
			default : printf("\nPlease enter a valid choice (1-4)\n\n");
		}
	}
}


void insert(Node **front,Node **rear)
{
	Node *tempf=*front,*tempr=*rear;
	Node *nw;
	int n;
	printf("Enter an integer\n");
	scanf("%d",&n);
	nw=(Node *)malloc(sizeof(Node));
	nw->data=n;
	nw->next=*front;
	if(tempr==NULL)
	{
		tempf=nw;
		tempr=nw;
        nw->next = nw;
	}
	else
	{
		tempr->next=nw;
		tempr=tempr->next;
	}
	*front=tempf;
	*rear=tempr;
	printf("The new element has been successfully added\n");
}

void delet(Node **front, Node **rear)
{
	if(*front==NULL)
		printf("Queue is empty\n");
	else
	{
        Node *temp=*front;
        if(*front == *rear){
            *front = NULL;
            *rear = NULL;
            free(temp);
            printf("The first element has been successfully deleted\n");
            return;
        }
		*front=(*front)->next;
        (*rear)->next = *front;
		free(temp);
		printf("The first element has been successfully deleted\n");
	}
}

void display(Node *front, Node *rear)
{
	if(front==NULL)
		printf("Queue is empty\n");
	else
	{
		while(front!=rear)
		{
			printf("%d ",front->data);
			front=front->next;
		}
        printf("%d\n\n", front->data);
	}
}

void search(Node *head, Node *rear){
    if (head == NULL){
        printf("Queue is empty\n");
    }
    else {
        int srch, i=1, flag=0;
        printf("Enter search key : ");
        scanf("%d",&srch);
        while(head != rear){
            if(head->data == srch){
                printf("Element found at position %d\n",i);
                flag=1;
                break;
            }
            head = head->next;
            i+=1;
        }
        if(head == rear){
            if(head->data == srch){
                printf("Element found at position %d\n",i);
                flag=1;
            }
        }
        if(flag==0)
            printf("Element not found\n");
    }
}