#include <iostream>
using namespace std;

int BinSearch(int arr[],int key,int n)
{
	int low = 1; 
	int high = n;
	int mid,index =-1;
	int compare = 0;
	while(low <= high)
	{
		compare++;
		if(high<low)
			index = -1;
		
		mid = low + (high -low)/2;
		
		if (arr[mid] == key)
		{	
			index = mid;
			break;
		}
			
		if( arr[mid] < key )
			low = ++mid;

		if( arr[mid] > key )
			high = --mid;		
	}
	cout<<"\nTotal comparisons made:"<<compare<<endl;
	return index;
}

void printLine(int count)
{
	for(int i = 0; i < count-1; i++ )
		cout << "=";
	cout <<endl;
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
	int loc = BinSearch(arr,43,MAX);
	if(loc != -1)
		cout<<"\nElement found at location: "<<loc<<endl;
	else
		cout<<"\nElement not found\n";
}