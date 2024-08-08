#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the size of the queue

// Define the circular queue
int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to insert an element into the queue
void insert(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

// Function to delete an element from the queue
int delete() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete\n");
        return -1; // Return a sentinel value to indicate failure
    }
    int value = queue[front];
    if (front == rear) {
        // Queue is empty after deletion
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return value;
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = delete();
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
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
