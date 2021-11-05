#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class Cliente
{
    private:
    string nome;
    string trattamento; //nome del trattamento
    int durata; //durata trattamento in minuti
    int prezzo;  //prezzo trattamento

    public:
    Cliente():nome(""),trattamento(""),durata(0),prezzo(0){}
    Cliente(string n,string t,int d,int p): nome(n),trattamento(t),durata(d),prezzo(p){}

    //getters
    string getNome() const{return nome;}
    string getTrattamento() const{return trattamento;}
    int getDurata() const{return durata;}
    int getPrezzo() const{return prezzo;}    

    friend istream& operator>>(istream& in,Cliente& c)
    {
        in.ignore();
        cout<<"Inserire Nome Cliente:"; getline(in,c.nome);
        cout<<"Inserire Trattamento Cliente:"; getline(in,c.trattamento);
        cout<<"Inserire Durata Cliente:"; in>>c.durata;
        cout<<"Inserire Prezzo Cliente:"; in>>c.prezzo;
        return in;
    }


};

#endif