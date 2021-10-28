#include <iostream>
using namespace std;


const int n = 2;

void fillMatrix(int matrix[][n]);
bool sella(int matrix[][n]);
bool puntoSella(int matrix[][n],const int r,const int c);




int main()
{
	
	 int matrix[n][n];
	 
	 fillMatrix(matrix);
	
	
	
	if(sella(matrix))
		cout<<"HA UN PUNTO SELLA"<<endl;
   
	 return 0;
	
}


bool puntoSella(int matrix[][n],const int r,const int c)
{
	 int max = matrix[0][c];
	 int min = matrix[r][0];
	 
	 for(int s = 1;s < n;s++)
	 {
		 if(matrix[r][s] < min)
	     {
			 min = matrix[r][s];
		 }
		 if(matrix[s][c] > max)
		 {
			max = matrix[s][c];
             			
		 }
	 }
	 
	 return max == matrix[r][c] && min == matrix[r][c];
}

bool sella(int matrix[][n])
{	
	
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(puntoSella(matrix,i,j))
				return true;
		}
	}
	
	return false;
}



void fillMatrix(int matrix[][n])
{
	
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			cin>>matrix[i][j];
    }
			
}

//1 1 3 5 4 3
  1 1 3 2 2 1
  235
