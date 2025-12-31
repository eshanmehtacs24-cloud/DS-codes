#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


void createDLL(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void insertLeft(int key, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

   
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nKey not found!\n");
        return;
    }

    
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }


    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}


void deleteNode(int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nNode with value %d not found!\n", key);
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

   
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}


void displayDLL() {
    struct Node* temp = head;
    printf("\nDoubly Linked List: ");
    printf("NULL<-");
    while (temp != NULL) {
        if(temp->next!=NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
        }
        else{
            printf("%d->",temp->data);
            temp=temp->next;
        }
       
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---");
        printf("\n1. Create (Insert at end)");
        printf("\n2. Insert to the left of node");
        printf("\n3. Delete node by value");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                createDLL(value);
                break;

            case 2:
                printf("Enter key (value of node): ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLeft(key, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                displayDLL();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
