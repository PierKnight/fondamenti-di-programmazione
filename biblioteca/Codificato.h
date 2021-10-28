#ifndef CODIFICATO_H
#define CODIFICATO_H

/*classe che definisce un oggetto con codice
il fatto che il counter nelle rispettive classi non sia diminuito nel destructor è voluto
perchè ha senso che se un nuovo libro sia inserito non abbia lo stesso codice di quello vecchio.
*/
class Codificato
{
protected:
    unsigned int codice;
public:
    Codificato(){}
    unsigned int getCodice() const;
};

unsigned int Codificato::getCodice() const
{
    return codice;
}


#endif
