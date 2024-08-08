#include <stdio.h>

#define SIZE 100  // Maximum size of the stack

int stack[SIZE];
int top = -1;  // Initialize top of the stack

// Function to push an element onto the stack
void push(int value) {
    if (top == SIZE - 1) {  // Stack is full
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {  // Stack is empty
        printf("Stack Underflow\n");
        return -1;  // Return a sentinel value
    }
    return stack[top--];
}

// Function to display the stack elements
void display() {
    if (top == -1) {  // Stack is empty
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
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
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}