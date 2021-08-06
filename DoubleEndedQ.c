// DOUBLE ENDED QUEUE

#include<stdio.h>
#include<stdio.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

void front_append(Node **front, Node **rear){
    int data;
    printf("Enter the element you want to insert : ");
    scanf("%d",&data);
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->next = *front;
    nn->data = data;
    *front = nn;
    if(*rear == NULL)
        *rear = *front;
    printf("%d has been added successfully at the Front End\n", data);
}

void rear_append(Node **front, Node **rear){
    int data;
    printf("Enter the element you want to insert : ");
    scanf("%d",&data);
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->next = NULL;
    nn->data = data;
    if(*rear == NULL){
        *rear = nn;
        *front = *rear;
    }
    else{
        (*rear)->next = nn;
        *rear = nn;
    }
    printf("%d has been added successfully at the Rear End\n", data);
}

void display(Node *p){
    if(p == NULL){
        printf("Queue is empty\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void front_delete(Node **front, Node **rear){
    Node *temp = *front;
    if (*front == NULL){
        printf("Queue is empty\n");
        return;
    }
    if (*front == *rear){
        *front = NULL;
        *rear = NULL;
        printf("Element successfully deleted from Front End\n");
        free(temp);
        return;
    }
    *front = (*front)->next;
    printf("Element successfully deleted from Front End\n");
    free(temp);
}

void rear_delete(Node **front, Node **rear){
    Node *temp = *front;
    if(*rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    if(*front == *rear){
        *front = NULL;
        *rear = NULL;
        printf("Element successfully deleted from Rear End\n");
        free(temp);
        return;
    }
    while(temp->next != *rear)
        temp = temp->next;
    temp->next = NULL;
    *rear = temp;
    printf("Element successfully deleted from Rear End\n");
}

void search(Node *front){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    int srch, i=1, flag=0;
    printf("Enter the element you want to search : ");
    scanf("%d", &srch);
    while(front != NULL){
        if (front->data == srch){
            printf("Element is present at position %d\n",i);
            flag=1;
            break;
        }
        i+=1;
        front = front->next;
    }
    if(flag==0)
        printf("Element not found in the Queue\n");
}

void main(){
    int ch;
    Node *front = NULL, *rear = NULL;
    while(1){
        printf("\nAvailable Operations :\n1. Display the Queue\n2. Add at Front\n3. Delete from Front\n4. Add at Rear\n5. Delete from Rear\n6. Search\n7. Exit\nEnter a valid choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : display(front); break;
            case 2 : front_append(&front, &rear); break;
            case 3 : front_delete(&front, &rear); break;
            case 4 : rear_append(&front, &rear); break;
            case 5 : rear_delete(&front, &rear); break;
            case 6 : search(front); break;
            case 7 : exit(0);
            default : printf("Please enter a valid choice\n");
        }
    }
}