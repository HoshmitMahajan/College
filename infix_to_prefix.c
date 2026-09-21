
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
        return ' ';
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
        return 3;
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
        return 4;
    }
    else
    {
        return 0;
    }
}

void in_pre(char inexp[])
{
    char postexp[SIZE];
    
    int left = 0;
    int right = strlen(inexp) - 1; 
    char temp;


    while (left < right) {
        temp = inexp[left];
        inexp[left] = inexp[right];
        inexp[right] = temp;

        left++;
        right--;
    }
    
    
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
        else if (tkn == ')')
        {
            push(')');
        }
        else if (tkn == '(')
        {
            while((isEmpty() == 0) && (tkn = pop()) != ')')
            {
                postexp[k] = tkn;
                k++;
            }
        }
        else
        {
            while ((isEmpty() == 0) && (isp(stack[top]) > icp(tkn)))
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
    printf("Prefix Exp: ");
    for (int i = (strlen(postexp)-1); i >= 0 ; i--)
    {
    	printf("%c", postexp[i]);
    }
    printf("\n");
}




int main() 
{
    int istrue = 1;
    while (istrue == 1)
	{
		printf("Choose 1 for PUSH.\n");
		printf("Choose 2 for POP.\n");
		printf("Choose 3 for Displaying Stack.\n");
        printf("Choose 4 for Infix to Prefix.\n");
		printf("Choose 5 to EXIT..\n");
		printf("Enter choice: \n");
		int choice;
		scanf("%d", &choice);
		char expr[SIZE];
		 char c;
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
               
				c = pop();
                printf("Popped character: %c", c);
				printf("\n");
				break;
			case 3:
				display();
				printf("\n");
				break;
            case 4:
                
                printf("Enter Infix Expression: ");
                scanf("%s", expr);
				in_pre(expr);
				break;
                
			case 5:
				istrue = 0;
				break;
		}
    }
    return 0;
}
