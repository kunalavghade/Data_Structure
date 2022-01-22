#include <stdio.h>

int MAXSIZE = 8;
int stack[25];
int top =-1;

int isEmpty()
{
	return (top == - 1) ? 1 : 0 ;
}

int isFull()
{
	return (top == MAXSIZE) ? 1 : 0 ;
}

int peek()
{
	return stack[top];
}

void push(int data)
{
	if(!isFull())
	{
		stack[++top] = data;
	}
	else
	{
		printf("Stack is Full !, Data can't be added\n");
	}
}

int pop()
{
	if(!isEmpty())
	{
		return stack[top--];
	}
	else
	{
		printf("Stack is Empty !\n");
	}
	return -1;
}