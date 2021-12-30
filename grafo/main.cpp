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

void printCammino(const vector<int>& map,int target)
{  

    std::string path;

    while(target != 0)
    {
        path = " --> " + to_string(target) + path;
        target = map[target];
    }

    cout<<0<<path<<endl;


}

//ritorna il nodo che ha il percoso ad esso meno costoso
int estraiMinimo(const GrafoPesato& g,vector<bool>& visitato,int& nNodiVisitati,const vector<int>& W)
{
    int costoMinimo = numeric_limits<int>::max();
    int nodoMinimo = -1;

    for(int i = 0;i < g.n();i++)
    {
        if(!visitato[i] && W[i] < costoMinimo)
        {
            nodoMinimo = i;
            costoMinimo = W[i];
        }
    }
    if(nodoMinimo != -1)
    {
    visitato[nodoMinimo] = true;
    nNodiVisitati++;
    }
    
    return nodoMinimo;

}

//ritorna l'array dei percorsi minimi
//start è il nodo di partenza
//il target serve per specificare se ci interessa un cammino al target e fermarci li oppure l'intero albero dei cammini
vector<int> dijkstra(const GrafoPesato& g,int start,int target)
{
    int nNodiVisitati = 0;
    vector<bool> visitato(g.n(),false);
    vector<int> W(g.n(),numeric_limits<int>::max());
    W[start] = 0;

    vector<int> percorsi(g.n(),0);

    while(nNodiVisitati < g.n())
    {
        int minNodo = estraiMinimo(g,visitato,nNodiVisitati,W);


        if(minNodo == -1 || minNodo == target)
        {
            return percorsi;
        }

        for(int i = 0;i < g.n();i++)
        {
            if(i != minNodo && g(minNodo,i))
            {
                if(W[minNodo] + g.w(minNodo,i) < W[i])
                {
                   W[i] = W[minNodo] + g.w(minNodo,i);
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

vector<int> split(const std::string& s,char c)
{
    vector<int> vec;

    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == c)
           vec.push_back(i);
    }
    return vec;
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


    

    std::string input;
    int n;
    cout<<"Grandezza Grafo: ";
    cin>>n;
    cout<<endl;

    GrafoPesato test(n);


    while(getline(cin,input) && input != "-1")
    {
        cout<<input<<endl;
        if(input.size() <= 4)
        {
            cout<<"L'input non puo' essere cosi corto."<<endl;
            continue;
        }
        vector<int> spl = split(input,',');
        if(spl.size() < 2)
        {
            cout<<"L'input non e' formato correttamente."<<endl;
            continue;
        }
          
        int from = stoi(input.substr(0,spl[0]));
        int to = stoi(input.substr(spl[0] + 1,spl[1]));
        int w = stoi(input.substr(spl[1] + 1,spl[2]));

        test(from,to,true,w);

        cout<<"Inserito Arco ("<<from<<","<<to<<") con peso "<<w<<endl;
    }


    printCammino(dijkstra(test,0,3),3);



    return 0;
}

