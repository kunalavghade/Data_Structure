#include <iostream>
using namespace std;

int main()
{
	int a[] = {1,5,6,7,8,9,10};
	int item = 10,k=3,n=7;
	
	cout << "The origional array elements \n";
	
	for(int i =0; i<n;i++)
		cout<<"a["<<i<<"] = "<<a[i]<<endl;
	
	n++;
	int j=n-1;
	while(j>=k)
	{
		a[j+1]=a[j];
		j--;
	}
	a[j] = item;
	cout <<"The array elements after insertion :\n";
	
	for(int i =0; i<n;i++)
		cout<<"a["<<i<<"] = "<<a[i]<<endl;
	
}