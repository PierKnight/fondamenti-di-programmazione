#ifndef GESTORE_DOC_H
#define GESTORE_DOC_H

#include <list>
#include "Documento.h"

bool ordinaPerProprietario(Documento* d1,Documento* d2)
      {
          return d1 -> getProprietario() < d2 -> getProprietario();
      }

      bool ordinaPerDescrizione(Documento* d1,Documento* d2)
      {
          return d1 -> getDescrizione() < d2 -> getDescrizione();
      }

      bool ordinaPerDimensione(Documento* d1,Documento* d2)
      {
          return d1 -> getDimensione() < d2 -> getDimensione();
      }

class GestoreDocumenti
{
    private:
      std::list<Documento*> documenti;
    public:
      GestoreDocumenti(){}

      //per poter creare una nuova instanza a seconda dei figli
      GestoreDocumenti(const GestoreDocumenti& d)
      {
          for(auto pos = d.documenti.begin();pos != d.documenti.end();pos++)
              documenti.push_back((**pos).newDocument());
      }
      ~GestoreDocumenti()
      {
           for(Documento* doc : documenti)
               delete doc;
      }

      void aggiungiDocumento(Documento* documento)
      {
          documenti.push_back(documento);
      }

      void rimuoviDocumento(Documento* documento)
      {
          for(auto pos = documenti.begin();pos != documenti.end();pos++)
             if(*pos == documento)
             {
                 delete *pos;
                 documenti.erase(pos);
                 return;
             }
      }


      void stampaDocumenti()
      {
          for(Documento* test : documenti)
          {
              std::cout<<"Proprietario: "<<test->getProprietario()<< " , ";
              std::cout<<"Descrizione: "<<test -> getDescrizione()<<" , tipo: "
              <<test -> getTipo()<<" , "<<test<<std::endl;
          }
      }

      



      void ordinaElementi(int criterio)
      {
          
          switch (criterio)
          {
          case 1:
              documenti.sort(ordinaPerProprietario);
              break;
          case 2:
              documenti.sort(ordinaPerDescrizione);
              break;
          case 3:
              documenti.sort(ordinaPerDimensione);
              break;
          default:
              break;
          }
          

      }
      
      



};

#endif