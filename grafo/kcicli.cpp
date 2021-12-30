#include "Grafo.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Soluzione
{
    Grafo grafo;
    vector<int> ciclo;
    int k;

    Soluzione(int _k,const Grafo& g):k(_k),grafo(g){
    }
};

bool canAdd(const Soluzione& sol,int nodo)
{
    if(sol.ciclo.empty()) return true;
 
    if(!sol.grafo(sol.ciclo.back(),nodo))
       return false;

    if(find(sol.ciclo.begin(),sol.ciclo.end(),nodo) != sol.ciclo.end())
       return false;

    if(sol.ciclo.size() < sol.k)
       return true;

    
    return false;

}

bool isComplete(const Soluzione& sol)
{
   return sol.k == sol.ciclo.size() && sol.grafo(sol.ciclo.back(),sol.ciclo.front());
}

bool solve(Soluzione& sol)
{
    for(int i = 0;i < sol.grafo.n();i++)
    {
        if(canAdd(sol,i))
        {
            sol.ciclo.push_back(i);
            if(isComplete(sol))
               return true;
            if(solve(sol))
               return true;
            
            sol.ciclo.pop_back(); 
        }
    }
    return false;
}



int main()
{

    Grafo grafo(5);

    grafo(0,1,true);
    grafo(1,4,true);
    grafo(2,1,true);
    grafo(3,2,true);
    grafo(4,3,true);
    grafo(1,3,true);

    Soluzione sol(3,grafo);

    if(solve(sol))
      cout<<"YES"<<endl;

    return 0;
}