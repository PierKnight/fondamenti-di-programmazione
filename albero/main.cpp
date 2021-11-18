#include "AlberoB.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;


template <class T>
AlberoB<T> cerca(const AlberoB<T>& a, T v) {
    if (a.nullo() || a.radice() == v)
        return a;
    
    // a questo punto sono in un sottoalbero che non ha v come valore 
//informativo e non è nullo
    AlberoB<T> temp = cerca(a.figlio(SIN), v);
    if (!temp.nullo())
        return temp;
    // a questo punto so che nel sottoalbero sinistro non c'era un albero con 
// v come valore informativo
    return cerca(a.figlio(DES), v);
}

typedef AlberoB<int> AlberoBInt;

void visitaPerLivelli(const AlberoB<int>& a) {
    if (a.nullo())
        return;
    
    std::queue<AlberoBInt> q;
    q.push(a);
    
    int messi = 1;

    while(!q.empty()) {
        AlberoBInt temp = q.front(); 
        q.pop();
    

       messi--;

       

        
        std::cout << temp.radice() << ' ';
        if(messi == 0)
          cout<<endl;
        

        if (!temp.figlio(SIN).nullo())
        {
            q.push(temp.figlio(SIN));
            messi++;
        }
        if (!temp.figlio(DES).nullo())
        {
            q.push(temp.figlio(DES));
            messi++;
        }


    }   
    //STAMPARE A SCALINI L'ALBERO

    
}

int sommaSottoAlberoEStampa(const AlberoB<int>& albero)
{
    if(albero.nullo())
       return 0;


    int sommaS = sommaSottoAlberoEStampa(albero.figlio(SIN));
    int sommaD = sommaSottoAlberoEStampa(albero.figlio(DES));
    int somma = albero.radice() + sommaS + sommaD;
    cout<<"Valore Del noto: "<<albero.radice()<<": "<<somma<<endl;
    return somma;
}

int main()
{
    

    int valoreIniziale;

    cout<<"Inserire Valore Iniziale: ";
    cin>>valoreIniziale;

    AlberoB<int> albero(valoreIniziale);

    string input;
    
    cout<<"Inserire Input: ";
    cin.ignore();
    while(getline(cin,input) && input != "-1")
    {
       
       int indexPoint = input.find(':');
       int indexSpace = input.find(' ');


       if(indexPoint != -1 && indexSpace != -1)
       {
           int valoreFiglio = stoi(input.substr(0,indexPoint));
           int valorePadre = stoi(input.substr(indexPoint + 1,indexSpace)); 

           AlberoB<int> found = cerca(albero,valorePadre);
           if(!found.nullo())
           {
                     
               char latoS = input[indexSpace + 1];

               Direzione direc = latoS == 's' ? SIN : DES;
               string lato = direc == SIN ? "sinisto" : "destro";
                
               if(found.figlio(direc).nullo())
               {
                    AlberoB<int> newAlbero(valoreFiglio);
                    found.insFiglio(direc,newAlbero);
                    cout<<"Inserito al nodo \""<<valorePadre<<"\" il valore \""<<valoreFiglio<<"\" sul lato "<<lato<<endl;
               }
               else
               {
                    cout<<"Non è possibile inserire il nodo sul lato "<<lato<<endl;
               }
               
           }
           else
           cout<<"Nodo padre non trovato!"<<endl;
       }
       else
       cout<<"Formato Input Invalido"<<endl;
       

       cout<<"Inserire Input: ";
    }

    visitaPerLivelli(albero);

    //sommaSottoAlberoEStampa(albero);
  
    return 0;
}