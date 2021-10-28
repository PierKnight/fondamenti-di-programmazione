#include <iostream>
using namespace std;


const int n = 2;

void fillMatrix(int matrix[][n]);
void esercizio1(int matrix1[][n],int matrix2[][n],int vettore[]);




int main()
{
	
	 int matrix1[n][n],matrix2[n][n];
	 
	 fillMatrix(matrix1);
	 fillMatrix(matrix2);
	
     int vettore[n];
	 	 
	 esercizio1(matrix1,matrix2,vettore);
	 	 
	 for(int i = 0;i < n;i++)
		 cout<<vettore[i]<<"\t";
	 return 0;
	
}


void esercizio1(int matrix1[][n],int matrix2[][n],int vettore[])
{
	//j sono le colonne
	
	for(int j = 0;j < n;j++)
	{
		int elementiComuni = 0;
		
		for(int s = 0;s < n;s++)
	    {
			for(int t = 0;t < n;t++)
	         	if(matrix1[s][j] == matrix2[t][j])
					elementiComuni++;
		}
		
		vettore[j] = elementiComuni;		
	}
}


void fillMatrix(int matrix[][n])
{
	
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			cin>>matrix[i][j];
    }
			
}
