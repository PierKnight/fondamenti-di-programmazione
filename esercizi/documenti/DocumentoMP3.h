#ifndef MP3_H
#define MP3_H

#include "Documento.h"

class DocumentoMP3 : public Documento
{
    private:
      float durata;

    public:
    DocumentoMP3(std::string a,std::string b,int c,float d):Documento(a,b,c){ this -> durata = d;}
    float getDurata() const {return durata;}
    void setDurata(float durata){this -> durata = durata;}

    std::string getTipo() const {return "mp3";}

    Documento* newDocument()
    {
      return new DocumentoMP3(*this);
    }

};

#endif