#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
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
		top += 1;
		stack[top] = data;
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
		top -= 1;
		return stack[top+1];
	}
	else
	{
		printf("Stack is Empty !\n");
	}
	return -1;
}