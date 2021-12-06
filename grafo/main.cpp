#include <iostream>
#include "Grafo.h"
#include "GrafoNonOrientato.h"
#include "GrafoPesato.h"
#include "vector"
#include "queue"
#include "limits"
#include "list"
using namespace std;





void stampaGrafo(const Grafo grafo)
{
    cout<<"Numero Nodi: "<<grafo.n()<<endl;
    cout<<"Numero Archi: "<<grafo.m()<<endl;
    for(int i = 0;i < grafo.n();i++)
    {
        for(int j = 0;j < grafo.n();j++)
        {
            if(grafo(i,j))
               cout<<"Arco "<<i<<" --> "<<j<<endl;
        }
    
    }
}


//prendere l'indice del nodo con più connessioni con gli altri nodi (iterativo)
int getNodoConGradoMassimo(const Grafo& grafo)
{

    int gradoMassimo = -1;
    int nodoMassimo = -1;

    for(int nodo = 0;nodo < grafo.n();nodo++)
    {

        int grado = 0;
        for(int i = 0;i < grafo.n();i++)
          if(grafo(nodo,i))
             grado++;
        
        if(grado > gradoMassimo)
        {
            gradoMassimo = grado;
            nodoMassimo = nodo;
        }


    }
    
    return nodoMassimo;


    
}

//il metodo ritorna true se e solo se esiste almeno un nodo che è connesso a tutti gli altri
bool almenoUnNodoAdiacenteATutti(const Grafo& g)
{

    for(int nodo = 0;nodo < g.n();nodo++)
    {
        bool connectedToAll = true;
        for(int i = 0;i < g.n() && connectedToAll;i++)
        {
            if(nodo != i && !g(nodo,i))
            {
                connectedToAll = false;
            }
        }
        if(connectedToAll)
          return true;
    }
    return false;
}

//restituisce true se e solo se per ogni 0<=i<=g.n() - 1 vale che g1 e g2 hanno lo stesso numero di nodi
//aventi grado i 
bool stessoNumeroNodiStessoGrado(const Grafo& g1,const Grafo& g2)
{
    if(g1.n() != g2.n())
       return false;

    int numero_nodi_per_grado[g1.n() - 1]{0};

    for(int nodo = 0;nodo < g1.n();nodo++)
    {
        int grado = 0;
        for(int i = 0;i < g1.n();i++)
            if(g1(nodo,i))
                ++grado;
        numero_nodi_per_grado[grado]++;
    }

    for(int nodo = 0;nodo < g2.n();nodo++)
    {
        int grado = 0;
        for(int i = 0;i < g2.n();i++)
            if(g2(nodo,i))
                ++grado;
        numero_nodi_per_grado[grado]--;
    }

    for(int g = 0;g < g1.n() - 1;g++)
        if(numero_nodi_per_grado[g] != 0)
            return false;
    return true;
}

int estraiMinimo(list<int>& daVisitare,const vector<int>& costiCammini)
{
    list<int>::iterator minNodo = daVisitare.begin();
    int minCosto = costiCammini[*minNodo];

    for(auto pos = daVisitare.begin()++; pos != daVisitare.end();pos++)
    {
        if(costiCammini[*pos] < minCosto)
        {
            minNodo = pos;
            minCosto = costiCammini[*pos];
        }
   
    }
    int n = *minNodo;
    daVisitare.erase(minNodo);
    return n;

    
}


void printCammino(const vector<int>& map,int target)
{  

    std::string path;

    while(target != 0)
    {
        path = " --> " + to_string(target);
        target = map[target];
    }

    cout<<0<<path<<endl;


}

vector<int> dijkstra(const GrafoPesato& g)
{
    vector<int> costoCammino(g.n(),numeric_limits<int>::max());
    costoCammino[0] = 0;

    vector<int> percorsi(g.n(),0);   
    
    list<int> visitati;
    list<int> daVisitare;
    for(int i = 0;i < g.n();i++)
      daVisitare.push_back(i);
    

    while(!daVisitare.empty())
    {
        int minNodo = estraiMinimo(daVisitare,costoCammino);
        visitati.push_back(minNodo);


        for(int i = 0;i < g.n();i++)
        {
           if(g(minNodo,i) && minNodo != i)
           {
               if(costoCammino[minNodo] + g.w(minNodo,i) < costoCammino[i])
               {
                   costoCammino[i] = costoCammino[minNodo] + g.w(minNodo,i);
                   percorsi[i] = minNodo;
               }

           }
        }

        
    }
    return percorsi;


}


//ritorna true se e solo se il grafo è debolmente connesso
bool connesso(const Grafo& grafo)
{
    queue<int> search;

    vector<bool> trovati(grafo.n(),false);
    trovati[0] = true;
    int numTrovati = 1;
    search.push(0);
    
    while(!search.empty())
    {
        int node = search.front();
        search.pop();
        
        for(int i = 0;i < grafo.n();i++)
        {
            if(grafo(node,i) && i != node && !trovati[i])
            {
                numTrovati++;
                trovati[i] = true;
                search.push(i);
            }
        }
    }

    return numTrovati == grafo.n();
}


//restituisce true il nodo dato appartiene ad un ciclo se presente nel grafo.
bool inUnCiclo(const Grafo& g, int nodo)
{
    queue<int> search;

    vector<bool> trovati(g.n(),false);
    search.push(nodo);

    while(!search.empty())
    {
        int sNode = search.front();
        search.pop();

        for(int i = 0;i < g.n();i++)
        {
            if(g(sNode,i) && i != sNode && !trovati[i])
            {
                if(i == nodo)
                   return true;
                trovati[i] = true;
                search.push(i);
            }
        }

    }
    return false;



}

/*
Sapendo chepesi[i] rappresenta il peso del nodoinel grafo g,
la funzione deve restituire true se e solo se vale per g la seguente proprieta:
per ogni nodo i, il peso di i moltiplicato per il numero di nodi adiacenti a i
 deve essere maggiore o uguale alla somma dei pesi dei nodi a lui adiacenti.
*/

bool proprieta2(const Grafo& g, vector<int>pesi)
{
    for(int i = 0;i < g.n();i++)
    {
        int nodiAdiacenti = 0;
        int totalePesiAdiacenti = 0;

        for(int j = 0;j < g.n();j++)
        {
            if(g(i,j) && i != j)
            {
                ++nodiAdiacenti;
                totalePesiAdiacenti += pesi[j];
            }
        }
        if(pesi[i] * nodiAdiacenti < totalePesiAdiacenti)
           return false;
    }
    return true;

}

int main()
{
    Grafo grafo(4);

    grafo(0,1,true);
    grafo(1,2,true);
    grafo(2,0,true);
    grafo(2,3,true);


    bool trovati[grafo.n()];
    int e = 0;

    if(connesso(grafo))
        cout<<"e' connesso!!!!"<<endl;

    int nodoCiclo = 0;
    if(inUnCiclo(grafo,nodoCiclo))
       cout<<"Il nodo "<<nodoCiclo<<" appartiene ad un ciclo del grafo!"<<endl;



    /*stampaGrafo(grafo);


    cout<<"Grado Massimo e' il nodo: "<<getNodoConGradoMassimo(grafo)<<endl;
    if(almenoUnNodoAdiacenteATutti(grafo))
        cout<<"Esiste un nodo adiacente a tutti!"<<endl;
    else
        cout<<"Non Esiste un nodo adiacente a tutti!"<<endl;

        */

    return 0;
}

