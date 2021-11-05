#include <iostream>
#include <string>
#include "Cliente.h"
#include <queue>


void stampaMenu()
{
    cout<<"Inserisci 1 per inserire un nuovo cliente."<<endl;
    cout<<"Inserisci 2 per eseguire il trattamento del prossimo cliente."<<endl;
    cout<<"Inserisci 3 per sapere il prossimo l'orario disponibile per un nuovo trattamento."<<endl;
    cout<<"Inserisci 4 per stampare tutti i clienti attualmente in fila."<<endl;
    cout<<"Inserisci 5 per stampare l'orario attuale."<<endl;
    cout<<"Inserisci 6 per stampare l'incasso attuale."<<endl;
    cout<<"Inserisci 0 per uscire."<<endl;
}

void printOrario(int orario)
{
    int ore = orario / 60;
    int minuti = orario % 60;

    string s1 = to_string(ore);
    if(ore < 10)
       s1 = "0" + s1;
    string s2 = to_string(minuti);
    if(minuti < 10)
       s2 = "0" + s2;

    cout<<s1<<':'<<s2<<endl;
}

//questo va bene perchè copio la queue senza modificare niente
void stampaClienti(int orario,queue<Cliente> clienti)
{
    if(clienti.empty())
    {
        cout<<"Nessun e' presente nessun cliente!"<<endl;
        return;
    }
    
    while(!clienti.empty())
    {
        Cliente cliente = clienti.front();
        cout<<"-Prenotato il cliente: \""<<cliente.getNome()<<"\" per le ore: ";
        printOrario(orario);
        orario += cliente.getDurata();
        clienti.pop();
    }
}


const int orarioApertura = 8 * 60;//le otto di mattina in minuti (si non ha molto senso)
const int orarioChiusura = 18 * 60;//le 18 di pomeriggio in minuti (si non ha molto senso x2)

int main()
{
     
    int orario = orarioApertura;
    int minutiDiLavoro = 0;
    int incasso = 0;
    queue<Cliente> clienti;

    cout<<"Benvenuti nel parrucchiere! Orario di apertura 8:00 chiusura 18:00"<<endl;

    int input;
    stampaMenu();
    cin>>input;
  
    do
    {
        
        switch (input)
        {
        case 1:
        {
            Cliente cliente;
            cin>>cliente;
            
            if(cliente.getDurata() + minutiDiLavoro + orario >= orarioChiusura)
            {
                cout<<"Non e' possibile aggiungere un nuovo cliente! Il negozio e' chiuso!"<<endl;
                break;
            }
            minutiDiLavoro += cliente.getDurata();
            clienti.push(cliente);           
            break;
        }
        case 2:
        {
            if(clienti.empty())
            {
                cout<<"Non e' presente nessun cliente!"<<endl;
                break;
            }

            Cliente cliente = clienti.front();
            orario += cliente.getDurata();
            incasso += cliente.getPrezzo();
            minutiDiLavoro -= cliente.getDurata();
            clienti.pop();          
            break;
        }
        case 3:
        {
            cout<<"Il prossimo appuntamento disponibile e' alle ore ";
            printOrario(orario + minutiDiLavoro);
            break;
        }
        case 4:
            stampaClienti(orario,clienti);
            break;
        case 5:
        {
            cout<<"Orario Attuale: ";
            printOrario(orario);
            break;
        }
        case 6:
            cout<<"Incasso:"<<incasso<<endl;
            break;
        default:
            break;
        }
        stampaMenu();
        cin>>input;
    }
    while(input != 0);
    return 0;
}



