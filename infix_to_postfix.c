
#include <stdio.h>
#include <ctype.h>
#define SIZE 100
char stack[SIZE];
int top = -1;

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

void push(char c)
{
    if (isFull() == 1)
    {
        printf("STACK IS FULL.");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = c;
    }
}

char pop()
{
    if (isEmpty() == 0)
    {
        char item = stack[top];
        top = top - 1;
        return item;
    }
    else
    {
        printf("STACK IS EMPTY.");
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
        printf("%c ", stack[i]);
    }
}


int icp (char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '^')
    {
        return 4;
    }
    if (c == '(')
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

int isp (char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void in_post(char inexp[])
{
    char postexp[SIZE];
    int k = 0;
    int i = 0;
    char tkn = inexp[i];
    while(tkn != '\0')
    {
        if (isalpha(tkn))
        {
            postexp[k] = inexp[i];
            k++;
        }
        else if (tkn == '(')
        {
            push('(');
        }
        else if (tkn == ')')
        {
            while((isEmpty() == 0) && (tkn = pop()) != '(')
            {
                postexp[k] = tkn;
                k++;
            }
        }
        else
        {
            while ((isEmpty() == 0) && (isp(stack[top]) >= icp(tkn)))
            {
                postexp[k] = pop();
                k++;
            }
            push(tkn);
        }
        i++;
        tkn = inexp[i];
    }

    while (isEmpty() == 0)
    {
        postexp[k] = pop();
        k++;
    }
    postexp[k] = '\0';
    printf("Postfix Expression: %s\n", postexp);
}

int main() 
{
    int istrue = 1;
    while (istrue == 1)
	{
		printf("Choose 1 for PUSH.\n");
		printf("Choose 2 for POP.\n");
		printf("Choose 3 for Displaying Stack.\n");
        printf("Choose 4 for Infix to Postfix.\n");
		printf("Choose 5 to EXIT..\n");
		printf("Enter choice: \n");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("Enter the character to be pushed: ");
				char temp;
				scanf(" %c", &temp);
				push(temp);
				printf("\n");
				break;
			case 2:
                char c;
				c = pop();
                printf("Popped character: %c", c);
				printf("\n");
				break;
			case 3:
				display();
				printf("\n");
				break;
            case 4:
                char expr[SIZE];
                printf("Enter Infix Expression: ");
                scanf("%s", expr);
				in_post(expr);
				break;
			case 5:
				istrue = 0;
				break;
		}
    }
    return 0;
}