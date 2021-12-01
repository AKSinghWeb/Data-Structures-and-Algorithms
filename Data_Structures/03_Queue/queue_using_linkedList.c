#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int value);
void dequeue();
void print();
void freeList();

int main(void)
{
    int choice = 0;
    int value;

    while (choice != 4)
    {
        printf("-----------------------------------------------------------------------------");
        printf("\nChoose for Queue between: \n");
        printf("(1) Enqueue\n(2) Dequeue\n(3) Display Queue\n(4) Exit\n\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1:
                printf("Enter Value to enqueue in the Queue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print();
                break;
            case 4:
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

void enqueue(int value)
{   
    node *new = (node *)malloc(sizeof(node));

    new->data = value;
    new->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = new;
        rear = new;
        return;
    }

    rear->next = new;
    rear = new;

}

void dequeue()
{   
    node *temp = front;
    if (front == NULL)
    {   
        printf("Error: Empty Queue\n");
    }

    if (front == rear)
    {
        front = rear = NULL;
        return;
    }

    front = front->next;
    free(temp);
}

void print()
{   
    if (front == NULL)
    {
        printf("Error: Empty Queue\n");
        return;
    }
    node *temp = front;

    printf("Queue elements are:\n\n");
    while(temp != NULL)
    {
        printf("\t %d",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}


void freeList()
{
    if (front == NULL)
    {
        return;
    }
    node *temp;
    while (front != NULL)
    {
        // temp points to second node
        temp = front->next;
        // head is freed from memory
        free(front);
        // head again points to first node as temp now points to first node
        front = temp;
    }
}