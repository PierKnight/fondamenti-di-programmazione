#include <iostream>
using namespace std;


int** fillMatrix(const int row,const int col);
bool esercizio(int** matrix1,int** matrix2,const int n,const int k);

int main()
{
	
	 int n,k;
	 
	 
	 cout<<"Inserire Dimensione n: "; 
	 cin>>n;
	 cout<<"Inserire Dimensione k: ";
	 
	 while(cin>>k && k >= n)
	 {
		 cout<<"Inserire Dimensione k (k minore di n): ";
	 }
		 
	 
	 
	
     int** matrixA = fillMatrix(n,n);
	 
	 int** matrixQ = fillMatrix(k,k);
	 
	 
	 
	 if(esercizio(matrixA,matrixQ,n,k))
		 cout<<"Esiste una sottomatrice simile!"<<endl;
	 else
		 cout<<"Non Esiste";
	
}


bool esercizio(int** matrix1,int** matrix2,const int n,const int k)
{
	
	int sommaK = 0;
	
	
	for(int i = 0;i < k;i++)
		sommaK += matrix2[i][i];
	
	//cout<<"Somma K"<< sommaK<<endl;
	
	bool trovato = false;
	
	//coordinate dell'eventuale sottomatrice simile
	int i;
	int j;
	
	for(i = 0;i < n - k + 1 && !trovato;i++)
	{
	    for(j = 0;j < n - k + 1 && !trovato;j++)
	    {					
	       //prova le varie sotto-matrici 
           int sommaSottoMatrice = 0;	
	
		   for(int e = 0;e < k;e++)
			   sommaSottoMatrice += matrix1[i + e][j + e];
		   
		    //cout<<"Somma Sottomatrice "<<sommaSottoMatrice<<endl;
	
		   if(sommaSottoMatrice == sommaK)
		      trovato = true;	   
		}
	}
	
	i--;
	j--;
	
	if(trovato)
	{
		for(int r = 0;r < k;r++)
		{
			for(int c = 0;c < k;c++)
			{
				matrix1[i + r][j + c] == matrix2[r][c];
			}
		
		}
		
		
		return true;
	}
	return false;
	
	
	
}



int** fillMatrix(const int row,const int col)
{
	
	int** matrix;
	
	matrix = new int*[row];
	
	for(int i = 0;i < row;i++)
	{
		matrix[i] = new int[col];
		for(int j = 0;j < col;j++)
			cin>>matrix[i][j];
	}
	
	return matrix;
			
}