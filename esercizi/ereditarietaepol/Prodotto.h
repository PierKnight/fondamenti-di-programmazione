#ifndef PROD_H
#define PROD_H
#include "Identity.h"



class Prodotto : public Identity
{

    public:
    static int CONTATORE;
    Prodotto(std::string name):Identity(name,CONTATORE){};

    std::string getIdentity() const {return "prodotto";}
};




#endif