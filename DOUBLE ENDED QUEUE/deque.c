#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the size of the deque

// Define the deque
int deque[SIZE];
int front = -1;
int rear = -1;

// Function to check if the deque is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at the front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d at the front\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    deque[front] = value;
    printf("%d inserted at the front\n", value);
}

// Function to insert an element at the rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d at the rear\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    deque[rear] = value;
    printf("%d inserted at the rear\n", value);
}

// Function to delete an element from the front
int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from the front\n");
        return -1; // Return a sentinel value to indicate failure
    }
    int value = deque[front];
    if (front == rear) {
        front = rear = -1; // The deque is now empty
    } else {
        front = (front + 1) % SIZE;
    }
    return value;
}

// Function to delete an element from the rear
int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from the rear\n");
        return -1; // Return a sentinel value to indicate failure
    }
    int value = deque[rear];
    if (front == rear) {
        front = rear = -1; // The deque is now empty
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
    return value;
}

// Function to display the elements of the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nDouble Ended Queue Operations:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                value = deleteFront();
                if (value != -1) {
                    printf("Deleted value from the front: %d\n", value);
                }
                break;
            case 4:
                value = deleteRear();
                if (value != -1) {
                    printf("Deleted value from the rear: %d\n", value);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
