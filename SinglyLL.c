#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
void append(Node **, int);
void display(Node *);
int count(Node *);
void delet(Node **,int);
void search(Node *);

void main()
{
	int n,choice,postn,c;
	Node *p=NULL;
	while(1)
	{
		printf("\n\nSelect your choice from the list\n1. Insert\n2. Delete a node\n3. Display the list\n4. Count the number of nodes\n5. Search\n6. Exit\nSelect your choice here -> ");
		scanf("%d",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 1 : printf("Insert\nEnter an integer\n");
					scanf("%d",&n);
					append(&p,n);
					printf("The new node has been successfully added\n");
					break;
			case 2 : printf("Delete a node\n");
					if(p==NULL)
					{
						printf("List is empty\n");
					}
					else
					{
						printf("Enter the element that you want to delete\n");
						scanf("%d",&n);
						delet(&p,n);
					}
					break;
			case 3 : printf("Displaying the elements of the list\n");
					display(p);
					break;
			case 4 : printf("Counting the number of Nodes\n");
					c=count(p);
					printf("There are %d nodes in the list\n",c);
					break;
			case 5 : if(p == NULL) printf("\nQueue is empty\n");
					else search(p); break;
			case 6 : exit(0);
			default : printf("Please enter a valid choice (1-11)\n\n");
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

void append(Node **q, int num)
{
	Node *temp,*nw;
	if(*q==NULL)
	{
		nw=(Node *)malloc(sizeof(Node));
		nw->data=num;
		nw->next=NULL;
		*q=nw;
	}
	else
	{
		temp=*q;
		nw=(Node *)malloc(sizeof(Node));
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nw;
		nw->data=num;
		nw->next=NULL;
	}
	//return q;
}
void display(Node *q)
{
	if(q==NULL)
	{
		printf("List is empty\n");
		return;
	}
	else
	{
		Node *temp;
		temp=q;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

int count(Node *q)
{
	int i=0;
	Node *temp;
	temp=q;
	while(temp!=NULL)
	{
		i=i+1;
		temp=temp->next;
	}
	return i;
}

void delet(Node **q,int num)
{
		Node *temp, *old;
		int flag=0;
		temp=*q;
		old=NULL;
		while(temp!=NULL)
		{
			if(temp->data==num)
			{
				flag=1;
				if(temp==*q)
				{
					*q=temp->next;
				}
				else
				{
					old->next=temp->next;
					free(temp);
				}
				printf("The element you entered has been successfully deleted\n");
				return;
			}
			else
			{
				old=temp;
				temp=temp->next;
			}
		}
		if(flag==0)
		printf("Element not found in the list\n");
}