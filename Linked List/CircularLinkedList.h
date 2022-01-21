#include <iostream>
using namespace std;

struct Node
{
	int data;
	int key;
	Node *next =NULL;
};

Node *head = NULL;

void insertFirst(int key, int data)
{
	Node *link = new Node;
	link->key = key;
	link->data = data;
	
	if(head == NULL)
	{
		head = link;
		head->next = head;
	}
	else
	{
		link->next = head;
		head = link;
	}
}

Node *deleteFirst()
{
	Node *tmp = head;
	
	if(head->next == head)
	{
		head = NULL;
		return tmp;
	}
	head = head->next;
	return tmp;
}

int lenght()
{
	Node *tmp = head;
	int l = 0;
	
	if(head == NULL)
		return 0;
	
	while(tmp->next != head)
	{
		l++;
		tmp = tmp->next;
	}
	
	return l;
}

bool isEmpty()
{
	return head == NULL;
}

void printList()
{
	Node *tmp = head->next;
	
	cout<<"\n[ ";
	if(head!=NULL)
	{
		while(tmp->next != tmp)
		{
			cout<<"("<<tmp->key<<","<<tmp->data<<") ";
			tmp =tmp->next;
		}
		cout<<"]\n";
	}
}