#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct point
{
    int x;
    int y;

    point(int _x,int _y):x(_x),y(_y){}
};

class QueenSolution
{
    public:
    //la grandezza della scacchiera n x n
    int n;
    vector<vector<bool>> board;
    vector<point> currentQueens;
    int currentCol;
    int currentRow;

    QueenSolution(int _n):n(_n),currentCol(0),currentRow(0)
    {
        for(int i = 0;i < n;i++)
        {
            vector<bool> row(n,false);
            board.push_back(row);
        }

    };

    void stepForward()
    {
        if(++currentCol >= n)
        {
            currentCol = 0;
            ++currentRow;
        }

        //cout<<"row: "<<currentRow<<", col: "<<currentCol<<endl;
    }

    void stepBackwards()
    {

        if(--currentCol < 0)
        {
            currentCol = n - 1;
            --currentRow;
        }
    }

};

bool canAdd(bool queen,const QueenSolution& sol)
{
    
    if(sol.currentRow >= sol.n || sol.currentCol >= sol.n)
        return false;

   
    if(!queen)
        return true;
    

    for(int i = 0;i < sol.n;i++)
    {
        for(int j = 0;j < sol.n;j++)
        {
            bool isPlusPattern = i == sol.currentRow || j == sol.currentCol;
            bool isCrossPattern = i - j == sol.currentRow - sol.currentCol || (sol.n - 1 - i) - j == (sol.n - 1 - sol.currentRow) - sol.currentCol;
            if(sol.board[i][j] && (isPlusPattern || isCrossPattern))
               return false;       
        }
    }
    return true;
}

bool isComplete(const QueenSolution& sol)
{
    return sol.currentQueens.size() == sol.n;
}

void add(bool queen,QueenSolution& sol)
{
    
    if(queen)
    {
       point p(sol.currentRow,sol.currentCol);
       sol.currentQueens.push_back(p);
    }
    
    sol.board[sol.currentRow][sol.currentCol] = queen;
    sol.stepForward();

}

void remove(QueenSolution& sol)
{
    if(sol.currentRow < sol.n && sol.currentCol < sol.n)
    {
       if(sol.board[sol.currentRow][sol.currentCol])
        {
         sol.currentQueens.pop_back();
         sol.board[sol.currentRow][sol.currentCol] = false;
        }
    }
    sol.stepBackwards();
    
}



bool solve(QueenSolution& sol)
{
    
    for(int i = 0;i < 2;i++)
    {
        bool queen = i == 1;
        if(canAdd(queen,sol))
        {
            add(queen,sol);
            if(isComplete(sol))
               return true;
            if(solve(sol))
               return true;
            remove(sol);
        }
    }
    return false;

}




void drawBoard(QueenSolution& queen)
{
    for(int i = 0;i < queen.n;i++)
    {
        for(int j = 0;j < queen.n;j++)
        {
            string slot = queen.board[i][j] ? "X" : "-";

            cout<<slot<<" ";
        }
        cout<<endl;
    

    }
}

int main()
{
    QueenSolution test(8);

    if(solve(test))
    {  
        for(int i = 0;i < test.currentQueens.size();i++)
        {
            point p = test.currentQueens[i];
            cout<<"row: "<<p.x<<", col: "<<p.y<<endl;
        } 
        drawBoard(test);
    }
    else
    {
        cout<<"NON ESISTE UNA SOLUZIONE"<<endl;
    }

   

    

    
    return 0;
}