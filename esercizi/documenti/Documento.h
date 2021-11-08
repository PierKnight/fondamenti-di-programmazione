#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <iostream>
#include <string>

class Documento
{
    private:
    std::string proprietario;
    std::string descrizione;
    unsigned int dimensione;

    public:
    Documento(std::string a,std::string b,unsigned int c):proprietario(a),descrizione(b),dimensione(c){}
   
    const std::string& getProprietario() const {return proprietario;}
    const std::string& getDescrizione() const {return descrizione;}
    int getDimensione() const {return dimensione;}

    virtual Documento* newDocument() = 0;
    virtual std::string getTipo() const = 0;

};

#endif