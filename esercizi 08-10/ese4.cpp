#include <iostream>
using namespace std;


const int size = 5;


void inputMatrix(int matrix[][size]);
void search(int matrix[][size]);
bool scanSubMatrix(int matrix[][size],const int i,const int j,const int dim);


int main()
{
	
	int matrix[size][size];
	
	inputMatrix(matrix);
	
	
	search(matrix);
	
	return 0;
}



void search(int matrix[][size])
{
	for(int dim = size;dim > 1;dim--)
	{
		for(int i = 0;i < size - dim;i++)
		{
			for(int j = 0;j < size - dim;j++)
			{
				if(scanSubMatrix(matrix,i,j,dim))
				{
					cout<<"Dimensione Massima Sottomatrice: "<<dim<<endl;
					cout<<"Coordinate del primo punto["<<i<<","<<j<<"]"<<endl;
					cout<<"Valore: "<<matrix[i][j]<<endl;
					
	
					return;
				}
			}
		
		}
	}
}


bool scanSubMatrix(int matrix[][size],const int i,const int j,const int dim)
{
	int number = matrix[i][j];
		
	for(int r = 0;r < dim;r++)
		for(int c = 0; c < dim;c++)
			if(matrix[i + r][j + c] != number)
				return false;
			
	return true;
}



void inputMatrix(int matrix[][size])
{
	for(int i = 0;i < size;i++)
		for(int j = 0;j < size;j++)
			cin>>matrix[i][j];
}

/*
1 2 3 4 5
2 2 2 3 1
2 2 2 4 5
2 2 2 1 3
3 4 1 5 6 
*/






