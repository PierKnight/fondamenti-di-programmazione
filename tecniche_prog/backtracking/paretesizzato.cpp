#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct SolutionT
{
    

    private:
    string solutioneCorrente;
    int parentesiAperte;
    int n;

    public: 
    vector<string> solutioni;
    SolutionT(int n_):n(n_),parentesiAperte(0),solutioneCorrente(""){}


    private:

    void add(int x,SolutionT& sol)
    {
        if(x == 0)
           sol.parentesiAperte++;
        
        char stringa = x == 0 ? '(' : ')';
        sol.solutioneCorrente += stringa;
        
    }

    void remove(SolutionT& sol)
    {
        if(sol.solutioneCorrente.back() == '(')
            sol.parentesiAperte--;
        
        sol.solutioneCorrente.pop_back();
    }

    bool canAdd(int x,SolutionT& sol)
    {
        if(x == 0)
           return sol.parentesiAperte < sol.n;
        else 
           return sol.parentesiAperte > (sol.solutioneCorrente.size() - sol.parentesiAperte);
    }

    bool isComplete(SolutionT& sol)
    {
        return sol.solutioneCorrente.size() == sol.n * 2;
    }


    void solve(SolutionT& sol)
    {
        for(int x = 0;x < 2;x++)
        {
            if(canAdd(x,sol))
            {
                add(x,sol);
                if(isComplete(sol))
                    sol.solutioni.push_back(sol.solutioneCorrente);
                solve(sol);               
                remove(sol);
            }
        }
    }




    

};

int main()
{

    SolutionT sol(3);


    for(int i = 0;i < sol.solutioni.size();i++)
    {
        cout<<sol.solutioni[i]<<endl;
    }

    cout<<"EEEEE"<<sol.solutioni.size();

    return 0;
}