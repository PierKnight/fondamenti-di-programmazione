using namespace std;

#ifndef LIBRO_H
#define LIBRO_H


#include <string>
#include <iostream>
#include <vector>
#include "Codificato.h"

class Libro : public Codificato
{
    friend class Biblioteca;

    private:
    string nome;
    string casaEditrice;
    vector<string> autori;
    bool inPrestito;

    public:
        static unsigned int CONTATORE;

    Libro()
    {
        codice = CONTATORE++;
        nome = "";
        casaEditrice = "";
        inPrestito = false;
    }
    
    Libro(const string& nome,const string& casaEditrice)
    {
      codice = CONTATORE++;
      this -> nome = nome;
      this -> casaEditrice = casaEditrice;
      inPrestito = false;
    }
    
    //getters
    const string& getNome() const {return nome;}
    const string& getCasaEditrice() const {return casaEditrice;}
    bool isInPrestito() const {return inPrestito;}

    //setters
    void setInPrestito(bool prestito)
    {
        inPrestito = prestito;
    }
  
    void aggiungiAutore(string autore)
    {
        autori.push_back(autore);
    }

    friend istream& operator>>(istream& in,Libro& libro)
    {
        in.ignore();
        cout<<"Inserire Titolo: ";getline(in,libro.nome);
        cout<<"Inserire Casa Editrice: ";getline(in,libro.casaEditrice);

        string val;
        while(getline(in,val) && val != "-1")
            libro.aggiungiAutore(val);
        return in;
    }

    friend ostream& operator<<(ostream& os,const Libro& libro)
    {
      os<<"Titolo Libro: "<<libro.nome<<endl;
      os<<"Casa Editrice: "<<libro.casaEditrice<<endl;
      os<<"Codice Libro: "<<libro.codice<<endl;

      os<<"Autori: "; 
      for(int i = 0;i < libro.autori.size();i++)
          os<<libro.autori[i]<<" ";
      os<<endl;

      
      os<<"E' in prestito?: ";
      if(libro.inPrestito)
         os<<"Si"<<endl;
      else
         os<<"No"<<endl;
      
      os<<endl;

      return os;
    }
     
};

#endif
