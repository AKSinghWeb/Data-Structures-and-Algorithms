#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void push(int value);
void pop();
void peek();
void displayStack();
void freeList();

int main(void)
{
    int choice = 0;
    int value;

    while (choice != 5)
    {
        printf("-----------------------------------------------------------------------------");
        printf("\nChoose for Stack between: \n");
        printf("(1) Push\n(2) Pop\n(3) Peek\n(4) Display Stack\n(5) Exit\n\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter Value to push in the Stack: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            displayStack();
            break;
        case 5:
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

void push(int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = value;

    new->next = head;
    head = new;
}

void pop()
{
    if (head == NULL)
        printf("Error stack is Empty\n");
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void peek()
{
    if (head == NULL)
        printf("Error stack is Empty\n");
    else
    {
        printf("Top element is : %d\n",head->data);
    }
}

void displayStack()
{
    if (head == NULL)
        printf("Error stack is Empty\n");
    else
    {
        node *temp = head;
        printf("Stack elements are: \n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

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