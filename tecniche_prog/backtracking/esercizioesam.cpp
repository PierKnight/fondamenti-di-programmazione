#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct Triple
{
    string s1;
    string s2;
    string s3;

    Triple(string _s1,string _s2,string _s3):s1(_s1),s2(_s2),s3(_s3){}
};


struct Soluzione
{
    unordered_map<string,int> map;
    vector<string> A;
    vector<Triple> S;
    vector<int> sol;
    Soluzione(vector<string> A,vector<Triple> S)
    {
        this -> A = A;
        this -> S = S;
    }
};

bool canAdd(int x,const Soluzione& sol)
{
    return find(sol.sol.begin(),sol.sol.end(),x) == sol.sol.end();
}

bool isValidTriple(const Triple& t,const unordered_map<string,int>& map)
{
    return (map.at(t.s1) < map.at(t.s2) && map.at(t.s2) < map.at(t.s3)) || (map.at(t.s3) < map.at(t.s2) && map.at(t.s2) < map.at(t.s1));
}

bool isComplete(const Soluzione& sol)
{
    if(sol.sol.size() < sol.A.size())
       return false;
    
    for(Triple t : sol.S)
    {
       if(!isValidTriple(t,sol.map))
          return false;
    }
    return true;
}

void addSol(int x,Soluzione& sol)
{
    sol.sol.push_back(x);
    sol.map[sol.A[sol.sol.size() - 1]] = x;
}

void removeSol(Soluzione& sol)
{
    string key = sol.A[sol.sol.size() - 1];
    sol.sol.pop_back();
    sol.map.erase(key);
}

bool solve(Soluzione& sol)
{
    for(int x = 1;x <= sol.A.size();x++)
    {
        if(canAdd(x,sol))
        {
            addSol(x,sol);
            if(isComplete(sol)){return true;}
            if(solve(sol))return true;
            removeSol(sol);    
        }
    }
    return false;
}

int main()
{
    
    vector<string> A = {"a","b","c","d","e"};

    Triple t1("a","e","d");
    Triple t2("b","c","d");
    Triple t3("c","a","b");
    Triple t4("d","e","c");


    vector<Triple> C = {t1,t2,t3,t4};


    Soluzione sol(A,C);

    if(solve(sol))
    {
       cout<<"YES!!"<<endl;
       for(int i = 0;i < sol.sol.size();i++)
           cout<<sol.sol[i]<<endl;
    }


    return 0;
}