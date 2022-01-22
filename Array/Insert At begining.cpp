#include <iostream>
using namespace std;

int main()
{
	int a[] ={2, 3, 4, 5}; 
	int n = 4;
	int item =1;
	
	cout << "The origional array elements are: \n";
	for(int i = 0; i< n; i++)
		cout<<"a["<<i<<"] = "<<a[i]<<endl;
	
	n++;
	for(int i = n; i > 0; i--)
		a[i+1] = a[i];
	
	a[0] = item;

	cout << "The array elements after insertion :\n";
	for(int i = 0; i< n; i++)
		cout<<"a["<<i<<"] = "<<a[i]<<endl;
	
	return 0;
}