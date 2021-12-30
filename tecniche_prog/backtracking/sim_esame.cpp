/*
scrivere una funzione che prenda in input un vettore di stringhe S ed un vettore di liste L, dove ogni
lista contiene almeno 2 e al massimo 3 stringhe appartenenti a S, e un intero positivo q.
La funzione deve restituire true se esiste un sottoinsieme P di S tale che:
- P ha almeno q stringhe;
- Non esiste una lista l in L tale che tutte le sue stringhe sono contenute in P.

Nel caso in cui non esista un sottoinsieme che rispetti queste condizioni, return false;
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Soluzione
{
     // ISTANZA
    int q;
    vector<char> S;
    vector<vector<char>> L;

    // SOLUZIONE
    string sol;

    Soluzione(int _q, vector<char> _S, vector<vector<char>> _L): q(_q), S(_S), L(_L) {}

};

bool canAdd(int x,const Soluzione& sol)
{
    if(sol.sol.empty())return true;
    if(sol.sol.size() >= sol.q) return false;
    if(find(sol.sol.begin(),sol.sol.end(),sol.S[x]) != sol.sol.end())return false;

    for(vector<char> l : sol.L)
    {
        bool contieneTutto = true;
        for(int i = 0;i < l.size() && contieneTutto;i++)
        {
            if(find(sol.sol.begin(),sol.sol.end(),l[i]) == sol.sol.end() && l[i] != sol.S[x]) //non trovo il char della lista nella soluzione corrente e non è x
                contieneTutto = false;
        }
        if(contieneTutto)
           return false;
    }

    return true;

}

bool isComplete(const Soluzione& sol)
{
    return sol.sol.size() >= sol.q;
}

void add(int x,Soluzione& sol)
{
    sol.sol.push_back(sol.S[x]);
}

void remove(Soluzione& sol)
{
    sol.sol.pop_back();
}

bool solve(Soluzione& sol)
{
    for(int i = 0;i < sol.S.size();i++)
    {
        if(canAdd(i,sol))
        {
            add(i,sol);
            if(isComplete(sol))return true;
            if(solve(sol))return true;

            remove(sol);
        }
    }
    return false;
}

int main()
{

    vector<char> S ={'a','b','c','d','e','f'};
    vector<char> a = {'a','b','c'};
    vector<char> b = {'a','d'};
    vector<char> c = {'d','e'};
    vector<char> d = {'b','f'};

    vector<vector<char>> L;
    L.push_back(a);
    L.push_back(b);
    L.push_back(c);
    L.push_back(d);

    Soluzione sol(3,S,L);
    if(solve(sol))
       cout<<sol.sol<<endl;

    //stampa aeb

    return 0;
}

