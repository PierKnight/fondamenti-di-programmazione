#include <iostream>
#include <vector>
#include <limits>
using namespace std;



//involontariamente ho fatto la tecnica golosa (e ti pareva)
int divCoinsGolosa(const vector<int>& vec)
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

int divCoinsDinamica(const vector<int>& vec)
{
    if(vec.empty())
        return 0;
    if(vec.size() == 1)
        return vec[0];

    //la matrice che memorizza il valore data alla persona numero 1
    vector<vector<int>> matrix;

    int n = vec.size();

    //somma dei valori totali delle monete
    int valoreTotaleMonete = vec[0];

    
    //la matrice segue cosi: prima riga, se diamo una monet alla persona, seconda riga diamo due monete etc...
    //ovviamente il valore totale di monete di una singola moneta è il valore stesso di quest'ultima
    matrix.push_back(vec);

    for(int i = 1;i < n;i++)
    {
        valoreTotaleMonete += vec[i];

        vector<int> row(n,0);
        matrix.push_back(row);
    }

    //cout<<"Totale Valore: "<<valoreTotaleMonete<<endl;



    //il caso peggiore
    int miglioreDifferenza = numeric_limits<int>::max();

    //proviamo i vari prestiti che possiamo fare mano a mano
    for(int i = 0;i < n - 1;i++)
    {

        for(int j = 0;j < n;j++)
        {
            
            for(int k = 0;k < n - i;k++)
            {
               int valoreTotaleP = i == 0 ? matrix[i][j] : matrix[i - 1][j] + vec[(j + i + k) % n];

               //con questo aggiorno la mia matrice
               if(i > 0 && k == 0)
                  matrix[i][j] = valoreTotaleP;           
               int differenzaDatoValore = abs(valoreTotaleMonete - valoreTotaleP * 2);         
               //se troviamo una combinazione che dia 0 di differenza,allora è inutile andare avanti non troverò di meglio
               if(differenzaDatoValore == 0)
               {     
                  return 0;
               }
            

               if(differenzaDatoValore < miglioreDifferenza)
               {
                   miglioreDifferenza = differenzaDatoValore;   
               }        
            }


            
        }


    }
   
   /*
   cout<<endl;
   for(int i = 0;i < n - 1;i++)
   {
       for(int j = 0;j < n;j++)
       {
           cout<<matrix[i][j]<<" ";
       }
       cout<<endl;
   }
   */

    return miglioreDifferenza;

}

int main()
{
    vector<int> input;

    int value;
    while(cin>>value && value != -1)
    {
        input.push_back(value);
    }

    cout<<"La differenza minima tra le due persone e': "<<divCoinsDinamica(input);
}