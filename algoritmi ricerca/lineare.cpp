#include <iostream>
using namespace std;


bool search(const int array[],const int size,const int value);

int main()
{
	
	int size = 7;
	
	int array[] = {1,2,3,5,1,12,3};
	
	int val;
	
	cin>>val;
	
	
	if(search(array,size,val))
		cout<<"Il valore è presente";
	else
		cout<<"Il valore non è presente";
	
	
	return 0;
	
	
}

bool search(const int array[],const int size,const int value)
{
	for(int i = 0;i < size;i++)
		if(array[i] == value)
			return true;
	return false;
}