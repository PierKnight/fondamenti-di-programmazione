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

bool solve(Solution& sol)
{
    for(int i = 0;i < sol.W.size();i++)
    {
        if(canAdd(i,sol))
        {
            sol.sol.push_back(i);
            sol.sommaTotale += sol.W[i];
            if(isComplete(sol))return true;
            if(solve(sol))return true;
            
            sol.sommaTotale -= sol.W[i];
            sol.sol.pop_back();
        }
    }
    return false;
}

int main()
{
    vector<int> W = {4, 12, 3, 88, 192};

    Solution sol(W,207);
    if(solve(sol))
    {
       for(int val : sol.sol)
           cout<<val<<endl;
    }
    return 0;
}