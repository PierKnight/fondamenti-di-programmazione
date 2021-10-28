#include <iostream>
using namespace std;



// 9 6 3 8 0 7 2 1 4 5

//ordinare prendendo due a due e scambiando
//ad ogni ciclo il valore più grande viene spostato a destra

void printArray(int array[],int size);
void bubble(int array[],int size);

int main()
{
	
	int size = 7;
	
	int array[] = {1,2,6,1,1,12,3};
	
	
	bubble(array,size);
	
	
	printArray(array,size);

	
	return 0;
}


void printArray(int array[],int size)
{
	for(int i = 0;i < size;i++)
		cout<<array[i]<<"\t"<<endl;
}


void bubble(int array[],int size)
{
	bool scambio = false;
	
	
	do
	{
    	for(int i = 0;i < size - 1;i++)
	    {
		
		//controllo se il primo valore della coppia è più grande del secondo valore
		//se si scambiare i due valori
		//cosi ci portiamo a presso il valore più grande alla sua effettiva posizione 
		if(array[i] > array[i + 1])
		{
			//scambio		
			int temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;					
			scambio = true;
					
		}		
	   }   
	   size--;
	}
	while(scambio && size >= 1);
}