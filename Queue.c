/*QUEUE  USING  SINGLY  LINKED  LIST*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
void insert(Node **,Node **);
void display(Node **);
void delet(Node **);
void search(Node *);
void main()
{
	int choice,n;
	Node *front=NULL;
	Node *rear=NULL;
	printf("Implementation of QUEUE\n\n");
	while(1)
	{
		printf("Available operations\n1. Insertion of integer\n2. Deletion of integer\n3. Displaying the elements\n4. Search an element\n5. Exit\nEnter your choice here -> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\nInsertion of an integer\n");
					insert(&front,&rear);
					break;
			case 2 : printf("\nDeletion of the first element\n");
					delet(&front);
					break;
			case 3 : printf("\nDisplaying the elements of the queue\n");
					display(&front);
					break;
			case 4 : if(front == NULL) printf("\nQueue is empty\n\n");
					else search(front); break;
			case 5 : exit(0);
			default : printf("\nPlease enter a valid choice (1-4)\n\n");
		}
	}
}

void search(Node *front){
	int key, i=1;
	printf("Enter the integer to be searched : ");
	scanf("%d", &key);
	while(front != NULL){
		if(front->data == key){
			printf("%d found at position %d\n",key, i);
			return;
		}
		i+=1;
		front=front->next;
	}
	printf("%d is not present in the list\n",key);
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
	nw->next=NULL;
	if(tempr==NULL)
	{
		tempf=nw;
		tempr=nw;
	}
	else
	{
		tempr->next=nw;
		tempr=tempr->next;
	}
	*front=tempf;
	*rear=tempr;
	printf("The new element has been successfully added\n\n");
}
void delet(Node **front)
{
	Node *tempf=*front;
	if(tempf==NULL)
		printf("Queue is empty\n\n");
	else
	{
		Node *temp=*front;
		tempf=tempf->next;
		free(temp);
		printf("The first element has been successfully deleted\n\n");
		*front=tempf;
	}
}
void display(Node **front)
{
	Node *tempf=*front;
	if(tempf==NULL)
		printf("Queue is empty\n\n");
	else
	{
		Node *temp=*front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	printf("\n\n");
	}
}
