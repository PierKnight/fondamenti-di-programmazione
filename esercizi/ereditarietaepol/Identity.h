#ifndef IDENTITY_H
#define IDENTITY_H

#include <iostream>
#include <string>
#include <ctime>

class Identity
{
    private:
    int code;
    std::string name;

    public:
    //crea una nuova instanza dove il codice segue un counter
    Identity(std::string name,int& counter);
    //crea una nuova instanza dove invece genera il codice a random
    Identity(std::string name);
    int getCode() const;
    std::string getName() const;
    void printInfo(std::ostream&) const;

    //per definire che cosa sia effettivamente questa identità
    virtual std::string getIdentity() const = 0;
};


Identity::Identity(std::string name,int& counter)
{
    code = counter++;
    this -> name = name;
}

Identity::Identity(std::string name)
{
    srand(time(0));
    this -> name = name;
    code = rand() % 10000;
}

void Identity::printInfo(std::ostream& out) const
{
    out<<"Codice: "<<code<<std::endl;
    out<<"Nome: "<<name<<std::endl;
}

int Identity::getCode() const{return code;}

std::string Identity::getName() const {return name;}

#endif 