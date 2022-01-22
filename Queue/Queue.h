#define MAX 6

int queue[MAX];
int front = 0;
int rear = -1;

int peek()
{
	return queue[front];
}

int isfull()
{
	return (rear == MAX-1)? 1 : 0 ;
}

int isempty()
{
	return ( front < 0 || front > rear )? 1 : 0;
}

int enqueue(int data)
{
	if(isfull())
		return 0;
	queue[++rear] = data;
	return 1;
}

int dequeue()
{
	if(isempty())
		return 0;
	return queue[front++];
}