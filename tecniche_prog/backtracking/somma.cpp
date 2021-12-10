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

    bool canAdd(int x,const SolutionT& solution)
    {
        for(int i = 0;i < solution.sol.size();i++)
              if(solution.sol[i] == x)
                  return false;
        return x <= solution.sommaRestante;
    }

    bool isComplete(const SolutionT& solution)
    {
        return solution.sommaRestante == 0;
    }

    //la i serve per evitare di controllare combinazioni uguali
    public:
    bool solve(SolutionT& solution,int i)
    {
        for(int x = i;x < solution.numeri.size();x++)
        {
            if(canAdd(x,solution))
            {
               add(x,solution);

               if(isComplete(solution)){return true;}
               if(solve(solution,x + 1)){return true;}
               remove(solution);
            }
        }
        return false;
        
    }
    

};

int main()
{
    vector<int> numeri;
    


    cout<<"Inserire Numeri: ";
    int value;
    while(cin>>value && value != -1)
          numeri.push_back(value);
    cout<<"Inserire Target: ";
    cin>>value;
    


    SolutionT test(value,numeri);

    if(test.solve(test,0))
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