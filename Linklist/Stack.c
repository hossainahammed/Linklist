#include <stdio.h>
int top = -1, maxstk;
int stack[10000];

int main() {
    int i, choice;
    printf("Enter the size of the stack: ");
    scanf("%d", &maxstk);

    do {
        printf("\nEnter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        printf("Enter 5 to peek (view top element)\n"); // Added option for peek
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                topmost();
                break;
            case 5:
                peek(); // Call the peek function
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid Choice");
        }
    } while (choice != 0);
}

void push() {
    int x;

    if (top == maxstk - 1) {
        printf("\nOverflow\n");
    } else {
        printf("\nEnter the element: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("\nUnderflow\n");
    } else {
        printf("\n%d is popped\n", stack[top]);
        top--;
    }
}

void topmost() {
    if (top == -1) {
        printf("Stack is Empty");
    } else {
        printf("%d is on the top\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty");
    } else {
        printf("\nElements are: \n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
    printf("\n");
}

void peek() {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nTop element: %d\n", stack[top]);
    }
}
