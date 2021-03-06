#include <stdio.h>
#include <conio.h>
#include <time.h>
#define MAX 10 // Changing this value will change length of array
int queue[MAX];
int front = -1, rear = -1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);
int count(void);
void insert_random(void);
int main()
{
	int option, val;
	srand(time(NULL));
	do
	{
		printf("\n\n * ****MAIN MENU * ****");
		printf("\n 1. Insert an element");
		printf("\n 2. Delete an element");
		printf("\n 3. Peek");
		printf("\n 4. Display the queue");
		printf("\n 5. EXIT");
		printf("\n 6. calculate the number of items");
		printf("\n 7. Creat Full elements Randomly.");
		printf("\n Enter your option : ");
		scanf(" %d", &option);
		switch (option)
		{
		case 1:
			insert();
			break;
		case 2:
			val = delete_element();
			if (val != -1)
				printf("\n The number deleted is : % d", val);
			break;
		case 3:
			val = peek();
			if (val != -1)
				printf("\n The first value in queue is : % d", val);
			break;
		case 4:
			display();
			break;
		case 6:
			val=count();
			if(val!=-1)
				printf("\n The number of items is %d", val);
			break;
		case 7:
			insert_random();
			break;
		}
	} while (option != 5);
	getch();
	return 0;
}
void insert()
{
	int num;
	printf("\n Enter the number to be inserted in the queue : ");
	scanf(" %d", &num);
	if (rear == MAX - 1)
		printf("\n OVERFLOW");
	else if (front == -1 && rear == -1) {
		front = 0;
		rear = 0;
	}
	else
		rear++;
	queue[rear] = num;
}
int delete_element()
{
	int val;
	if (front == -1 || front > rear)
	{
		printf("\n UNDERFLOW");
		return -1;
	}
	else
	{
		val = queue[front];
		front++;
		if (front > rear) {
			front = -1;
			rear = -1;
		}
		return val;
	}
}
int peek()
{
	if (front == -1 || front > rear)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
	{
		return queue[front];
	}
}
void display()
{
	int i;
	printf("\n");
	if (front == -1 || front > rear)
		printf("\n QUEUE IS EMPTY");
	else
	{
		for (i = front; i <= rear; i++)
			printf("\t % d", queue[i]);
	}
}
int count()
{
	if (rear > -1 && front > -1)
		return rear - front+1;
	else
		return -1;
}
void insert_random()
{
	while (rear != MAX - 1) {
		if (rear == MAX - 1)
			printf("\n OVERFLOW");
		else if (front == -1 && rear == -1) {
			front = 0;
			rear = 0;
		}
		else
			rear++;
		queue[rear] = rand();

}
}