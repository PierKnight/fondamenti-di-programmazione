#include <iostream>
using namespace std;

//data una matrice determinare se tutte le coppie di righe hanno almeno un elemento in comune


const int row = 3;
const int col = 3;

bool f(const int matrix[][col],const int row,const int col);
bool contieneNumero(const int array[],const int size,const int numero);
void riempiMatrice(int matrix[][col],const int row,const int col);
void stampaMatrice(const int matrix[][col],const int row,const int col);


int main()
{
	
	
	int matrix[row][col];
	
	riempiMatrice(matrix,row,col);
	
	stampaMatrice(matrix,row,col);
	
	if(f(matrix,row,col))
		cout<<"YES!!!!!"<<endl;
	
	
	
	
	return 0;
	
	
}


void riempiMatrice(int matrix[][col],const int row,const int col)
{
	for(int i = 0;i < row;i++)
	{
	   for(int j = 0;j < col;j++)
		   cin>>matrix[i][j];
	  
	}
}

void stampaMatrice(const int matrix[][col],const int row,const int col)
{
	for(int i = 0;i < row;i++)
	{	 
	   for(int j = 0;j < col;j++)
		   cout<<matrix[i][j]<<"\t";
	   
	   cout<<endl;
	     
	}
}

bool f(const int matrix[][col],const int row,const int col)
{
	for(int r1 = 0;r1 < row - 1;r1++)
	{
	
		for(int r2 = r1 + 1;r2 < row;r2++)
		{
	
	        bool contiene = false;
	
			for(int j = 0;j < col && !contiene;j++)
		    {
				if(contieneNumero(matrix[r2],col,matrix[r1][j]))
					contiene = true;
				
			}
			if(!contiene)
				return false;
			
		}	
	}
	
	return true;
	
}

bool contieneNumero(const int array[],const int size,const int numero)
{
	for(int i = 0;i < size;i++)
		if(array[i] == numero)
			return true;
		
	return false;
}