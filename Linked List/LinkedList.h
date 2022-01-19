#include <iostream>
using namespace std;

struct node
{
	int data;
	int key;
	node *next;
};

node* head = NULL;

void printList()
{
	node *ptr = head;
	cout<<endl<<"[ ";
	
	// start from beging
	while(ptr !=  NULL)
	{
		cout<<"("<<ptr->key<<","<<ptr->data<<") ";
		ptr = ptr->next;
	}
	cout<<"]"<<endl;
}

void insertFirst(int key,int data)
{
	// create link 
	node *link = new node;
	link->key = key;
	link->data = data;
	
	// point it to old first node
	link->next = head;
	
	// point head to link
	head =  link;
}

node *deleteFirst()
{
	// Save reference to first link 
	struct node *tmp = head;
	
	// mark next to first to links first
	head = head->next;
	
	//return deleted link
	return tmp;
}

bool isEmpty()
{
	return head == NULL;
}

int length()
{
	node *tmp = head;
	int length = 0;
	while(tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}
	return length;
}

// find a link with given key
node *find(int key)
{
	node *tmp = head;
	
	// if List is empty
	if(head == NULL)
		return NULL;
	
	// navigate through List
	while(tmp->key != key)
	{
		if(tmp->next == NULL)
			return NULL;
		else
			tmp = tmp->next;
	}
	return tmp;
}

// delete at given node
node *deleteAt(int key)
{
	// start from first link
	node *current = head;
	node *previous = NULL;
	
	// chacke if List is empty
	if(head == NULL)
		return NULL;
	
	// navigate through list
	while(current->key != key)
	{
		if(current->next == NULL)
			return NULL;
		else
		{
			previous =  current;
			current = current->next;
		}
	}
	
	// found match then update list
	if(current == head)
		head = head->next;
	else
		previous->next = current->next;
	return current;
}

void sort()
{
	int key,data;
	node *current, *next;
	int size = length();
	for(int i = 0, k = size ; i < size; i++)
	{
		current =  head;
		next =  head->next;
		
		for(int j = 1; j < k; j++)
		{
			if(current->data > next->data)
			{
				data = current->data;
				current->data = next->data;
				next->data =  data;
				
				key  = current->key;
				current->key = next->key;
				next->key = key; 
			}
			
			current =  current->next;
			next =  next->next;
		}
	}
}

void reverse()
{
	node *previous =  NULL;
	node *current = head;
	node *next;
	
	while(current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}