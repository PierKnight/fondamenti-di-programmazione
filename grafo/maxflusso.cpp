#include <iostream>
#include <stack>
#include "GrafoPesato.h"
#include <vector>
#include <limits>
using namespace std;



void aggiornaFlusso(int n,vector<vector<int>>& flusso,vector<int> flussoCorrente,const vector<int> cammino,int epsilon)
{
    int node = n - 1;
    while(node != 0)
    {
        int prec = cammino[node];
        if(flussoCorrente[node] >= 0)
            flusso[prec][node] += epsilon;
        else
            flusso[node][prec] -= epsilon;
        node = prec;
    }
}

//questo metodo fornisce il cammino incrementale definito dal vettore cammino
//e annesso l'aumento di flusso di questo cammino da nodo "0" a nodo "n - 1"
//ritorna -1 se non è stato possibile trovare un cammino incrementale
int percorsoMinimo(const GrafoPesato& g,vector<vector<int>>& flusso)
{
    stack<int> s;
    s.push(0);

    vector<bool> visitati(g.n(),false);
    visitati[0] = true;

    //il flusso fino al nodo i-esimo
    vector<int> flussoCorrente(g.n(),0);
    flussoCorrente[0] = numeric_limits<int>::max();

     vector<int> cammino(g.n(),0);

    while(!s.empty())
    {
        int top = s.top();
        s.pop();

        for(int i = 0;i < g.n();i++)
        {
            if(visitati[i])
               continue;
            if(g(top,i) && flusso[top][i] < g.w(top,i))
            {

                int m = min(abs(flussoCorrente[top]),g.w(top,i) - flusso[top][i]);
                visitati[i] = true;               
                flussoCorrente[i] = m;
                s.push(i);
                cammino[i] = top;

                if(i == g.n() - 1)
                {
                   aggiornaFlusso(g.n(),flusso,flussoCorrente,cammino,m);
                   return m;
                }
            }
            if(g(i,top) && flusso[i][top] > 0)
            {
                int m = min(abs(flussoCorrente[top]),flusso[i][top]);
                visitati[i] = true;               
                flussoCorrente[i] = -m;
                s.push(i);
                cammino[i] = top;
                if(i == g.n() - 1)
                {
                   aggiornaFlusso(g.n(),flusso,flussoCorrente,cammino,m);
                   return m;
                }
            }
        }
        
    }
    cout<<"Nodi appartenenti a W: ";

    for(int i = 0;i < visitati.size();i++)
    {
        if(visitati[i])
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"Archi Taglio Minimo \"Verso in avanti\": "<<endl;
    for(int i = 0;i < g.n();i++)
    {
        for(int j = 0;j < g.n();j++)
        {
            if((visitati[i] && !visitati[j]) && g(i,j))
            {
                cout<<"("<<i<<","<<j<<")"<<endl;
            }

        }
    
    }



    

    return -1;
}

void ford(const GrafoPesato& g)
{
    vector<vector<int>> flusso(g.n(),vector<int>(g.n(),0));

   
    int flussoMassimo = 0;
    int epsilon = 0;
    while(epsilon != -1)
    {
       epsilon = percorsoMinimo(g,flusso);
       
       if(epsilon != -1)
       {
        flussoMassimo += epsilon;
       cout<<"Aumentato il flusso di: "<<epsilon<<endl;
       for(int i = 0;i < g.n();i++)
       for(int j = 0;j < g.n();j++)
       {
           if(flusso[i][j] > 0)
           cout<<"("<<i<<","<<j<<")"<<" -> "<<flusso[i][j]<<endl;
       }
       }
    

        
    }
    cout<<"Il flusso massimo e'"<<flussoMassimo<<endl;

}


int main()
{
    GrafoPesato grafo(6);

    
    //esercizio 1 test
    grafo(0,1,true,12);
    grafo(0,2,true,9);
    grafo(1,3,true,15);
    grafo(1,2,true,3);
    grafo(2,4,true,6);
    grafo(3,2,true,3);
    grafo(3,5,true,7);
    grafo(4,1,true,5);
    grafo(4,5,true,8);
    grafo(4,3,true,8);
    

    //esercizio 2 test
    grafo(0,1,true,7);
    grafo(0,2,true,23);
    grafo(1,3,true,10);
    grafo(2,1,true,6);
    grafo(2,3,true,9);
    grafo(2,4,true,11);
    grafo(3,4,true,5);
    grafo(3,5,true,20);
    grafo(4,1,true,4);
    grafo(4,5,true,8);
    
    
    
    
    
    
    


    ford(grafo);




    

    return 0;
}