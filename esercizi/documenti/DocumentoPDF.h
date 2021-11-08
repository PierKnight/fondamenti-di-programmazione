#ifndef PDF_H
#define PDF_H

#include "Documento.h"

class DocumentoPDF : public Documento
{
    private:
      bool firmato;

    public:
    DocumentoPDF(std::string a,std::string b,unsigned int c):Documento(a,b,c){ firmato = false;}
    bool isFirmato() const {return firmato;}
    void setFirmato(bool firmato){this -> firmato = firmato;}

    std::string getTipo() const {return "pdf";}

    Documento* newDocument()
    {
      return new DocumentoPDF(*this);
    }

};

#endif