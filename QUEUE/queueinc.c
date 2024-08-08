#include <stdio.h>

#define SIZE 100  // Maximum size of the queue

int queue[SIZE];
int front = -1;  // Initialize front of the queue
int rear = -1;   // Initialize rear of the queue

// Function to add an element to the queue
void enqueue(int value) {
    if (rear == SIZE - 1) {  // Queue is full
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {  // Queue is empty
        front = 0;  // Set front to 0 if the queue was empty
    }
    queue[++rear] = value;
    printf("%d added to queue\n", value);
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {  // Queue is empty
        printf("Queue Underflow\n");
        return -1;  // Return a sentinel value
    }
    return queue[front++];
}

// Function to display the queue elements
void display() {
    if (front == -1 || front > rear) {  // Queue is empty
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
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
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
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
