#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


enum Tipo {ESPLOSIVO = 0,AUTOMATICO = 1};
class Arma
{
    protected:
    string nome;
    int proiettili;
    Tipo tipo;

    public:
    Arma(string _nome,Tipo _tipo):nome(_nome),proiettili(0),tipo(_tipo){}

   
    virtual void printStats(ostream& out)const
    {
        out<<"Nome: "<<nome<<endl;
        out<<"Potenza: "<<potenza()<<endl;
        out<<"Precisione: "<<precisione()<<endl;
        out<<getProiettili()<<" / "<<capienza()<<endl;
    }

    virtual float potenza() const = 0;
    virtual float precisione() const = 0;
    virtual int capienza() const = 0;
    
    int getProiettili() const { return proiettili; }

    void ricarica(){ proiettili = capienza();}
    virtual void spara() { if(proiettili > 0)--proiettili;}

    friend ostream& operator<<(ostream& out,const Arma& a)
    {
        a.printStats(out);
        if(a.tipo == ESPLOSIVO)
          out<<"BOOBO"<<endl;
        return out;
    }
};


class Bazooka : public Arma
{
    public:
    Bazooka():Arma("bazooka",ESPLOSIVO){ricarica();}


    float potenza() const{
        return 100;
    }
    float precisione() const
    {
        return 0.2F;
    }
    int capienza()const
    {
        return 1;
    }

    virtual void printStats(ostream& out)const
    {
        Arma::printStats(out);
        out<<"Descrizione: FA MOLTO MALE"<<endl;
    }


};

class AK47 : public Arma
{
    public:
    AK47():Arma("ak47",AUTOMATICO){ricarica();}

    float potenza() const{
        return 50;
    }
    float precisione() const
    {
        return 0.8F;
    }
    int capienza()const
    {
        return 1000;
    }
};

int main()
{
    vector<Arma*> armi;

    Bazooka g1;
    AK47* g2 = new AK47();

    armi.push_back(&g1);
    armi.push_back(g2);

    for(Arma* a : armi)
        a -> printStats(cout);

    armi[0] -> spara();

    for(Arma* a : armi)
        a -> printStats(cout);



    delete g2;

    return 0;
}