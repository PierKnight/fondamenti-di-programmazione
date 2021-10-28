#include <iostream>
using namespace std;


const int dim = 10;

int readArray(int array[]);
bool binary(const int array[],const int from,const int to,const int val);

int main()
{
	
	
	
	//lista ordinata
	int array[dim];
	int size = readArray(array);
	
	int val;
	
	cin>>val;
	
	
	if(binary(array,0,size,val))
		cout<<"Il valore e' presente";
	else
		cout<<"Il valore non e' presente";
	
	
	return 0;
	
	
}



//ritorna la grandezza dell'array letto (massimo dim)
int readArray(int array[])
{
	
	
	int i = 0;
	int val;
	cin>>val;
	
	
	while(val != -1 && i < dim)
	{
		array[i++] = val;
		cin>>val;
    }
	return i;
		
}

//consiste in una ricorsione dove si ha un array da index from a index to
//dopo si prende la metà dell'array contenente il valore ricercato
//e si chiama la stessa funzione su quell sotto-array

//ATTENZIONE il prerequisito è che la lista sia già ordinata!

bool binary(const int array[],const int from,const int to,const int val)
{
	
	
	if(from >= to)
		return array[from] == val;
		
	int medium = (from + to) /  2;
	
	if(val > array[medium])
		return binary(array,medium + 1,to,val);
    else
	    return binary(array,from,medium,val);
	
	
	
}