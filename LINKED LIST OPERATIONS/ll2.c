#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the front of the list
void deleteFromFront(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a specific node with given data
void deleteSpecificNode(Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    Node *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    Node *head = NULL; // Initialize the head of the list to NULL
    int choice, data;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Delete Specific Node\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteFromFront(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                printf("Enter data of the node to delete: ");
                scanf("%d", &data);
                deleteSpecificNode(&head, data);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    // Free allocated memory
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
