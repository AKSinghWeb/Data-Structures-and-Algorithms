#include <stdio.h>

#define MAX_SIZE 10

int aStack[MAX_SIZE];
int top = -1;

void push(int value);
void pop();
void peek();
int isEmpty();
void displayStack();

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
                break;
            default:
                printf("Invalid Choice");
                break;
        }
    }
    return 0;
}

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow \n");
        return;
    }

    aStack[++top] = value;
}

void pop()
{
    if (isEmpty() == 1)
    {
        printf("Error: Stack is empty");
        return;
    }

    top--;
}

void peek()
{
    if (isEmpty() == 1)
    {
        printf("Error: Stack is empty");
        return;
    }
    printf("%d\n", aStack[top]);
}

int isEmpty()
{
    return (top == -1) ? 1 : 0;
}

void displayStack()
{   
    if (isEmpty() == 1)
    {
        printf("Error: Stack is empty");
        return;
    }
    printf("\nPrinting  stack from TOP to BOTTOM:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", aStack[i]);
    }
}