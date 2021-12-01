// Implementaion of linked list(print,insert,delete,search,reverse) in C.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a node using a struct
typedef struct node
{
    int data;
    struct node *next;
}
node;

node *head = NULL;

// Function prototypes
void insert();
void delete ();
bool search();
void reverseList(node *p);
//void reverseList();
void print();
void freeList();

int main(void)
{
    int choice = 0;

    while (choice != 6)
    {
        printf("-----------------------------------------------------------------------------");
        printf("\nChoose for Singly Linked List between: \n");
        printf("(1) Insert\n(2) Delete\n(3) Search\n(4) Print\n(5) Reverse list\n(6) Exit\n\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            search() ? printf("\nItem Found in list\n") : printf("\nItem not found in list\n");
            break;
        case 4:
            print();
            break;
        case 5:
            reverseList(head);
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

// Function to insert user input element at any index
void insert()
{
    int data, index;

    // Create a new node dynamically
    node *new = (node *)malloc(sizeof(node));

    printf("Enter a number to insert in the linked list: ");
    scanf("%d", &data);
    printf("Enter position to insert(choose 1 to insert at the beginning and 'n' to insert at any index: ");
    scanf(" %d", &index);

    new->data = data;
    new->next = NULL;

    // Insert node at the beginning
    if (index == 1)
    {
        new->next = head;
        head = new;
        return;
    }

    // temp variable to keep track of nodes
    node *temp = head;

    for (int i = 0; i < index - 2; i++)
    {
        temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;
}

// Function to delete a list item using its index
void delete ()
{
    int index;
    printf("Enter position to delete(choose 1 to delete firlst element and 'n' to delete any element: ");
    scanf("%d", &index);

    // Variable temp1 is used to traverse the linked list
    node *temp1 = head;

    if (index == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }

    // Variable temp2 is used to keep track of item to be deleted/memory freed
    node *temp2 = NULL;

    for (int i = 0; i < index - 2; i++)
    {
        // temp1 points to (n-1)th element
        temp1 = temp1->next;
    }

    // temp2 points to element to be deleted
    temp2 = temp1->next;

    // temp1's next pointer points to deleted item's next node
    temp1->next = temp2->next;
    free(temp2);
}

// Function to search for an element
bool search()
{
    int element;
    printf("Enter element to be searched: ");
    scanf("%d", &element);

    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == element)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

// Recursive function to reverse a linked list
void reverseList(node *p)
{
    //  if (p == NULL) return;
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    // See video of mycodeschool (recursively reverse) 
    reverseList(p->next);

    node *q = p->next;
    q->next = p;
    p->next = NULL;
}

// Function to reverse a list using iterative method
// void reverseList()
// {
//     node *current, *prev, *next;

//     current = head;
//     prev = NULL;

//     while (current != NULL)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }

//     head = prev;
// }

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

// Function to print elements of linked list
void print()
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    node *temp = head;
    printf("Linked list items are :\n");
    while (temp != NULL)
    {
        printf("\t%d\n", temp->data);
        temp = temp->next;
    }
}
