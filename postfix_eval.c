#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

int stk[SIZE];

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

void push(int c)
{
    if (isFull() == 1)
    {
        printf("STACK IS FULL.");
        return;
    }
    else
    {
        top = top + 1;
        stk[top] = c;
    }
}

int pop()
{
    if (isEmpty() == 0)
    {
        int item = stk[top];
        top = top - 1;
        printf("Popped Item: %d\n", item);
        return item;
    }
    else
    {
        printf("STACK IS EMPTY.");
        return 0;
    }
}

int calc(int a, int b, char op)
{
	int ans = 0;
	switch (op)
	{
		case '+':
			ans = a+b;
			break;
		case '-':
			ans = a-b;
			break;
		case '*':
			ans = a*b;
			break;
		case '/':
			ans = a/b;
			break;
		
	}
	return ans;
}

void postfix_eval(char post[SIZE])
{
	for (int i = 0; post[i] != '\0'; i++)
	{
		if (isalpha(post[i])!=0)
		{
			printf("Enter the number %c: ", post[i]);
			int z;
			scanf("%d", &z);
			push(z);
		}
		else
		{
			int op2 = pop();
			int op1 = pop();
			int ans = calc(op1, op2, post[i]);
			push(ans);
		}
	}
	printf("\nResult is: %d\n", stk[top]);
}

void prefix_eval(char post[SIZE])
{
	int length = strlen(post);
	for (int i = length-1; i >= 0; i--)
	{
		if (isalpha(post[i])!=0)
		{
			printf("Enter the number %c: ", post[i]);
			int z;
			scanf("%d", &z);
			push(z);
		}
		else
		{
			int op2 = pop();
			int op1 = pop();
			int ans = calc(op1, op2, post[i]);
			push(ans);
		}
	}
	printf("\nResult is: %d\n", stk[top]);
}

	

int main()
{
	printf("Enter prefix exp: ");
	char exp[20];
	scanf("%s", exp);
	prefix_eval(exp);

}	
