#include <iostream>
#include <vector>
using namespace std;


class SolutionT
{
    public:
    vector<int> sol;
    vector<int> numeri;
    int sommaRestante;
    SolutionT(int sommaTarget,const vector<int>& n):sommaRestante(sommaTarget),numeri(n){}
    
    private:
    void add(int x,SolutionT& solution)
    {
        solution.sol.push_back(x);
        solution.sommaRestante -= numeri[x];
    }

    void remove(SolutionT& solution)
    {
        solution.sommaRestante += numeri[solution.sol.back()];
        solution.sol.pop_back();
    }

    bool canAdd(int x,SolutionT& solution)
    {
        for(int i = 0;i < solution.sol.size();i++)
              if(solution.sol[i] == x)
                  return false;
        return x <= solution.sommaRestante;
    }

    bool isComplete(SolutionT& solution)
    {
        return solution.sommaRestante == 0;
    }
    public:
    bool solve(SolutionT& solution)
    {
        int x = 0;
        while(x < solution.numeri.size())
        {
            if(canAdd(x,solution))
            {
               add(x,solution);

               if(isComplete(solution)){return true;}
               if(solve(solution)){return true;}
               remove(solution);
               x++;
            }
            else
              x++;
        }
        return false;
        
    }
    

};

int main()
{
    vector<int> numeri = {1,3,5,7,11,5,8,9};
    SolutionT test(13,numeri);

    if(test.solve(test))
    {
        cout<<"YAY ho trovato una combinazione!: "<<endl;

        for(int i = 0;i < test.sol.size();i++)
            cout<<numeri[test.sol[i]]<<" ";
        cout<<endl;
    }
    else
      cout<<"Non ho trovato nessuna combinazione."<<endl;

    return 0;

}