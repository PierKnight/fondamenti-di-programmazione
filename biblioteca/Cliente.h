
using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include "Libro.h"
#include "Codificato.h"

class Cliente : public Codificato
{
    friend class Biblioteca;
    private:
      string nome,codice_fiscale;
      Libro* libro;
    public:
      static unsigned int CONTATORE;

      Cliente()
      {
          codice = CONTATORE++;
          nome = "";
          codice_fiscale = "";
          libro = nullptr;
      }

      Cliente(const string& nome,const string& codice_fiscale)
      {
          codice = CONTATORE++;
          this -> nome = nome;
          this -> codice_fiscale = codice_fiscale;
          libro = nullptr;
      }

      //getters
      const string& getNome() const {return nome;}
      const string& getCodiceFiscale() const {return codice_fiscale;}

      bool haLibro() const
      {
          return libro != nullptr;
      }

      friend istream& operator>>(istream& in,Cliente& c)
      {
          in.ignore();
          cout<<"Inserire Nome: "; getline(in,c.nome);
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