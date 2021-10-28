#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include "Libro.h"

using namespace std;



class Cliente
{
    friend class Biblioteca;
    private:
      string nome,codice_fiscale;
      unsigned int codice;
      Libro* libro;

    public:
      static unsigned int contatore;

      Cliente()
      {
          nome = "";
          codice_fiscale = "";
          codice = contatore++;
          libro = nullptr;
      }

      Cliente(string nome,string codice_fiscale)
      {
          this -> nome = nome;
          this -> codice_fiscale = codice_fiscale;
          codice = contatore++;
          libro = nullptr;
      }

      //getters
      string getNome() const {return nome;}
      string getCodiceFiscale() const {return codice_fiscale;}
      unsigned int getCodice() const {return codice;}

      bool haLibro() const
      {
          return libro != nullptr;
      }

      friend istream& operator>>(istream& in,Cliente& c)
      {
          cout<<"Inserire Nome: ";in>>c.nome;
          cout<<"Inserire Codice Fiscale: ";in>>c.codice_fiscale;
          return in;
      }

      friend ostream& operator<<(ostream& os,const Cliente& c)
      {
          os<<"Nome: "<<c.nome<<endl;
          os<<"Codisce Fiscale: "<<c.codice_fiscale<<endl;
          os<<"Codice Cliente: "<<c.codice<<endl;

          if(c.haLibro())
              os<<(*c.libro);
          else
              os<<"Non ha un libro in prestito!"<<endl;
          

          return os;
      }

};


#endif