#include <stdio.h>
#include <string.h>
# define SIZE 5
struct job
{
	int jobid;
	char title[20];
};

int isFull(int *rear, int *front)
{
	if (((*rear + 1) % SIZE) == *front)
	{
		return 1;
	}
	else return 0;
}

void enqueue(struct job queue[], struct job element, int *rear, int *front)
{
		*rear = (*rear + 1) % SIZE;
		queue[*rear] = element;
}

int isEmpty(int *rear, int *front)
{
	if (*rear == *front)
	{
		return 1;
	}
	else return 0;
}

void dequeue(struct job queue[], int *rear, int *front)
{
		*front = (*front + 1) % SIZE;
		printf("Removed element: [%d %s]", queue[*front].jobid, queue[*front].title);
}

void display(struct job queue[], int rear, int front)
{
	if (front == rear)
	{
		printf("Queue is empty.\n");
		return;
	}
	for (int i = (front+1); i != (rear); i++)
	{
		if (i != (SIZE))
		{
			printf(" [%d %s] ", queue[i].jobid, queue[i].title);
		}
		else
		{
			i = -1;
		}
	}
}

int main()
{
	int front = 0;
	int rear = 0;
	struct job queue[SIZE];
	
	int istrue = 1;
	while (istrue == 1)
	{
		printf("Choose 1 for Enqueue.\n");
		printf("Choose 2 for Dequeue.\n");
		printf("Choose 3 for Displaying Queue.\n");
		printf("Choose 4 to EXIT..\n");
		printf("Enter choice: \n");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				if (isFull(&rear, &front) == 1)
				{
					printf("Queue is full.\n");
					break;
				}
				printf("Enter the Job ID and Title: ");
				struct job temp;
				scanf("%d %s", &temp.jobid, temp.title);
				enqueue(queue, temp, &rear, &front);
				printf("\n");
				break;
			case 2:
				if (isEmpty(&rear, &front) == 1)
				{
					printf("Queue is empty.\n");
					break;
				}
				dequeue(queue, &rear, &front);
				printf("\n");
				break;
			case 3:
				display(queue, rear, front);
				printf("\n");
				break;
			case 4:
				istrue = 0;
				break;
		}
	}
	return 0;
}
