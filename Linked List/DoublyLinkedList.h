#include <iostream>
using namespace std;

// define Doubly Node Structure
struct Node
{
	int data;
	int key;
	
	Node *next=NULL;
	Node *prev=NULL;
};

// Create Global pointer
Node *head = NULL;
Node *last = NULL;

// insert node at first
 void insertFirst(int key, int data)
 {
	 // create Node
	 Node *link =  new Node;
	 link->key = key;
	 link->data = data;
	 if(head == NULL)
	 {
		// create last link
		last = link;
	 }
	 else
	 {
		// update first prev link
		head->prev = link;
	 }
	 // point to old first
	 link->next = head;
	 // point first by head
	 head = link;
 }
 
 // insert at last
 void insertLast(int key, int data)
 {
	 Node *link = new Node;
	 link->key = key;
	 link->data = data;
	 
	 if(head==NULL)
	 {
		 // make it last link
		 last = link;
	 }
	 else
	 {
		 // make link a new last link
		 last->next = link;
		 // mark old last node as prev of new link
		 last->prev = last;
	 }
	 last = link;
 }
 
 void displayForward()
 {
	 Node *tmp = head;
	 cout<<"\n[ ";
	 while(tmp != NULL)
	 {
		 cout<<"("<<tmp->key<<","<<tmp->data<<") ";
		 tmp = tmp->next;
	 }
	 cout<<"]\n";
 }

 void displayBackward()
 {
	 Node *tmp = last;
	 cout<<"\n[ ";
	 while(tmp != NULL)
	 {
		 cout<<"("<<tmp->key<<","<<tmp->data<<") ";
		 tmp = tmp->prev;
	 }
	 cout<<"]\n";	 
 }
 
 Node *deleteFirst()
 {
	 Node *tmp = head;
	 
	 if(head->next == NULL)
		 last = NULL;
	 else
		 head->next->prev = NULL;
	 head = head->next;
	 return tmp;
 }
 
 Node *deleteLast()
 {
	 Node *tmp = last;
	 if(head->next == NULL)
		 head = NULL;
	 else
		 last->prev->next = NULL;
	 last = last->prev;
	 return tmp;
 }
 
 Node *deleteAt(int key)
 {
	 Node *current = head;
	 Node *previos = NULL;
	 
	 if(head == NULL)
		 return NULL;
	 
	 while(current->key != key)
	 {
		if(current->next == NULL)
			return NULL;
		else
		{
			previos = current;
			current = current->next;
		}
	 }
	 
	 if(current == head)
		 head = head->next;
	 else
		 current->prev->next = current->next;
	 
	 if(current == last)
		 last = current->prev;
	 else
		 current->next->prev = current->prev;
	 
	 return current;
 }
 
 bool isEmpty()
 {
	 return head == NULL;
 }
 
 int length()
 {
	 Node *tmp = head;
	 int length;
	 while(tmp!=NULL)
	 {
		 length++;
		 tmp = tmp->next;
	 }
	 return length;
 }
 
 bool insertAfter(int key, int newKey, int data)
 {
	Node *tmp = head; 
	
	if(head == NULL)
		return false;
	
	while(tmp->key != key)
	{
		if(tmp->next == NULL)
			return false;
		else
			tmp = tmp->next;
	}
	
	Node *link = new Node;
	link->key = newKey;
	link->data = data;
	
	if(tmp == last)
	{
		link->next = NULL;
		last = link;
	}
	else
	{
		link->next = tmp->next;
		tmp->next->prev = link;	// connect next Nodes prev
	}
	
	link->prev = tmp;
	tmp->next = link;
	return true;
 }