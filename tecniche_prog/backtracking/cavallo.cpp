#include <iostream>
#include <vector>
using namespace std;

struct punto
{
    int row;
    int col;

    punto(int a,int b)
    {
        row = a;
        col = b;
    }
};

struct SoluzioneCavallo
{
    
    int board[8][8];
    int currRow;
    int currCol;
    int totalVisited;


    SoluzioneCavallo(int row,int col)
    {
        for(int i = 0;i < 8;i++)
        {
            for(int j = 0;j < 8;j++)
            {
               board[i][j] = -1;
            }
        }
        currRow = row;
        currCol = col;
        totalVisited = 1;
        board[row][col] = 1;
    }

    bool checkPosition(int i,int j,int& updateI,int& updateJ) const
    {
        if(i >= 0 && j >= 0 && i < 8 && j < 8)
        {
            updateI = i;
            updateJ = j;
            return true;
        }
        return false;
    }
               
};


//il cavallo può saltare in 8 diverse posizioni, rappresentate da index
bool getNearCheckByIndex(const SoluzioneCavallo& sol,int index,int& i,int& j)
{
    switch (index)
    {
    case 0:
        return sol.checkPosition(sol.currRow - 2,sol.currCol - 1,i,j);
    case 1:
        return sol.checkPosition(sol.currRow - 1,sol.currCol - 2,i,j);
    case 2:
        return sol.checkPosition(sol.currRow - 2,sol.currCol + 1,i,j);
    case 3:
        return sol.checkPosition(sol.currRow - 1,sol.currCol + 2,i,j);
    case 4:
        return sol.checkPosition(sol.currRow + 1,sol.currCol + 2,i,j);
    case 5:
        return sol.checkPosition(sol.currRow + 2,sol.currCol + 1,i,j);
    case 6:
        return sol.checkPosition(sol.currRow + 2,sol.currCol - 1,i,j);
    case 7:
        return sol.checkPosition(sol.currRow + 1,sol.currCol - 2,i,j);
    default:
        return false;
    }
}


bool isComplete(const SoluzioneCavallo& sol)
{
    return sol.totalVisited >= 64;
}

bool solve(SoluzioneCavallo& sol,bool right)
{
    int row;
    int col;
    //le otto possibili mosse del cavallo
    for(int index = 0;index < 8;index++)
    {
        int test= right ? index : 7 - index;
        if(getNearCheckByIndex(sol,test,row,col) && sol.board[row][col] == -1)
        {
            
            sol.totalVisited++;
            sol.board[row][col] = sol.totalVisited;


            int precRow = sol.currRow;
            int precCol = sol.currCol;

            sol.currRow = row;
            sol.currCol = col;
            
            if(isComplete(sol)){return true;}
            if(solve(sol,right)){return true;}

            sol.totalVisited--;
            sol.board[row][col] = -1;
            sol.currRow = precRow;
            sol.currCol = precCol;
        }
    }
    return false;
}


int main()
{
    SoluzioneCavallo cav(3,4);
    solve(cav,false);

     
   
        int row;
        int col;
   
    //if(getNearCheckByIndex(cav,15,row,col))
    //    cav.board[row][col] = 55;
    

    for(int i = 0;i < 8;i++)
    {
        for(int j = 0;j < 8;j++)
        {
            cout<<cav.board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

