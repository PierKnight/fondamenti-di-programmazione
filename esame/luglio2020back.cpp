#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Soluzione
{
    unordered_map<string,int> convMap;
    vector<int> usoLettera;

    vector<vector<string>> S;
    int k;
    vector<int> sol;

    Soluzione(vector<string>& U,vector<vector<string>>& _S,int _k):S(_S),k(_k),usoLettera(U.size(),0)
    {
        for(int i = 0;i < U.size();i++)
             convMap[U[i]] = i;
    }


};

bool canAdd(int x,const Soluzione& sol)
{
    if(sol.sol.size() >= sol.k)
        return false;
    
    for(string s : sol.S[x])
    {
        if(sol.usoLettera[sol.convMap.at(s)] == 0)
            return true;
    }
    return false;
}

bool isComplete(const Soluzione& sol)
{
    for(int i = 0;i < sol.k;i++)
        if(sol.usoLettera[i] == 0)
           return false;
    return true;
}

void addSol(int x,Soluzione& sol)
{
    sol.sol.push_back(x);
    for(string s : sol.S[x])
        sol.usoLettera[sol.convMap.at(s)]++;
}

void removeSol(int x,Soluzione& sol)
{
    sol.sol.pop_back();
     for(string s : sol.S[x])
        sol.usoLettera[sol.convMap.at(s)]--;
}

bool solve(Soluzione& sol)
{
    for(int i = 0;i < sol.usoLettera.size();i++)
    {
        if(canAdd(i,sol))
        {
            addSol(i,sol);
            if(isComplete(sol))return true;
            if(solve(sol))return true;
            removeSol(i,sol);
        }
    }
    return false;
}

int main()
{
    vector<string> U = {"a", "b", "xq", "e", "f"};
    vector<vector<string>> S = 
    { {"xq", "e", "f" }, 
         {"b", "e", "f"}, 
         {"a", "b"}, 
         {"xq", "f"}, 
         {"a", "xq", "e" } };

    int k = 2;
    Soluzione sol(U,S,k);
    if(solve(sol))
    {
        cout<<"YES!!"<<endl;
        for(int i : sol.sol)
           cout<<i<<endl;
    }
    return 0;
}