#include <iostream>
using namespace std;



// 9 6 3 8 0 7 2 1 4 5

//inserire il valore a sinistra facendo spazio e mettendolo nel posto giusto
void printArray(int array[],int size);
void mergeSorting(int array[],int start,int end);
void merge(int A[],int sizeA,int B[],int sizeB,int array[]);

int main()
{
	
	int size = 7;
	
	int array[] = {1,2,6,1,1,12,3};
	
	int array1[] = {1,2,6};
	int array2[] = {5,11,15};
	
	
	
	//mergeSorting(array,0,size);
	
	
	
	int output[6];
	
	merge(array1,3,array2,3,output);
	
	printArray(output,6);

	
	return 0;
}


void printArray(int array[],int size)
{
	for(int i = 0;i < size;i++)
		cout<<array[i]<<"\t"<<endl;
}

//divide l'array in due sotto array, poi riordini i due sottoarray, e poi li unisci assieme (merge)
void mergeSorting(int array[],int start,int end)
{
	
	
}


//unisci due array ordinati per crearne uno ordinato a sua volta.
void merge(int V[],int start,int fin,int medio)
{
	
	int support[fin - start];
	
	
	int i = start;
	int j = medio + 1;
	
	int size = 0;
	
	while(i <= sizeA && j <= sizeB)
	{
		
	  if(A[i] < B[j])
	  {  
		support[size] = V[i];
	 	i++;
	  }
	  else
	  {
		support[size] = V[j];
	 	j++;
	  }	  
	  size++;
	}
	
	
	while(i <= sizeA)
	{
		array[size] = V[i];
		size++;
		i++;
	}
	
	while(j <= sizeB)
	{
		array[size] = V[j];
		size++;
		j++
	}
	
	for(int i = 0;i < size;i++)
		V[start + i] = support[i];
	
	
	
	
}