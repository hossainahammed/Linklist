#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
node *head;

void createnode(int n);
void display();
void insert_beg();
void insert_mid(int pos);
void insert_end();
void update_beg();
void update_middle(int pos);
void update_end();
void update_at_position(int pos);
void delete_beg();
void delete_mid(int pos);
void delete_end();
void delete_at_position(int pos);
int search(int val);
int count_nodes();

int main()
{
    int n;
    printf("\n Enter total number of nodes: ");
    scanf("%d", &n);
    createnode(n);
    display();

    int choice;
    while (1)
    {
        printf("\n Menu:");
        printf("\n 1. Insert new node at beginning");
        printf("\n 2. Insert new node at end");
        printf("\n 3. Insert new node at middle");
        printf("\n 4. Insert new node at a specific position");
        printf("\n 5. Update beginning node data");
        printf("\n 6. Update data for a middle node");
        printf("\n 7. Update end node data");
        printf("\n 8. Update data for a node at a specific position");
        printf("\n 9. Delete beginning node");
        printf("\n 10. Delete middle node");
        printf("\n 11. Delete end node");
        printf("\n 12. Delete node at a specific position");
        printf("\n 13. Search for a value");
        printf("\n 14. Count nodes");
        printf("\n 15. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_beg();
            display();
            break;
        case 2:
            insert_end();
            display();
            break;
        case 3:
            insert_mid(4);
            display();
            break;
        case 4:
            {
                int pos;
                printf("\n Enter the position to insert: ");
                scanf("%d", &pos);
                insert_mid(pos);
                display();
            }
            break;
        case 5:
            update_beg();
            display();
            break;
        case 6:
            {
                int pos;
                printf("\n Enter the position to update: ");
                scanf("%d", &pos);
                update_middle(pos);
                display();
            }
            break;
        case 7:
            update_end();
            display();
            break;
        case 8:
            {
                int pos;
                printf("\n Enter the position to update: ");
                scanf("%d", &pos);
                update_at_position(pos);
                display();
            }
            break;
        case 9:
            delete_beg();
            display();
            break;
        case 10:
            {
                int pos;
                printf("\n Enter the position to delete: ");
                scanf("%d", &pos);
                delete_mid(pos);
                display();
            }
            break;
        case 11:
            delete_end();
            display();
            break;
        case 12:
            {
                int pos;
                printf("\n Enter the position to delete: ");
                scanf("%d", &pos);
                delete_at_position(pos);
                display();
            }
            break;
        case 13:
            {
                int val;
                printf("\n Enter a value to search: ");
                scanf("%d", &val);
                int result = search(val);
                if (result == -1)
                    printf("\nValue not found\n");
                else
                    printf("\nValue found at position %d\n", result);
            }
            break;
        case 14:
            printf("\n Total number of nodes: %d\n", count_nodes());
            break;
        case 15:
            exit(0);
        default:
            printf("\n Invalid choice! Please try again.");
        }
    }

    return 0;
}

void createnode(int n)
{
    node *newnode, *temp;
    int i;
    head = (node *)malloc(sizeof(node));
    head->next = head; // Point the last node back to the first node
    printf("\n Enter data for node 1: ");
    scanf("%d", &head->data);
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("\n Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = head; // Point the last node back to the first node
        temp->next = newnode;
        temp = temp->next;
    }
}

void insert_beg()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data for the new beginning node: ");
    scanf("%d", &newnode->data);
    newnode->next = head->next; // Point the new node to the second node
    head->next = newnode;       // Point the head to the new node
}

void insert_mid(int pos)
{
    int i;
    node *newnode, *prev, *current, *temp;
    temp = head;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data for the new middle node: ");
    scanf("%d", &newnode->data);
    for (i = 1; i < pos; i++)
    {
        prev = temp;
        current = temp->next;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = current;
}

void insert_end()
{
    node *newnode, *temp;
    temp = head;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data for the new end node: ");
    scanf("%d", &newnode->data);
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head; // Point the last node back to the first node
}

void update_beg()
{
    if (head == NULL)
    {
        printf("\n The linked list is empty. Cannot update the beginning node data.");
        return;
    }

    int new_data;
    printf("\n Enter the new data for the beginning node: ");
    scanf("%d", &new_data);

    head->data = new_data;
}

void update_middle(int pos)
{
    int i;
    node *temp;
    temp = head;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    printf("\n Enter new data for the middle node at position %d: ", pos);
    scanf("%d", &temp->data);
}

void update_end()
{
    if (head == NULL)
    {
        printf("\n The linked list is empty. Cannot update the end node data.");
        return;
    }

    node *temp = head;
    int new_data;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    printf("\n Enter the new data for the last node: ");
    scanf("%d", &new_data);

    temp->data = new_data;
}

void update_at_position(int pos)
{
    int i;
    node *temp;
    temp = head;
    for (i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("\n Position %d does not exist in the linked list.", pos);
            return;
        }
        temp = temp->next;
    }
    printf("\n Enter new data for the node at position %d: ", pos);
    scanf("%d", &temp->data);
}

void delete_beg()
{
    if (head == NULL)
    {
        printf("\n The linked list is empty. Nothing to delete.");
        return;
    }
     if (head->next == head) // If there is only one node in the circular list
    {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    node *prev,*current,*next_node;
    while (temp->next!= head)
    {
        prev=temp;
        current=temp->next;

        temp = temp->next;
    }

     next_node = head->next;
     current->next=next_node;
    free(head);
    head=next_node;


    /*node *next_node = head->next;
    head = next_node;
    temp->next = head; // Point the last node back to the first node
    free(temp);*/
}


void delete_mid(int pos)
{
    if (head == NULL)
    {
        printf("\n The linked list is empty. Nothing to delete.");
        return;
    }

    int i;
    node *temp, *prev, *current;
    temp = head;
    for (i = 1; i < pos; i++)
    {
        prev = temp;
        current = temp->next;
        temp = temp->next;
    }
    prev->next = current->next;
    free(current);
}

void delete_end()
{
    if (head == NULL)
    {
        printf("\n The linked list is empty. Nothing to delete.");
        return;
    }
    node *temp = head;
    node *prev,*current;

    while(temp->next!=head){
        prev =temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=current->next;
    free(current);
/*
    node *temp = head;
    node *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
    {
        prev->next = head; // Point the last node back to the first node
    }
    free(temp);*/
}

void delete_at_position(int pos)
{
    if (head == NULL)
    {
        printf("\n The linked list is empty. Nothing to delete.");
        return;
    }

    int i;
    node *temp, *prev;
    temp = head;
    for (i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("\n Position %d does not exist in the linked list. Nothing to delete.", pos);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

int search(int val)
{
    int index = 1;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return index;
        }
        temp = temp->next;
        index++;
        if (temp == head) // Check if we have looped back to the beginning
            break;
    }
    return -1; // Value not found
}

int count_nodes()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
        if (temp == head) // Check if we have looped back to the beginning
            break;
    }
    return count;
}

void display()
{
    node *temp;
    temp = head;
    printf("\n You have successfully created the following circular linked list: \n");
    if (temp != NULL)
    {
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("Head\n");
}
