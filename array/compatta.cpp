#include <iostream>
using namespace std;



void leggiArray(int array[],int& dim);
void printArray(int array[],int& dim);
void compatta(int array[],int& dim);

int main()
{
	
	int dim = 100;
	int numeri[dim];
	leggiArray(numeri,dim);
	
	compatta(numeri,dim);
	
	printArray(numeri,dim);
	
	
	return 0;
	
	
}


void leggiArray(int array[],int& dim)
{
	int val;
		
	int size = 0;
	
	
	
	while(cin>>val && val != -1 && size < dim)
	{
		array[size++] = val;
		
	}
	
	dim = size;
    
	
}

void printArray(int array[],int& dim)
{
	for(int i = 0;i < dim;i++)
		cout<<array[i]<<"\t";
	
	cout<<endl;
}
void compatta(int array[],int& dim)
{
	
	for(int i = 0;i < dim;i++)
	{
		
         int j = i + 1;
		 
		 while(j < dim)
		 {
	  
	        if(array[i] == array[j])
			{
			  for(int k = j;k < dim - 1;k++)
	          {
				array[k] = array[k + 1];
			  }
			  
			  dim--;
			}
			else
			 j++;
		 }  
	   
	}
}

