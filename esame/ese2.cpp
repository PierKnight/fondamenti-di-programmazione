#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Solution
{
    vector<int> W;
    int V;
    int sommaTotale;
    vector<int> sol;
    vector<int> smallestSol;
    Solution(vector<int> _W,int _V):W(_W),V(_V),sommaTotale(0){}
};


bool canAdd(int x,const Solution& sol)
{
    if(sol.sol.size() >= sol.W.size())
        return false;
    if(find(sol.sol.begin(),sol.sol.end(),x) != sol.sol.end())
        return false;
        
    return sol.sol.size() < sol.W.size() && sol.sommaTotale + sol.W[x] <= sol.V;
}

bool isComplete(const Solution& sol)
{
    return sol.sommaTotale == sol.V;
}

void solve(Solution& sol)
{
    for(int i = 0;i < sol.W.size();i++)
    {
        if(canAdd(i,sol))
        {
            sol.sol.push_back(i);
            sol.sommaTotale += sol.W[i];
            if(isComplete(sol))
              if(sol.smallestSol.empty() || sol.sol.size() < sol.smallestSol.size())
                sol.smallestSol = sol.sol;
            
            
            solve(sol);
            
            sol.sommaTotale -= sol.W[i];
            sol.sol.pop_back();
        }
    }
}

int main()
{
    vector<int> W = {4, 12, 3, 88, 192,203};

    Solution sol(W,207);

    solve(sol);
  
    for(int val : sol.smallestSol)
        cout<<val<<endl;
    
    return 0;
}