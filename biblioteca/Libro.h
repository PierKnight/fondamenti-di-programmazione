#ifndef LIBRO_H
#define LIBRO_H


#include <string>
#include <iostream>
#include <vector>
using namespace std;



class Libro
{
    friend class Biblioteca;

    private:
    string nome;
    string casaEditrice;
    unsigned int codice;
    vector<string> autori;
    bool inPrestito;

    public:
    static unsigned int contatore;


    Libro()
    {
        codice = Libro::contatore++;
        nome = "";
        casaEditrice = "";
        inPrestito = false;
    }
    
    Libro(string nome,string casaEditrice)
    {
      this -> nome = nome;
      this -> casaEditrice = casaEditrice;
      codice = Libro::contatore++;
      inPrestito = false;
    }

    //getters
    string getNome() const {return nome;}
    string getCasaEditrice() const {return casaEditrice;}
    unsigned int getCodice() const {return codice;}
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
        cout<<"Inserire Titolo: ";in>>libro.nome;
        cout<<"Inserire Casa Editrice: ";in>>libro.casaEditrice;

        string val;
        while(in>>val && val != "-1")
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
