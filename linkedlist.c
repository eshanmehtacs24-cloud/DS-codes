#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

// Create linked list
void create(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
            temp = start;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Display linked list
void display() {
    struct Node* temp = start;
    if (temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = start;
    start = newNode;
    printf("Inserted %d at beginning.\n", data);
}

// Insert at end
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = start;
    newNode->data = data;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at end.\n", data);
}

// Insert at specific position
void insertAtPosition(int data, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = start;
    int i;

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    newNode->data = data;

    if (pos == 1) {
        newNode->next = start;
        start = newNode;
        printf("Inserted %d at position %d.\n", data, pos);
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
}

// Delete head node
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted head node with data %d.\n", temp->data);
    free(temp);
    return head;
}

// Delete end node
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        printf("Deleted last node with data %d.\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted end node with data %d.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete node at position
struct Node* deletePosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (pos <= 0) {
        printf("Invalid position.\n");
        return head;
    }

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted node at position 1 with data %d.\n", temp->data);
        free(temp);
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    struct Node* ptr = temp->next;
    printf("Deleted node at position %d with data %d.\n", pos, ptr->data);
    temp->next = ptr->next;
    free(ptr);
    return head;
}

// Sort linked list
struct Node* sorting(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = head;
    int temp;

    while (current != NULL) {
        struct Node* index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    printf("List sorted in ascending order.\n");
    return head;
}

// Reverse linked list
struct Node* reversing(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *prev = NULL, *current = head, *next1 = NULL;

    while (current != NULL) {
        next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
    }

    printf("List reversed.\n");
    return prev;
}

// Concatenate two linked lists
struct Node* concatenation(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    printf("Lists concatenated successfully.\n");
    return head1;
}

// ---------------- MAIN FUNCTION ---------------- //
int main() {
    int n, data, choice, pos;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    create(n);
    display();

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Head\n");
        printf("5. Delete End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Sort\n");
        printf("9. Reverse\n");
        printf("10. Concatenate Another List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;

            case 4:
                if (start == NULL)
                    printf("List is empty.\n");
                else
                    start = deleteHead(start);
                break;

            case 5:
                if (start == NULL)
                    printf("List is empty.\n");
                else
                    start = deleteEnd(start);
                break;

            case 6:
                if (start == NULL)
                    printf("List is empty.\n");
                else {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    start = deletePosition(start, pos);
                }
                break;

            case 7:
                display();
                break;

            case 8:
                if (start == NULL)
                    printf("List is empty.\n");
                else
                    start = sorting(start);
                break;

            case 9:
                if (start == NULL)
                    printf("List is empty.\n");
                else
                    start = reversing(start);
                break;

            case 10: {
                int m;
                struct Node* secondList = NULL;
                printf("Enter number of nodes in second list: ");
                scanf("%d", &m);

                if (m <= 0) {
                    printf("Cannot concatenate an empty list.\n");
                    break;
                }

                struct Node *newNode, *temp;
                for (int i = 1; i <= m; i++) {
                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    printf("Enter data for node %d of second list: ", i);
                    scanf("%d", &data);
                    newNode->data = data;
                    newNode->next = NULL;
                    if (secondList == NULL) {
                        secondList = newNode;
                        temp = secondList;
                    } else {
                        temp->next = newNode;
                        temp = newNode;
                    }
                }

                start = concatenation(start, secondList);
                printf("After concatenation: ");
                display();
                break;
            }

            case 11:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
