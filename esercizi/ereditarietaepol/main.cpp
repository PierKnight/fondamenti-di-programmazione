#include <iostream>
#include "Prodotto.h"

int Prodotto::CONTATORE = 0;

int main()
{
    Prodotto p("Ciccio");
    Prodotto p1("Pasticcio");
    Prodotto p2("YES!");
    p1.printInfo(std::cout);

    std::cout<<p1.getIdentity();
    return 0;
}