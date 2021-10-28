#include <iostream>
using namespace std;

int** fillMatrix(const int row,const int col);
int** createMatrix(const int row,const int col,const int val);
int** createVector(const int dim,const int val);
void printMatrix(int** matrix,const int row,const int col);

void sumMatrix(int** matrix1,int** matrix2,const int row,const int col);
int** prodMatrix(int** matrix1,int** matrix2,const int row,const int col);




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

//il casino comincia
int** createMatrix(const int row,const int col,const int val)
{
	int** matrix;
	
	matrix = new int*[row];
	
	for(int i = 0;i < row;i++)
	{
		matrix[i] = new int[col];
		for(int j = 0;j < col;j++)
			matrix[i][j] = val;
	}
	
	return matrix;
}

int** createVector(const int dim,const int val)
{
	return createMatrix(dim,1,val);
}

int** i3Matrix(const int row,const int col)
{
	return createMatrix(3,3,0);
}

//puoi usare anche numeri negativi
void sumMatrix(int** matrix1,int** matrix2,const int row,const int col)
{
	for(int i = 0;i < row;i++)
		for(int j = 0;j < col;j++)
			matrix1[i][j] += matrix2[i][j];
}

void printMatrix(int** matrix,const int row,const int col)
{
		
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
}

int** prodMatrix(int** matrix1,int** matrix2,const int row,const int col)
{
		
	int** newMatrix = createMatrix(row,col,0);	
		
	for(int j = 0;j < col;j++)
	{
	 for(int i = 0;i < row;i++)
	 {
		 int sum = matrix2[i][j] * matrix1[j][i];
		 newMatrix[i][j] = sum;
	 }
	}
	return newMatrix;
}


