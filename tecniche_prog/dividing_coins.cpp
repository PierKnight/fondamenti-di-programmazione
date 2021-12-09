#include <iostream>
#include <vector>
using namespace std;



//si utilizza la tecnica della programmazione dinamica visto che risolvo i sottoproblemi
int divCoins(const vector<int>& vec)
{
    int valorePersona1 = 0;
    int valorePersona2 = 0;

    //aggiunta in più, ora fornisce anche quali monete dare a chi per poter minimizzare la differenza di valore
    vector<int> monetePersona1;
    vector<int> monetePersona2;

    for(int i = 0;i < (vec.size() + 1) / 2;i++)
    {
        int left = vec[i];
        int right = vec[vec.size() - 1 - i];

        //questo serve in caso di input di numero dispari, nel for quando si arriva al centro si fa finta di comparare il valore su i e 0
        if(i == vec.size() - 1 - i)
            right = 0;
        


        
        if(abs((valorePersona1 + right) - (valorePersona2 + left)) < abs((valorePersona1 + left) - (valorePersona2 + right)))
        {
            valorePersona1 += right;
            valorePersona2 += left;
            monetePersona1.push_back(right);
            monetePersona2.push_back(left);
        }
        else
        {
            valorePersona1 += left;
            valorePersona2 += right;
            monetePersona1.push_back(left);
            monetePersona2.push_back(right);
        }
    }
    cout<<"Persona 1 ha: ";
    for(int i = 0;i < monetePersona1.size();i++)
         cout<<monetePersona1[i]<<"\t";
    cout<<endl;

    cout<<"Persona 2 ha: ";
    for(int i = 0;i < monetePersona2.size();i++)
    if(monetePersona2[i] != 0)
         cout<<monetePersona2[i]<<"\t";
    cout<<endl;
         

    return abs(valorePersona1 - valorePersona2);
}

int main()
{
    vector<int> input = {2, 5, 3, 1, 7};

    cout<<"La differenza minima tra le due persone e': "<<divCoins(input)<<endl;
}