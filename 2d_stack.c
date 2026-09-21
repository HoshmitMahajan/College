
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

char stk[10][20];

int top = -1;
int top_str = -1;


int isFull()
{
    if (top == (SIZE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char c[])
{
    if (isFull() == 1)
    {
        printf("STACK IS FULL.");
        return;
    }
    else
    {
        top = top + 1;
        strcpy(stk[top], c);
    }
}

void pop()
{
    if (isEmpty() == 0)
    {
        char item[10];
        strcpy(item, stk[top]);
        top = top - 1;
        printf("Popped Item: %s", item);
    }
    else
    {
        printf("STACK IS EMPTY.");
        return;
    }
}

void display()
{
    if (isEmpty() == 1)
    {
        printf("STACK IS EMPTY.");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%s ", stk[i]);
    }
}







int main() 
{
    int istrue = 1;
    while (istrue == 1)
	{
		printf("Choose 1 for PUSH.\n");
		printf("Choose 2 for POP.\n");
		printf("Choose 3 for Displaying Stack.\n");
		printf("Choose 4 to EXIT..\n");
		printf("Enter choice: \n");
		int choice;
		scanf("%d", &choice);
		char expr[SIZE];
		switch (choice)
		{
			case 1:
				printf("Enter the string to be pushed: ");
				char temp[10];
				scanf(" %s", temp);
				push(temp);
				printf("\n");
				break;
			case 2:
				pop();
				printf("\n");
				break;
			case 3:
				display();
				printf("\n");
				break;
                
			case 4:
				istrue = 0;
				break;
		}
    }
    return 0;
}
