#include <iostream>
using namespace std;

void printLine(int count)
{
	for(int i = 0; i < count-1; i++ )
		cout << "=";
	cout <<endl;
}

int find(int data[],int key,int n)
{
	int comparisons = 0;
	
	for(int i = 0; i< n; i++)
	{
		if(data[i] == key)
			return i;
	}
	return -1;
}

void display(int arr[],int n)
{
	cout<<"[";
	for(int i = 0; i < n; i++ )
		cout<<arr[i]<<" ";
	cout<<"]\n";
}

int main()
{
	int MAX = 20;
	int arr[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
	cout<<"\nInput Array: ";
	display(arr,MAX);
	printLine(70);
	int loc = find(arr,43,MAX);
	if(loc != -1)
		cout<<"\nTotal comparisons made: "<< loc << "\nElement found at location: "<<loc<<endl;
	else
		cout<<"\nElement not found\n";
}