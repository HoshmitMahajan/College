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

void pop(char item[10])
{
    if (isEmpty() == 0)
    {
        strcpy(item, stk[top]);
        top = top - 1;
        printf("Popped Item: %s\n", item);
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

void postfix_to_infix(char exp[])
{
	int length = strlen(exp);
	char op2[10];
	char op1[10];
	char E1[100];
	char x;
	for (int i = 0; i < length; i++)
	{
		x = exp[i];
		if (isalpha(x))
		{
			push(&x);
		}
		else
		{
			strcpy(E1, "");
			pop(op2);
			pop(op1);
			
			strcat(E1, "(");
			strcat(E1, op1);
			strcat(E1, &x);
			strcat(E1, op2);
			strcat(E1, ")");
			push(E1);
		}
		
	}
	printf("Infix Expression is: %s\n", stk[top]);
}

void postfix_to_prefix(char exp[])
{
	int length = strlen(exp);
	char op2[10];
	char op1[10];
	char E1[100];
	char x;
	for (int i = 0; i < length; i++)
	{
		x = exp[i];
		if (isalpha(x))
		{
			push(&x);
		}
		else
		{
			strcpy(E1, "");
			pop(op2);
			pop(op1);
			
			strcat(E1, &x);
			strcat(E1, op1);
			strcat(E1, op2);
			push(E1);
		}
		
	}
	printf("Prefix Expression is: %s\n", stk[top]);
}

void prefix_infix(char exp[])
{
	int length = strlen(exp);
	char op2[10];
	char op1[10];
	char E1[100];
	char x;
	for (int i = length-1; i >= 0; i--)
	{
		x = exp[i];
		if (isalpha(x))
		{
			push(&x);
		}
		else
		{
			strcpy(E1, "");
			pop(op1);
			pop(op2);
			
			strcat(E1, "(");
			strcat(E1, op1);
			strcat(E1, &x);
			strcat(E1, op2);
			strcat(E1, ")");
			push(E1);
		}
		
	}
	printf("Infix Expression is: %s\n", stk[top]);
}

void prefix_postfix(char exp[])
{
	int length = strlen(exp);
	char op2[10];
	char op1[10];
	char E1[100];
	char x;
	for (int i = length-1; i >= 0; i--)
	{
		x = exp[i];
		if (isalpha(x))
		{
			push(&x);
		}
		else
		{
			strcpy(E1, "");
			pop(op1);
			pop(op2);
			
			strcat(E1, op1);
			strcat(E1, op2);
			strcat(E1, &x);
			push(E1);
		}
		
	}
	printf("Prefix Expression is: %s\n", stk[top]);
}
int main() 
{
    int istrue = 1;
    while (istrue == 1)
	{
		printf("Choose 1 for PUSH.\n");
		printf("Choose 2 for POP.\n");
		printf("Choose 3 for Displaying Stack.\n");
		printf("Choose 4 for Postfix to Infix Conversion.\n");
		printf("Choose 5 for Postfix to Prefix Conversion.\n");
		printf("Choose 6 for Prefix to Infix Conversion.\n");
		printf("Choose 7 for Prefix to Prefix Conversion.\n");
		printf("Choose 8 to EXIT..\n");
		printf("Enter choice: \n");
		int choice;
		scanf("%d", &choice);
		char expr[SIZE];
		char temp2[100];
		char exp[100];
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
				
				pop(temp2);
				printf("\n");
				break;
			case 3:
				display();
				printf("\n");
				break;
                	case 4:
                		
                		printf("Enter the exp: ");
                		scanf("%s", exp);
                		postfix_to_infix(exp);
                		break;
                	case 5:
                		
                		printf("Enter the exp: ");
                		scanf("%s", exp);
                		postfix_to_prefix(exp);
                		break;
                	case 6:
                		printf("Enter the exp: ");
                		scanf("%s", exp);
                		prefix_infix(exp);
                		break;
                	case 7:
                		
                		printf("Enter the exp: ");
                		scanf("%s", exp);
                		prefix_postfix(exp);
                		break;
			case 8:
				istrue = 0;
				break;
		}
    }
    return 0;
}
