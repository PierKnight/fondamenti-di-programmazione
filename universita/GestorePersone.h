#ifndef GESTORE_P_H
#define GESTORE_P_H


#include "Persona.h"
#include <unordered_map>

class GestorePersone
{
    protected:
    unordered_map<string,Persona*> persone;
    void clear();

    public:
    GestorePersone(){}
    ~GestorePersone();
    GestorePersone(const GestorePersone&);
    virtual GestorePersone& operator=(const GestorePersone&);
    virtual void stampa() const;
};

void GestorePersone::clear()
{
    for(auto pos = persone.begin();pos != persone.end();pos++)
        delete (*pos).second;
    persone.clear();
}

GestorePersone::~GestorePersone(){clear();}

GestorePersone::GestorePersone(const GestorePersone& other)
{
    clear();
    for(auto pos = other.persone.begin();pos != other.persone.end();pos++)
         persone.insert({(*pos).first,(*pos).second->newCopy()});
}

GestorePersone& GestorePersone::operator=(const GestorePersone& other)
{
    clear();
    for(auto pos = other.persone.begin();pos != other.persone.end();pos++)
         persone.insert({(*pos).first,(*pos).second->newCopy()});
    return *this;
}

void GestorePersone::stampa() const
{
    for(auto pos = persone.begin();pos != persone.end();pos++)
    {
        cout<<"-"<<(*(*pos).second);
    }
}  

#endif