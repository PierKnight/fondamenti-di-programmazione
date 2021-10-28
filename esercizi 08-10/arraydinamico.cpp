#include <iostream>
using namespace std;

#include "matrixHelper.h"



void resize(int*&,int&,const int);


//dimensione iniziale array e anche incremento di array
const int dim = 10;

int main()
{
	
	int val,capacity = dim,size = 0;
	
	//alloco un array di int di dimensione capacity
	int * array = new int[capacity];
	
	
	
	
	
	
	
	
	while(cin>>val)
	{
		//se size supera la capacità cambiare con un array più grande
		if(size >= capacity)	 
			resize(array,capacity,dim);
			
		array[size++] = val;
			
	}
	
	
	cout<<"LA SIZE DI QUESTO ARRAY= "<<size<<endl;
	
	return 0;
	
}



//int *& array sarebbe il puntatore del nostro array
void resize(int *& array,int & capacity,const int increase)
{
	
	//allochiamo nella memoria un nuovo array più grande
	int * temp = new int[capacity + increase];
	
	
	
	for(int i = 0;i < capacity;i++)
	{
		temp[i] = array[i];
	}
	
	delete [] array;
	
	array = temp;
	
	capacity += increase;
	
}