#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;
Node *head;

void create_node(int n);
void Display();

void delete();
void Display();

void create_node(int n) {
    int i;
    Node *next, *temp, *newnode;

     head = (Node*)malloc(sizeof(Node));
     printf("Enter data for node 1: ");
     scanf("%d", &head->data);
     head->next = NULL;

     temp = head;
    for (i = 2; i <= n; i++) {
        newnode = (Node*)malloc(sizeof(Node));
        printf("Enter data for the node %d:", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void Display() {
    Node *temp;
    temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


   void delete() {
    Node *temp, *prev, *current;
    temp = head;
    int i, pos;
    scanf("%d", &pos);


    for (i = 1; i < pos; i++) {
        prev = temp;
        current = temp->next;
        temp = temp->next;
    }


    int count = 0;
    while (current != NULL) {
        if (count % 2 == 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }
}


int main() {
    int n;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);


    create_node(n);
    Display();

     printf("Enter 2nd position for  start alterate delete:");
     delete();
     Display();
    return 0;
}
