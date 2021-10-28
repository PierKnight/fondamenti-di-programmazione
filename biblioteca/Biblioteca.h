#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H


#include <iostream>
#include <vector>
#include "Cliente.h"
#include "Libro.h"

using namespace std;

class Biblioteca
{
    vector<Cliente> clienti;
    vector<Libro> libri;

    public:
       void aggiungereCliente(Cliente& cliente)
       {
            clienti.push_back(cliente);
       }

       void aggiungereLibro(Libro& libro)
       {
            libri.push_back(libro);
       }

       const Libro* getLibro(const unsigned int codice) const
       {
           for(int i = 0;i < libri.size();i++)
              if(libri[i].getCodice() == codice)
                  return &libri[i];
           return nullptr;
       }
       const Libro* getLibro(const string titolo) const
       {
           for(int i = 0;i < libri.size();i++)
              if(libri[i].getNome() == titolo)
                  return &libri[i];
           return nullptr;
       }

       Cliente* getCliente(const unsigned int codice)
       {
           for(int i = 0;i < clienti.size();i++)
              if(clienti[i].getCodice() == codice)
                  return &clienti[i];
           return nullptr;
       }
       Cliente* getCliente(string codice_fiscale)
       {
           for(int i = 0;i < clienti.size();i++)
              if(clienti[i].getCodiceFiscale() == codice_fiscale)
                  return &clienti[i];
           return nullptr;
       }

       //tenta di prestare un libro a cliente
       //se cliente ha già un libro oppure il libro è in prestito ritorna false.
       bool presta(Cliente& cliente,Libro& libro)
       {
          if(!libro.isInPrestito() && !cliente.haLibro())
          {
             libro.setInPrestito(true);
             cliente.libro = &libro;
             return true;
          }
          return false;

       }

       bool presta(string codice_fiscale,Libro& libro)
       {
           Cliente* c = getCliente(codice_fiscale);
           if(c != nullptr)
               return presta(*c,libro);
           return false;
       }

       bool riconsegna(Cliente& cliente)
       {
           if(cliente.haLibro())
          {
              cliente.libro -> setInPrestito(false);
              cliente.libro = nullptr;
              return true;
          }
          return false;
       }

       void infoClienti()
       {
           for(int i = 0;i < clienti.size();i++)
           {
               if(clienti[i].haLibro())
               {
                   cout<<"Cliente "<<clienti[i].getCodice()<<" ha un libro in prestito: "
                   <<clienti[i].libro -> getNome()
                   <<endl;
               }
           }
       }

       void infoLibri()
       {
           for(int i = 0;i < clienti.size();i++)
           {
               if(clienti[i].haLibro())
               {
                   cout<<"Libro preso in prestito da "<<clienti[i].getNome()<<" Codice fiscale: "<<clienti[i].getCodiceFiscale()<<endl;
               }
           }
       }


       friend ostream& operator<<(ostream& os,const Biblioteca& b)
       {
           os<<"Totale Libri: "<<b.libri.size()<<endl;
           os<<"Totale Clienti: "<<b.clienti.size()<<endl;
           return os;
       }


};


#endif