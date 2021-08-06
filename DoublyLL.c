// A Program by AyanG WAP-7

#include<stdio.h>
#include<stdlib.h>
struct dnode
{
	struct dnode *prev;
	int data;
	struct dnode *next;
};
typedef struct dnode Node;
Node *append(Node *, int);
void display(Node *);
int count(Node *);
void delet(Node **,int);
void search(Node *, int);

void main()
{
	int n,choice,key,c;
	Node *p=NULL;
	while(1)
	{
		printf("\n\nSelect your choice from the list\n1. Append the list\n2. Delete a node\n3. Display the list\n4. Count the number of nodes\n5. Search a value\n6. Exit\n");
		printf("Select your choice here -> ");
		scanf("%d",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 1 : printf("Append the list\nEnter an integer\n");
					scanf("%d",&n);
					p=append(p,n);
					break;
			case 2 : printf("Delete a node\n");
					if(p==NULL)
						printf("List is empty\n");
					else
					{
						printf("Enter the element that you want to delete\n");
						scanf("%d",&n);
						delet(&p,n);
					}
					break;
			case 3 : printf("Display of the list\n");
					display(p);
					break;
			case 4 : printf("Counts the number of Nodes\n");
					c=count(p);
					printf("There are %d nodes in the list\n",c);
					break;
			case 5 :if(p==NULL) printf("LL is empty\n"); 
					else {
						printf("Enter the integer to be searched : ");
						scanf("%d", &key);
						search(p, key);
					} break;
			case 6 : exit(0);
			default : printf("Please enter a valid choice (1-11)\n\n");
		}
	}
}

void search(Node *p, int key){
	int i=1;
	while(p != NULL){
		if(p->data == key){
			printf("%d is present at position %d\n",key,i);
			return;
		}
		i++;
		p=p->next;
	}
	printf("%d is not present in list\n",key);
}

Node *append(Node *q, int num)
{
	if(q==NULL)
	{
		Node *nw;
		nw=(Node *)malloc(sizeof(Node));
		nw->prev=NULL;
		nw->data=num;
		nw->next=NULL;
		q=nw;
	}
	else
	{
		Node *temp,*nw;
		temp=q;
		nw=(Node *)malloc(sizeof(Node));
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nw;
		nw->prev=temp;
		nw->data=num;
		nw->next=NULL;
	}
	return q;
}
void display(Node *q)
{
	if(q==NULL)
		printf("List is empty\n");
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
					if(*q != NULL) (*q)->prev=NULL;
					return;
				}
				else
				{
					old->next=temp->next;
					if((temp->next)!=NULL) temp->next->prev=old;
					free(temp);
					return;
				}
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