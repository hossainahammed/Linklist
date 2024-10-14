#include <stdio.h>

int front = -1, rear = -1, n;
int queue[1000];

int main() {
    int x;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    int choice;

    do {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to peek (view the front element)\n"); // Added option for peek
        printf("Enter 5 to exit\n\n"); // Changed option number to avoid conflicts
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data you want to insert: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek(); // Call the peek function
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("\nInvalid input\n");
        }
    } while (choice != 5);
}

void enqueue(int x) {
    if (rear == n - 1) {
        printf("\nOverflow\n\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty\n\n");
    } else if (front == rear) {
        printf("\n%d is dequeued\n\n", queue[front]);
        front = rear = -1;
    } else {
        printf("\n%d is dequeued\n\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty\n\n");
    } else {
        printf("\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty\n\n");
    } else {
        printf("\nFront element: %d\n\n", queue[front]);
    }
}
