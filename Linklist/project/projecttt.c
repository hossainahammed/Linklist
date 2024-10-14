#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct book {
    int book_id;
    char title[100];
    char author[100];
    int copies;
    struct book *next;
};



#define MAX_QUEUE_SIZE 100
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;



#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;



typedef struct book Book;
Book *head = NULL;



void enqueue(int item);
int dequeue();
void displayQueue();
void push(int item);
int pop();
void displayStack();


void add_book();
void add_book_at_beginning();
void add_book_at_end();
void add_book_at_middle();
void add_book_at_position(int position);
void update_book(int book_id);
void delete_book(int book_id);
void search_book(const char *title);
void display_books();



int isQueueFull() {
    return rear == MAX_QUEUE_SIZE - 1;
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int item) {
    if (isQueueFull()) {
        printf("Queue is full. Cannot enqueue more items.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
    printf("Enqueued %d\n", item);
}

int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return -1;
    }
    int item = queue[front];
    front++;
    return item;
}

void displayQueue() {
    if (isQueueEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}



int isStackFull() {
    return top == MAX_STACK_SIZE - 1;
}

int isStackEmpty() {
    return top == -1;
}

void push(int item) {
    if (isStackFull()) {
        printf("Stack is full. Cannot push more items.\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("Pushed %d\n", item);
}

int pop() {
    if (isStackEmpty()) {
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    }
    int item = stack[top];
    top--;
    return item;
}

void displayStack() {
    if (isStackEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void add_book() {
    int sub_choice;
    printf("Add Book Sub-Options:");
    printf("\n 1. Add at the beginning");
    printf("\n 2. Add at the end");
    printf("\n 3. Add at the middle");
    printf("\n 4. Add at a specific position");
    printf("\n Enter your choice: ");
    scanf("%d", &sub_choice);

    switch (sub_choice) {
        case 1:
            add_book_at_beginning();
            break;
        case 2:
            add_book_at_end();
            break;
        case 3:
            add_book_at_middle();
            break;
        case 4:
            {
                int position;
                printf("Enter the position to add the book: ");
                scanf("%d", &position);
                add_book_at_position(position);
            }
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

void add_book_at_beginning() {
    Book *new_book = (Book *)malloc(sizeof(Book));
    if (new_book == NULL) {
        printf("Memory allocation failed.");
        return;
    }

    new_book->next = NULL;
    new_book->book_id = rand();
    printf("Enter the title of the book: ");
    scanf("%s", new_book->title);
    printf("Enter the author of the book: ");
    scanf("%s", new_book->author);
    printf("Enter the number of copies: ");
    scanf("%d", &(new_book->copies));

    if (head == NULL) {
        head = new_book;
    } else {
        new_book->next = head;
        head = new_book;
    }
 push(new_book->book_id);

    printf("Book added at the beginning successfully.\n");
}

void add_book_at_end() {
    Book *new_book = (Book *)malloc(sizeof(Book));
    if (new_book == NULL) {
        printf("Memory allocation failed.");
        return;
    }

    new_book->next = NULL;
    new_book->book_id = rand();
    printf("Enter the title of the book: ");
    scanf("%s", new_book->title);
    printf("Enter the author of the book: ");
    scanf("%s", new_book->author);
    printf("Enter the number of copies: ");
    scanf("%d", &(new_book->copies));

    if (head == NULL) {
        head = new_book;
    } else {
        Book *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_book;
    }

  push(new_book->book_id);

    printf("Book added at the end successfully.\n");
}

void add_book_at_middle() {
    int count = 0;
    Book *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    if (count < 2) {
        printf("Not enough books to add in the middle.\n");
        return;
    }

    int middle = count / 2;
    add_book_at_position(middle);
}

void add_book_at_position(int position) {
    if (position < 1) {
        printf("Invalid position. Position must be at least 1.\n");
        return;
    }

    if (position == 1) {
        add_book_at_beginning();
        return;
    }

    int count = 0;
    Book *current = head;
    while (current != NULL) {
        count++;
        if (count == position - 1) {
            Book *new_book = (Book *)malloc(sizeof(Book));
            if (new_book == NULL) {
                printf("Memory allocation failed.");
                return;
            }

            new_book->next = NULL;
            new_book->book_id = rand();
            printf("Enter the title of the book: ");
            scanf("%s", new_book->title);
            printf("Enter the author of the book: ");
            scanf("%s", new_book->author);
            printf("Enter the number of copies: ");
            scanf("%d", &(new_book->copies));

            new_book->next = current->next;
            current->next = new_book;
            printf("Book added at position %d successfully.\n", position);
            return;
        }
        current = current->next;
    }

    printf("Invalid position. Position exceeds the number of books.\n");
}

void update_book(int book_id) {
    Book *current = head;
    while (current != NULL) {
        if (current->book_id == book_id) {
            printf("Enter the new title: ");
            scanf("%s", current->title);
            printf("Enter the new author: ");
            scanf("%s", current->author);
            printf("Enter the new number of copies: ");
            scanf("%d", &(current->copies));
            printf("Book with ID %d updated successfully.\n", book_id);
            return;
        }
        current = current->next;
    }

    printf("Book with ID %d not found.\n", book_id);
}

void delete_book(int book_id) {
    Book *current = head;
    Book *prev = NULL;

    while (current != NULL) {
        if (current->book_id == book_id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Book with ID %d deleted successfully.\n", book_id);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Book with ID %d not found.\n", book_id);
}

void search_book(const char *title) {
    Book *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Book found - ID: %d, Title: %s, Author: %s, Copies: %d\n",
                   current->book_id, current->title, current->author, current->copies);
            return;
        }
        current = current->next;
    }
    printf("Book with title '%s' not found.\n", title);
}
void displayStackBooks() {
    if (isStackEmpty()) {
        printf("No books available in the library.\n");
        return;
    }
    printf("Available Books in Stack (Library):\n");
    printf("Book IDs: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void display_books() {
    Book *current = head;
    printf("\n List of Books:\n");
    while (current != NULL) {
        printf("ID: %d, Title: %s, Author: %s, Copies: %d\n", current->book_id, current->title, current->author, current->copies);
        current = current->next;
    }
}

struct stackNodeBorrow {
    int book_id;
    struct stackNodeBorrow *next;
};

struct stackNodeBorrow *topBorrowStack = NULL;


void borrow_book(int book_id);
int return_book();

void borrow_book(int book_id) {

    Book *current = head;
    while (current != NULL) {
        if (current->book_id == book_id && current->copies > 0) {
            push(book_id);
            enqueue(book_id);
            current->copies--;
            printf("Book with ID %d has been borrowed successfully.\n", book_id);
            return;
        }
        current = current->next;
    }
    enqueue(book_id);
    printf("Book with ID %d is either not available or doesn't exist.\n", book_id);
}

int return_book() {
    int book_id = pop();
    if (book_id == -1) {
        printf("No books borrowed.\n");
        return -1;
    }


    int dequeued = dequeue();
    if (dequeued != book_id) {
        printf("Error: Book ID mismatch between borrowed and returned books.\n");
        return -1;
    }


    Book *current = head;
    while (current != NULL) {
        if (current->book_id == book_id) {
            current->copies++;
            printf("Book with ID %d has been returned successfully.\n", book_id);
            return book_id;
        }
        current = current->next;
    }
    return -1;
}


int main() {

    int choice;
    while (1) {
        printf("\n Library Management System Menu:");


         printf("\n 1. Add Book");
        printf("\n 2. Update Book");
        printf("\n 3. Delete Book");
        printf("\n 4. Search Book");
        printf("\n 5. Display Books");
        printf("\n 6. Enqueue (Queue)");
        printf("\n 7. Dequeue (Queue)");
        printf("\n 8. Display Queue");
        printf("\n 9. Push (Stack)");
        printf("\n 10. Pop (Stack)");
        printf("\n 11. Display Stack");
        printf("\n 12. Exit");
        printf("\n 13. Borrow Book");
        printf("\n 14. Return Book");

printf("\n 15. Display Available Books (Stack)");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {

            case 1:
                add_book();
                break;
            case 2:
                {
                    int book_id;
                    printf("Enter the book ID to update: ");
                    scanf("%d", &book_id);
                    update_book(book_id);
                }
                break;
            case 3:
                {
                    int book_id;
                    printf("Enter the book ID to delete: ");
                    scanf("%d", &book_id);
                    delete_book(book_id);
                }
                break;
            case 4:
                {
                    char title[100];
                    printf("Enter the title of the book to search: ");
                    scanf("%s", title);
                    search_book(title);
                }
                break;
            case 5:
                display_books();
                break;


            case 6:
                {
                    int item;
                    printf("Enter the item to enqueue: ");
                    scanf("%d", &item);
                    enqueue(item);
                }
                break;
            case 7:
                dequeue();
                break;
            case 8:
                displayQueue();
                break;


            case 9:
                {
                    int item;
                    printf("Enter the item to push: ");
                    scanf("%d", &item);
                    push(item);
                }
                break;
            case 10:
                pop();
                break;
            case 11:
                displayStack();
                break;
                 case 12:
                exit(0);
            case 13:
                {
                    int book_id;
                    printf("Enter the book ID to borrow: ");
                    scanf("%d", &book_id);
                    borrow_book(book_id);
                }
                break;
            case 14:
                return_book();
                break;

            case 15:
                displayStackBooks();
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
