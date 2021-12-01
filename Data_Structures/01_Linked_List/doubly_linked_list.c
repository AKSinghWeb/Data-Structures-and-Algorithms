// Implementaion of doubly linked list to insert, delete, print

#include <stdio.h>
#include <stdlib.h>

// Create a node with pointer to store previous and next node using a struct
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

// Function prototypes
void insertAtStart();
void insertAtEnd();
void delete ();
void print();
void reversePrint();
void freeList();

int main(void)
{
    int choice = 0;

    while (choice != 6)
    {
        printf("-----------------------------------------------------------------------------");
        printf("\nChoose for Doubly Linked list between: \n");
        printf("(1) Insert at Start\n(2) Insert at End\n(3) Delete\n(4) Print\n(5) Print in reverse\n(6) Exit\n\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            insertAtStart();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            delete ();
            break;
        case 4:
            print();
            break;
        case 5:
            reversePrint();
            break;
        case 6:
            freeList();
            break;
        default:
            printf("Invalid Choice");
            freeList();
            break;
        }
    }
    return 0;
}

// Funtion to insert at start of Doubly Linked List
void insertAtStart()
{
    int data;

    printf("Enter number to be inserted at start: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node));

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (head == NULL)
    {
        head = new;
        return;
    }
    new->next = head;
    head->prev = new;
    head = new;
}

// Funtion to insert at start of Doubly Linked List
void insertAtEnd()
{
    // temp is used to go to last node
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    int data;
    printf("Enter number to be inserted at End: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node));

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (head == NULL)
    {
        head = new;
        return;
    }
    temp->next = new;
    new->prev = temp;
}

// Function to print elements in default order
void print()
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    node *temp = head;
    printf("Doubly Linked list items are :\n\n");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print elements in reverse order
void reversePrint()
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Doubly Linked list items in reverse order are :\n\n");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to free dynamically allocated memory
void freeList()
{
    if (head == NULL)
    {
        return;
    }
    node *temp;
    while (head != NULL)
    {
        // temp points to second node
        temp = head->next;
        // head is freed from memory
        free(head);
        // head again points to first node as temp now points to first node
        head = temp;
    }
}

// Function to delete an item from the doubly linked list
void delete ()
{
    int element;
    printf("Enter element to be deleted: ");
    scanf("%d", &element);

    // temp1 keeps track of item to be deleted
    node *temp1 = head;
    // temp2 points to previous node of node to be deleted
    node *temp2 = NULL;

    while (temp1 != NULL)
    {
        if (temp1->data == element)
        {
            break;
        }

        temp1 = temp1->next;
    }

    // Deletes when item is the first node
    if (temp1 == head)
    {
        temp2 = head->next;
        free(head);
        head = temp2;

        return;
    }

    temp2 = temp1->prev;
    temp2->next = temp1->next;
    free(temp1);
}