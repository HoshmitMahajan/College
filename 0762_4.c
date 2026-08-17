#include <stdio.h>
#include <string.h>
struct job
{
	int jobid;
	char title[20];
};

#define SIZE 5
int front = 0;
int rear = 0;
struct job queue[SIZE];

int isFull()
{
	if (((rear + 1) % SIZE) == front)
	{
		return 1;
	}
	else return 0;
}

void enqueue(struct job element)
{
	if (isFull()==1)
	{
		printf("Queue is full.\n");
		return;
	}
	else
	{
		rear = (rear + 1) % SIZE;
		queue[rear] = element;
	}
}


int isEmpty()
{
	if (rear == front)
	{
		return 1;
	}
	else return 0;
}

void dequeue()
{
	if (isEmpty()==1)
	{
		printf("Queue is empty.\n");
		return;
	}
	else
	{
		front = (front + 1) % SIZE;
		printf("Removed element: [%d %s]", queue[front].jobid, queue[front].title);
	}
}

void display()
{
	if (isEmpty())
	{
		printf("Queue is empty.\n");
		return;
	}
	else if (front < rear)
	{
		for (int i = front+1; i <= rear; i++)
		{
			printf(" [%d %s] ", queue[i].jobid, queue[i].title);
		}
	}
	else
	{
		for (int i = front+1; i < SIZE; i++)
		{
			printf(" [%d %s] ", queue[i].jobid, queue[i].title);
		}
		for (int i = 0; i <=rear; i++)
		{
			printf(" [%d %s] ", queue[i].jobid, queue[i].title);
		}
	}
	
}


int main()
{
	int istrue=1;
	while(istrue == 1)
	{
		printf("Choose 1 for Enqueue.\n");
		printf("Choose 2 for Dequeue. (non rec)\n");
		printf("Choose 3 for Displaying Queue. (rec)\n");
		printf("Choose 4 to EXIT..\n");
		printf("Enter choice: \n");
		int choice;
		int temp;
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("Enter the Job ID and Title: ");
				struct job temp;
				scanf("%d %s", &temp.jobid, temp.title);
				enqueue(temp);
				printf("\n");
				break;
			case 2:
				dequeue();
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
	
	
}
