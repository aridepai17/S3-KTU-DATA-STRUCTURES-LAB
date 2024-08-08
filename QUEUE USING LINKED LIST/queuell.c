#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
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

// Function to enqueue (insert at the end)
void enqueue(Node **rear, Node **front, int data) {
    Node *newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (delete from the front)
int dequeue(Node **front) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return -1; // Return a sentinel value
    }
    Node *temp = *front;
    int dequeuedValue = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        // If the queue becomes empty, set rear to NULL
        int rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

// Function to display the queue elements
void display(Node *front) {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    Node *temp = front;
    printf("Queue elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node *front = NULL, *rear = NULL; // Initialize the queue
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&rear, &front, value);
                break;
            case 2:
                value = dequeue(&front);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    // Free allocated memory (optional)
    Node *temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
