#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
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

// Function to push an element onto the stack
void push(Node **top, int data) {
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1; // Return a sentinel value
    }
    Node *temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

// Function to display the stack elements
void display(Node *top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    Node *temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node *top = NULL; // Initialize the stack (top) to NULL
    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                value = pop(&top);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(top);
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
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}
