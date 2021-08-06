#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

void inorder(Node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

Node *insert(Node *root, int key){
    Node *temp;
    if(root==NULL){
        temp = (Node *)malloc(sizeof(Node));
        temp->data = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if((root->data) == key)
        return root;
    if((root->data) > key)
        root->left = insert(root->left, key);
    if((root->data) < key)
        root->right = insert(root->right, key);
    return root;
}

Node *search(Node *root, int key) {
    if(root == NULL || root->data == key)
        return root;
    if((root->data) < key)
        return search(root->right, key);
    if((root->data) > key)
        return search(root->left, key);
}

Node *minNodeValue(Node *root){
    Node *current = root;
    while((current->left) != NULL)
        current = current->left;
    return current;
}

Node *deleteNode(Node *root, int key){
    if(root == NULL)
        return root;
    if(key < (root->data))
        root->left = deleteNode(root->left, key);
    if (key > (root->data))
        root->right = deleteNode(root->right, key);
    if(key == (root->data)){
        if((root->left) == NULL){
            Node *temp = root->right;
            root = NULL;
            return temp;
        }
        if((root->right) == NULL){
            Node *temp = root->left;
            root = NULL;
            return temp;
        }
        Node *temp = minNodeValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void main(){
    int ch, item;
    Node *root = NULL;
    while(1){
        printf("\nAvailable Operations\n1. Inorder traversal\n2. Insert\n3. Delete\n4. Search\n5. Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
        case 1 : if(root == NULL) printf("BST is empty\n");
                else inorder(root); break;
        case 2 : printf("Enter integer to be inserted : ");
                scanf("%d", &item);
                root = insert(root, item);
                printf("Updated BST : Rooted at %d\n",root->data);
                inorder(root); break;
        case 3 : printf("Enter an integer for deletion : ");
                scanf("%d", &item);
                root = deleteNode(root, item);
                if(root!=NULL) {
                    printf("Updated BST : Rooted at %d\n",root->data);
                    inorder(root); break;
                }else printf("BST is empty\n"); break;
        case 4 : printf("Enter integer to be searched : ");
                scanf("%d", &item);
                Node *temp = search(root, item);
                if(temp == NULL) printf("%d is not present in BST\n", item);
                else printf("%d is present in BST\n", item); break;
        case 5 : exit(0);
        default: printf("Please enter a valid choice\n");
        }
    }
}