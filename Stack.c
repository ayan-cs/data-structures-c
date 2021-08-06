#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
void insert(struct queue **,int);
void delet(struct queue **);
void display(struct queue *);
void search(struct queue *);

void main()
{
	int choice,n;
	struct queue *top=NULL;
	printf("\nImplementation of Stack\n\n");
	while(1)
	{
		printf("Available operations\n1. Insertion\n2. Deletion\n3. Display\n4. Search\n5. Exit\nEnter your choice here-> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\nInsertion of integer\nEnter an integer\n");
				scanf("%d",&n);
				insert(&top,n);
				break;
			case 2 : printf("\nDeletion of integer\n");
				delet(&top);
				break;
			case 3 : printf("\nDisplaying the elements of the Stack\n");
				display(top);
				break;
			case 4 : if(top == NULL) printf("\nStack is empty\n");
					else search(top); break;
			case 5 : printf("\nThank you\n\n");
				exit(0);
			default : printf("\nPlease enter a valid choice (1-4)\n\n");
		}
	}
}

void search(struct queue *front){
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
	printf("%d is not present in Stack\n",key);
}

void insert(struct queue **temp,int n)
{
	struct queue *t=*temp,*nw;
	nw=(struct queue *)malloc(sizeof(struct queue));
	nw->data=n;
	nw->next=t;
	t=nw;
	printf("The new element has been successfully added\n\n");
	*temp=t;
}

void delet(struct queue **temp)
{
	if(*temp==NULL)
		printf("Stack is empty\n\n");
	else
	{
		struct queue *t=*temp,*s=*temp;
		t=t->next;
		*temp=t;
		free(s);
		printf("The last added element has been successfully deleted\n\n");
	}
}

void display(struct queue *temp)
{
	if(temp==NULL)
		printf("Stack is empty\n\n");
	else
	{
		struct queue *s=temp,*p=temp;
		int *num,n=0,i;
		while(s!=NULL)
		{
			n++;
			s=s->next;
		}
		num=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			*(num+i)=p->data;
			p=p->next;
		}
		for(i=n-1;i>=0;i--)
			printf("%d ",*(num+i));
		printf("\n\n");
		
	}
}
