/* Circular Queue Implementation Using Array */

#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int myArray[MAX];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
bool isEmpty();
bool isFull();
void print();

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
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}

void enqueue(int value)
{
    printf("\nInserting %d in the queue ...\n", value);

    if (isFull())
    {
        printf("Error : Cannot insert as Queue is full \n");
    }

    else if (isEmpty())
    {
        front = rear = 0;
    }

    else
    {
        rear = (rear + 1) % MAX;
    }

    myArray[rear] = value;
}

void dequeue()
{
    printf("Dequeuing from the queue ...\n");

    if (isEmpty())
    {
        printf("Error : Cannot Dequeue as Queue is full \n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

bool isEmpty()
{
    return (front == -1 && rear == -1) ? true : false;
}

bool isFull()
{
    if ((rear + 1) % MAX == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print()
{
    if (isEmpty())
    {
        printf("Error: Queue is empty");
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("\t %d", myArray[i]);
        }
        printf("\t %d", myArray[rear]);
    }
    printf("\n\n");
}