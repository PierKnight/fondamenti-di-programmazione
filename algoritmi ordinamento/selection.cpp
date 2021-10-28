#include <iostream>
using namespace std;



// 9 6 3 8 0 7 2 1 4 5

void printArray(int array[],int size);
void selection(int array[],int size);

int main()
{
	
	int size = 7;
	
	int array[] = {1,2,6,1,1,12,3};
	
	
	selection(array,size);
	
	
	printArray(array,size);

	
	return 0;
}


void printArray(int array[],int size)
{
	for(int i = 0;i < size;i++)
		cout<<array[i]<<"\t"<<endl;
}

//cerca il minimo e lo mette dell'array ad indice i e si scambia
void selection(int array[],int size)
{
	
	for(int i = 0;i < size - 1;i++)
	{
		int minIndex = i;
		
		for(int j = i + 1;j < size;j++)
		{
			if(array[j] < array[minIndex])
				minIndex = j;
		}
		
		int temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}
	
}