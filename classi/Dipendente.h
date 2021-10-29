#ifndef DIPENDENTE_H
#define DIPENDENTE_H

#include <iostream>
#include <string>

using namespace std;

class Dipendente
{
    string id,nome,cognome;
    float stipendio;

    public:
    Dipendente()
    {
        id = "";
        nome = "";
        cognome = "";
        stipendio = 0;       
    }

    Dipendente(string id,string nome,string cognome,float stipendio)
    {
        this -> id = id;
        this -> nome = nome;
        this -> cognome = cognome;
        this -> stipendio = stipendio;
    }

    //getters
    string getNome() const{return nome;}
    string getCognome() const{return cognome;}
    string getId() const{return id;}
    float getStipendio() const{return stipendio;}

    bool operator==(const Dipendente& d)
    {
        return d.id == id;
    }

    friend istream& operator>>(istream& in,Dipendente& d)
    {
        cout<<"Inserire Nome: "; in>>d.nome;
        cout<<"Inserire Cognome: "; in>>d.cognome;
        cout<<"Inserire Id: "; in>>d.id;
        cout<<"Inserire Stipendio: "; in>>d.stipendio;
        return in;
    }

    friend ostream& operator<<(ostream& out,const Dipendente& d)
    {
        out<<"Nome Dipendente: "<<d.nome<<endl;
        out<<"Cognome Dipendente: "<<d.cognome<<endl;
        out<<"Id Dipendente: "<<d.id<<endl;
        out<<"Stipendio Dipendente: "<<d.stipendio<< "$"<<endl;      
        return out;
    }

};

#endif