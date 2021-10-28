#include <iostream>
using namespace std;



void resize(int*&,int&,const int);

const int dim = 10;

int main()
{
	
	int val,capacity = dim,size = 0;
	
	int * array = new int[capacity];
	
	
	
	
	
	
	while(cin>>val)
	{
		if(size >= capacity)	 
			resize(array,capacity,dim);
			
		array[size++] = val;
			
	}
	
	
	cout<<"LA SIZE DI QUESTO ARRAY= "<<size<<endl;
	
	return 0;
	
}


void resize(int *& array,int & capacity,const int increase)
{
	int * temp = new int[capacity + increase];
	
	for(int i = 0;i < capacity;i++)
	{
		temp[i] = array[i];
	}
	
	delete [] array;
	
	array = temp;
	
	capacity += increase;
	
}