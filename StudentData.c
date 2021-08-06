#include<stdio.h>
#include<stdlib.h>

struct node{
    int roll;
    char name[20];
    char prog[10];
    int start;
    int end;
    struct node *link;
};
typedef struct node Student;

void viewByRoll(Student *s){
    if(s==NULL){
        printf("List is empty\n");
        return;
    }
    int roll;
    printf("\nEnter a valid Roll Number : ");
    scanf("%d", &roll);
    while(s != NULL){
        if(s->roll == roll){
            printf("Student found\nRoll : %d\tName : %s\tProgram : %s\tSession : %d - %d\n",s->roll,s->name,s->prog,s->start,s->end);
            return;
        }
        s = s->link;
    }
    printf("No student found with this Roll Number\n");
}

void addStudent(Student **s){
    Student *nn = (Student *)malloc(sizeof(Student));
    printf("Enter Student details one by one\nRoll Number : "); scanf("%d",&(nn->roll));
    printf("Name : "); scanf("%s",nn->name);
    printf("Program : "); scanf("%s",nn->prog);
    printf("Start year : "); scanf("%d",&(nn->start));
    printf("End year : "); scanf("%d",&(nn->end));
    nn->link = NULL;
    if(*s == NULL){
        *s = nn;
        printf("Student added suceessfully\n");
        return;
    }
    Student *temp = *s;
    while(temp->link != NULL) temp=temp->link;
    temp->link = nn;
    printf("Student addedd successfully\n");
}

void showAll(Student *s){
    if(s==NULL){
        printf("List is empty\n");
        return;
    }
    printf("All Students\n");
    while(s!=NULL){
        printf("Roll : %d\tName : %s\tProgram : %s\tSession : %d - %d\n",s->roll,s->name,s->prog,s->start,s->end);
        s=s->link;
    }
}

void deleteStudent(Student **s){
    if(*s==NULL){
        printf("List is empty\n");
        return;
    }
    int roll;
    printf("Enter a valid Roll Number to delete record : ");
    scanf("%d",&roll);
    Student *temp = (*s)->link, *prev=*s;
    if(prev->roll == roll){ // Student found in FIRST Position
        *s = (*s)->link;
        free(prev);
        printf("Student deleted successfully\n");
        return;
    }
    while(temp != NULL) {
        if(temp->roll == roll){ // Student found in between
            prev->link = temp->link;
            free(temp);
            printf("Student deleted successfully\n");
            return;
        }
        prev = temp;
        temp = temp->link;
    }
    printf("Roll number not found\n");
}

void updateRecord(Student **s){
    if(*s==NULL){
        printf("List is empty\n");
        return;
    }
    int rno, ch, buf;
    char buffer[20];
    printf("Enter a valid Roll Number to update record : ");
    scanf("%d",&rno);
    Student *temp = *s;
    while(temp != NULL){
        if((temp->roll) == rno){
            //printf("%d %d\n", temp->roll, rno);
            printf("Student found\nRoll : %d\tName : %s\tProgram : %s\tSession : %d - %d\nEnter which field you want to update : \n1. Roll Number\n2. Name\n3. Program\n4. Start year\n5. End year\nEnter your choice : ",(temp)->roll,(temp)->name,(temp)->prog,(temp)->start,(temp)->end);
            scanf("%d",&ch);
            switch(ch){
                case 1 : printf("Enter correct roll number : "); scanf("%d", &buf); (temp->roll)=buf; break;
                case 2 : printf("Enter correct name : "); scanf("%s",&(temp->name)); break;
                case 3 : printf("Enter correct program : "); scanf("%s",&(temp->prog)); break;
                case 4 : printf("Enter correct start year : "); scanf("%d", &buf); (temp->start)=buf; break;
                case 5 : printf("Enter correct end year : "); scanf("%d", &buf); (temp->end)=buf; break;
                default : printf("Please enter correct choice and Try again\n");
            }
            printf("Student record updated successfully\n");
            return;
        }
        temp = temp->link;
    }
    printf("Student not found with this Roll Number\n");
}

void main(){
    int ch;
    Student *list = NULL;
    while(1){
        printf("\nAvailable operations\n1. View by Roll No.\n2. Add Student\n3. Delete Student\n4. Update a Student Record\n5. View All Records\n6. Exit\nEnter yout choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : viewByRoll(list); break;
            case 2 : addStudent(&list); break;
            case 3 : deleteStudent(&list); break;
            case 4 : updateRecord(&list); break;
            case 5 : showAll(list); break;
            case 6 : exit(0);
            default : printf("Please enter a valid choice\n");
        }
    }
}