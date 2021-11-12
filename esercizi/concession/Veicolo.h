#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>
#include <string>
using namespace std;

class Veicolo
{
    private:
    string targa;
    float prezzo;
    string casaProduttrice;
    string nome;

    public:
    Veicolo(string _targa,float _prezzo,string _casa,string _nome):targa(_targa),prezzo(_prezzo),casaProduttrice(_casa),nome(_nome){}

    string getTarga() const {return targa;}
    string getCasaProduttrice() const {return casaProduttrice;}
    string getNome() const {return nome;}
    virtual float getPrezzo() const{return prezzo;}

    friend ostream& operator<<(ostream& out,const Veicolo& v)
    {
        return v.print(out);
    }

    virtual Veicolo* clone() const = 0;

   
    virtual string getTipoVeicolo() const = 0;

    protected:
    ostream& print(ostream& out) const
    {
        out<<"["<<targa<<"]"<<", Prezzo:"<<prezzo<<" , Nome: "<<nome<<" , Casa Produttrice: "<<casaProduttrice<<endl;
        return out;
    }



    


};

#endif