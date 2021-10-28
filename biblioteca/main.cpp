#include <iostream>
using namespace std;
#include "Libro.h"
#include "Cliente.h"
#include "Biblioteca.h"


unsigned int Cliente::CONTATORE = 10000;
unsigned int Libro::CONTATORE = 10000;

void stampaInformazioniMenu();

int main()
{

    Biblioteca biblioteca;

    int comando;

    stampaInformazioniMenu();
   
    while(cin>>comando && comando != -1)
    {
        switch (comando)
        {
        
        case 0:
            biblioteca.aggiungereLibro();
            break;
        case 1:
            biblioteca.rimuovereLibro();    
            break;   
        case 2: 
            biblioteca.aggiungereCliente(); 
            break;  
        case 3:
            biblioteca.rimuovereCliente();
            break;
        case 4:
            biblioteca.inserirePrestito();
            break;
        case 5:
            biblioteca.riconsegnareLibro();
            break;
        case 6: //informazione biblioteca
            cout<<biblioteca;   
            break;
        case 7: //informazione Prestito Libri
            biblioteca.infoLibri();
            break;
        case 8: //informazione Prestito Clienti con libro in
            biblioteca.infoClienti();
            break;
        default:
            break;
        }

        stampaInformazioniMenu();

    }

    cout<<"Grazie Per Aver Utilizzato Il Database Biblioteca creato da Pier!";
    

 
    return 0;
}

void stampaInformazioniMenu()
{
    //stampare menu
        cout<<"Funzioni Disponibili"<<endl;
        cout<<"0 - Aggiungere Libro"<<endl;
        cout<<"1 - Rimuovere Libro"<<endl;
        cout<<"2 - Aggiungere Cliente"<<endl;
        cout<<"3 - Rimuovere Cliente"<<endl;
        cout<<"4 - Inserire Prestito"<<endl;
        cout<<"5 - Riconsegnare Libro"<<endl;
        cout<<"6 - Info Libri e Clienti presenti nella biblioteca."<<endl;
        cout<<"7 - Informazione sui Libri prestati."<<endl;
        cout<<"8 - Informazione sui Clienti con libro in prestito."<<endl;
        cout<<"Inserire: ";
}