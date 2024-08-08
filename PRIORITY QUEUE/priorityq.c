#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the priority queue

// Define the priority queue structure
typedef struct {
    int data[MAX];
    int priority[MAX];
    int size;
} PriorityQueue;

// Function to initialize the priority queue
void initialize(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to insert an element into the priority queue
void insert(PriorityQueue *pq, int value, int priority) {
    if (pq->size == MAX) {
        printf("Priority Queue is full\n");
        return;
    }

    // Find the position where the new element should be inserted
    int i;
    for (i = pq->size - 1; i >= 0 && pq->priority[i] < priority; i--) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
    }

    pq->data[i + 1] = value;
    pq->priority[i + 1] = priority;
    pq->size++;
}

// Function to delete (dequeue) and return the element with the highest priority
int dequeue(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1; // Return a sentinel value to indicate failure
    }

    // The element with the highest priority is at the front of the queue
    int maxValue = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return maxValue;
}

// Function to display the elements of the priority queue
void display(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue elements (Value: Priority):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("%d: %d\n", pq->data[i], pq->priority[i]);
    }
}

int main() {
    PriorityQueue pq;
    int choice, value, priority;

    initialize(&pq);

    do {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter priority of the value: ");
                scanf("%d", &priority);
                insert(&pq, value, priority);
                break;
            case 2:
                value = dequeue(&pq);
                if (value != -1) {
                    printf("Dequeued value with highest priority: %d\n", value);
                }
                break;
            case 3:
                display(&pq);
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
