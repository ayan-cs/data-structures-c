#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
    int priority;
	struct node *next;
};
typedef struct node Node;

int isPriorityExist(Node *q, int pr){
    while(q != NULL){
        if(q->priority == pr)
            return 1;
        else
            q = q->next;
    }
    return 0;
}

int findMaxPriority(Node *q){
    int max=q->priority;
    q=q->next;
    while(q != NULL){
        if(max < q->priority){
            max = q->priority;
        }
        q=q->next;
    }
    return max;
}

void insert(Node **q){
    int pr;
    Node *nn = (Node *)malloc(sizeof(Node));
    printf("Enter data : "); scanf("%d", &pr); nn->data = pr;
    printf("Enter Priority value : "); scanf("%d", &pr);
    nn->next = NULL;
    if(*q == NULL){
        nn->priority = pr;
        *q = nn;
        printf("Element added successfully\n");
        return;
    }
    if(isPriorityExist(*q, pr)){
        printf("The prioroty value exists. Please retry.\n");
        return;
    }
    nn->priority = pr;
    Node *temp = *q;
    while(temp->next != NULL) temp = temp->next;
    temp->next = nn;
    printf("Element added successfully\n");
}

void display(Node *q){
    if(q==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Displaying Queue\n");
    while(q != NULL){
        printf("Element : %d\tPriority : %d\n", q->data, q->priority);
        q=q->next;
    }
}

void delet(Node **q){
    if(*q == NULL) {
        printf("Queue is empty\n");
        return;
    }
    if((*q)->next == NULL){
        printf("Element %d with Priority %d deleted successfully\n",(*q)->data, (*q)->priority);
        *q=NULL;
        return;
    }
    int max = findMaxPriority(*q);
    Node *temp = *q, *prev = NULL;
    while(temp->priority != max){
        prev = temp;
        temp = temp->next;
    }
    if(temp == *q) *q = temp->next;
    else prev->next = temp->next;
    printf("Element %d with Priority %d deleted successfully\n",temp->data, temp->priority);
    free(temp);
}

void main()
{
	int choice;
	Node *front=NULL;
	printf("Implementation of PRIORITY QUEUE\n\n");
	while(1)
	{
		printf("\nAvailable operations\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice here -> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Insertion of an integer\n");
					insert(&front);
					break;
			case 2 : printf("Deletion of the Highest Priority element\n");
					delet(&front);
					break;
			case 3 : display(front);
					break;
			case 4 : exit(0);
			default : printf("Please enter a valid choice (1-4)\n\n");
		}
	}
}