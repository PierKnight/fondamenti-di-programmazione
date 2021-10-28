#include <iostream>
using namespace std;



// 9 6 3 8 0 7 2 1 4 5

//inserire il valore a sinistra facendo spazio e mettendolo nel posto giusto
void printArray(int array[],int size);
void insertion(int array[],int size);

int main()
{
	
	int size = 7;
	
	int array[] = {1,2,6,1,1,12,3};
	
	
	insertion(array,size);
	
	
	printArray(array,size);

	
	return 0;
}


void printArray(int array[],int size)
{
	for(int i = 0;i < size;i++)
		cout<<array[i]<<"\t"<<endl;
}

//cerca il minimo e lo mette dell'array ad indice i e si scambia
void insertion(int array[],int size)
{
	
	for(int i = 1;i < size;i++)
	{
		int value = array[i];
		int index = i - 1;
		while(index >= 0 && array[index] > value)
		{		
	        array[index + 1] = array[index];
			index--;
		}
		
		array[index + 1] = value;
		
	}
	
}