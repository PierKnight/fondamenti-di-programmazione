#include <vector>
#include <iostream>
#include <limits>
using namespace std;

struct Soluzione
{
    vector<int> debolezze;
    vector<int> copertura;
    int matrix[18][18];

    vector<int> tipi;

 

    int bestScoperto = numeric_limits<int>::max();
    vector<int> bestTipi;


    Soluzione(int m[18][18]):copertura(18,0), debolezze(18,0)
    {
        for(int i = 0;i < 18;i++)
           for(int j = 0;j < 18;j++)
               matrix[i][j] = m[i][j];
    }




};

bool canAdd(int x,const Soluzione& sol)
{
    if(sol.tipi.empty())return true;
    if(sol.tipi.size() > 6) return false;

    for(int i = 0;i < 18;i++)
    {
        if(sol.matrix[x][i] != 0 && sol.debolezze[i] > 0)
            return true;
    }
    return false;
}

bool isComplete(const Soluzione& sol)
{
    return sol.tipi.size() == 6;
}

void addSol(int x,Soluzione& sol)
{
    for(int i = 0;i < 18;i++)
    {
       if(sol.matrix[x][i] != 0)
       {
           sol.copertura[i]++;
       }
       if(sol.matrix[i][x] != 0)
       {
           sol.debolezze[i]++;
       }
    }
    sol.tipi.push_back(x);
}

void removeSol(int x,Soluzione& sol)
{
    for(int i = 0;i < 18;i++)
    {
       if(sol.matrix[x][i] != 0)
       {
           sol.copertura[i]--;
       }
       if(sol.matrix[i][x] != 0)
       {
           sol.debolezze[i]--;
       }
    }
    sol.tipi.pop_back();
}

void solve(Soluzione& sol)
{
    for(int i = 0;i < 18;i++)
    {
        if(canAdd(i,sol))
        {
            addSol(i,sol);
            if(isComplete(sol))
            {
                int debolezze = 0;
                for(int i = 0;i < 18;i++)
                {                  
                    if(sol.debolezze[i] > 0 && sol.copertura[i] == 0)
                        debolezze++;
                }
                if(debolezze < sol.bestScoperto)
                {
                    sol.bestTipi = sol.tipi;
                    sol.bestScoperto = debolezze;
                }
                if(debolezze == 0)
                   return;
            }
            solve(sol);
            removeSol(i,sol);
        }
    }
}



int main()
{
    vector<string> tipi = { "NOR","FIR","WAT","ELE","GRA","ICE","FIG","POI","GRO","FLY","PSY","BUG","ROC","GHO","DRA","DAR","STE","FAI"};
    int matrix[18][18] = 
{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
 {0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0},  
 {0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},  
 {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},  
 {0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},  
 {0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0},  
 {1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0},  
 {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},  
 {0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0},  
 {0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0},  
 {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},  
 {0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0},  
 {0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0},  
 {0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},  
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},  
 {0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},  
 {0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1},  
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0}};

   Soluzione sol(matrix);

   solve(sol);


   if(!sol.bestTipi.empty())
   {
     for(int i = 0;i < sol.bestTipi.size();i++)
     {
        cout<<tipi[sol.bestTipi[i]]<<endl;
     }

      cout<<"totale debolezze: "<<sol.bestScoperto<<endl;
   }
   else
     cout<<"nessuna combinazione valida"<<endl;

    
    int max = 0;
    int type1 = 0;
    int type2 = 0;

    for(int i = 0;i < 18;i++)
    {
        for(int j = 0;j < 18;j++)
        {
            int cop = 0;
            for(int t = 0;t < 18;t++)
            {
                if(matrix[i][t] > 0 || matrix[j][t] > 0)
                {
                    cop++;
                }
            }
            if(cop > max)
            {
                max = cop;
                type1 = i;
                type2 = j;
            }
            
        }
    }

    cout<<"Type1: "<<tipi[type1]<<endl;
    cout<<"Type1: "<<tipi[type2]<<endl;

    cout<<"Totale Coperture: "<<max<<endl;
    



    return 0;
}