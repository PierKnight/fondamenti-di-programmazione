#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <assert.h>

class Matrix
{
    protected:
    double** mat;
    int rows;
    int cols;

    public:
    Matrix(int _rows,int _cols,double init);
    Matrix(const Matrix&);
    ~Matrix();

    void readFromInput();
    void readFromArray(int values[]);

    double getRows() const {return rows;}
    double getCols() const {return cols;}

    void print() const;
    double det() const;



    Matrix transpose();
    Matrix ADJ();
    bool inverse(Matrix& inv);

    Matrix operator=(const Matrix& other);
    double& operator()(int,int);
    const double operator()(int,int) const;

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator*(double);
   

};

Matrix::Matrix(int _rows,int _cols,double init)
{
    rows = _rows;
    cols = _cols;

    mat = new double*[rows];

    for(int i = 0;i < rows;i++)
    {
       mat[i] = new double[cols];
       for(int j = 0;j < cols;j++)
           mat[i][j] = init;
    }
     
}

Matrix::Matrix(const Matrix& m)
{
    rows = m.rows;
    cols = m.cols;

    mat = new double*[rows];

    for(int i = 0;i < rows;i++)
    {
       mat[i] = new double[cols];
       for(int j = 0;j < cols;j++)
           mat[i][j] = m.mat[i][j];
    }
}

Matrix::~Matrix()
{
    for(int i = 0;i < rows;i++)
        delete [] mat[i];
}

void Matrix::readFromInput()
{
    double val;
    for(int i = 0;i < rows;i++)
        for(int j = 0;j < cols;j++)
        {
            std::cin>>mat[i][j];
        }

}

void Matrix::print() const
{
    for(int i = 0;i < rows;i++)
    {
       for(int j = 0;j < cols;j++)
          std::cout<<(*this)(i,j)<<" ";
       std::cout<<std::endl;
    }
}

void Matrix::readFromArray(int values[])
{
    int c = 0;
    for(int i = 0;i < rows;i++)
    {
       for(int j = 0;j < cols;j++)
          (*this)(i,j) = values[c++];
    }
}

Matrix Matrix::operator=(const Matrix& other)
{
    for(int i = 0;i < rows;i++)
       for(int j = 0;j < cols;j++)
           mat[i][j] = other(i,j);   
    return (*this);
}

double& Matrix::operator()(int x,int y)
{
   assert(x < rows && y < cols);
   return mat[x][y];
}

const double Matrix::operator()(int x,int y) const
{
   assert(x < rows && y < cols);
   return mat[x][y];
}

Matrix Matrix::operator+(const Matrix& m)
{
    assert(m.cols == cols && m.rows == rows);

    Matrix newMatrix(m);

    for(int i = 0;i < rows;i++)
       for(int j = 0;j < cols;j++)
          newMatrix(i,j) += (*this)(i,j);
    return newMatrix;
}

Matrix Matrix::operator-(const Matrix& m)
{
    assert(m.cols == cols && m.rows == rows);

    Matrix newMatrix(*this);

    for(int i = 0;i < rows;i++)
       for(int j = 0;j < cols;j++)
          newMatrix(i,j) -= m(i,j);
    return newMatrix;
}


Matrix Matrix::operator*(const Matrix& m)
{
    assert(cols == m.rows);
    
    Matrix newMatrix(rows,m.cols,0);
    for(int i = 0;i < newMatrix.rows;i++)
    {
       for(int j = 0;j < newMatrix.cols;j++)
       {
            for(int k = 0; k < cols; ++k)
             newMatrix(i,j) += (*this)(i,k) * m(k,j);
       }
    }
    return newMatrix;
}

Matrix Matrix::operator*(double value)
{
    Matrix newMatrix((*this));
    for(int i = 0;i < rows;i++)
    {
       for(int j = 0;j < cols;j++)
       {
             newMatrix(i,j) *= value;
       }
    }
    return newMatrix;
}

void getSubMatrix(const Matrix& father,Matrix& temp,int pX,int pY)
{

    int x = 0;
    int y = 0;

    for(int i = 0;i < father.getRows();i++)
    {
        for(int j = 0;j < father.getCols();j++)
        {
           if(i != pX && j != pY)
           {
               temp(x,y++) = father(i,j);
               if(y >= father.getCols() - 1)
               {
                   y = 0;
                   x++;
               }
           }

        }

    }

}


double Matrix::det() const
{
    assert(rows == cols);

    if(rows == 1)
       return mat[0][0];
    if(rows == 2)
       return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];

    Matrix subMatrix(rows - 1,rows - 1,0);

    double determinant = 0;

    int sign = 1;
    for(int i = 0;i < rows;i++)
    {
        getSubMatrix((*this),subMatrix,0,i);
        determinant += subMatrix.det() * sign * (*this)(0,i);
        sign = -sign;
    }
    return determinant;
   
}

Matrix Matrix::ADJ()
{
    Matrix e(*this);

    if(rows == 1)
    {
       e(0,0) = 1;
       return e;
    }

    Matrix subMat(cols - 1,rows - 1,0);

    int s = 1;
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            getSubMatrix(*this,subMat,i,j);
            s = ((i+j)%2==0)? 1: -1;
            e(j,i) = subMat.det() * s;

        }
    }


    return e;

}

Matrix Matrix::transpose()
{
    Matrix t(cols,rows,0);

    for(int i = 0;i < rows;i++)
        for(int j = 0;j < rows;j++)
            t(j,i) = mat[i][j];

    return t;
}



bool Matrix::inverse(Matrix& inv)
{
    double determinant = det();
    if(determinant == 0)
        return false;
    
    inv = ADJ();

    for(int i = 0;i < rows;i++)
        for(int j = 0;j < cols;j++)
           inv(i,j) /= determinant;

    return true;
}

#endif