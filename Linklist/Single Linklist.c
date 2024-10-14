#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node* head;

void createnode(int n);
void display();
void insert_beg();
void insert_end();
void insert_middle(int pos);
void delete_beg();
void delete_middle(int pos);
void delete_end();
int search(int val);
int count();

void createnode(int n) {
    node* newnode, * temp;
    int i;
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
    printf("\n Enter data for Node 1: ");
    scanf("%d", &head->data);
    temp = head;
    for (i = 2; i <= n; i++) {
        newnode = (node*)malloc(sizeof(node));
        printf("\n Enter data for Node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void insert_beg() {
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    printf("Enter data to add in the beginning :");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void display() {
    node* temp;
    temp = head;
    printf("\nThe following linked list: \n");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_middle(int pos) {
    node* newnode, * temp, * prev, * current;
    temp = head;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter value for the new node : ");
    scanf("%d", &newnode->data);
    for (int i = 1; i < pos; i++) {
        prev = temp;
        current = temp->next;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = current;
}

void insert_end() {
    node* temp = head;
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    printf("Enter data to add at the end :");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int search(int val) {
    if (head == NULL) {
        return -1;
    }
    int index = 1;
    node* temp = head;
    while (temp->data != val) {
        if (temp->next == NULL) {
            return -1;
        }
        temp = temp->next;
        index++;
    }
    return index;
}

void delete_beg() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    node* temp = head;
    head = temp->next;
    free(temp);
}

void delete_middle(int pos) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    node* temp, * prev, * current;
    temp = head;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        current = temp->next;
        temp = temp->next;
    }
    prev->next = current->next;
    free(current);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    node* temp = head;
    node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    }
    free(temp);
}

int count() {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, pos, val;
    printf("\n Enter total number of nodes: ");
    scanf("%d", &n);
    createnode(n);
    display();

    printf("\n Insert new node at the beginning...\n");
    insert_beg();
    display();

    printf("\n Insert new node at the end...\n");
    insert_end();
    display();

    printf("\n Insert new node at desired position...\n");
    printf("Enter your desired position: ");
    scanf("%d", &pos);
    insert_middle(pos);
    display();

    printf("Enter a value to search: ");
    scanf("%d", &val);
    int ans = search(val);
    if (ans == -1)
        printf("\nValue not found\n");
    else
        printf("\nValue found at index %d\n", ans);
    display();

    printf("\n Delete from beginning...\n");
    delete_beg();
    display();

    printf("\n Delete from your desired position...\n");
    printf("Enter your desired position: ");
    scanf("%d", &pos);
    delete_middle(pos);
    display();

    printf("\n Delete from end...\n");
    delete_end();
    display();

    printf("\nTotal number of nodes: %d\n", count());

    return 0;
}
