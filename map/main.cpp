#include "HashMap.h"
#include <unordered_map>
#include <random>
#include <ctime>
using namespace std;


class Persona
{
    public:
    string nome;

    Persona(string p):nome(p){}


    bool operator==(const Persona& p) const
    {
        return p.nome == this -> nome;
    }

};

struct HashPersona
{

    size_t operator()(const Persona& p)const
    {
        size_t h = std::hash<std::string>()(p.nome);
        return h;
    }

};

bool comp(int a,int b)
{
    return a < b;
}

int main()
{

    srand(time(0));

    HashMap<Persona,int,HashPersona> map;
    
    Persona p("LOLLA");

    map.put(p,100);
     map.put(p,200);

    int e = -1;
    cout<<map.find(p,e)<<endl;


    vector<int> l;

    for(int i = 0;i < 1000000;i++)
        l.push_back(rand()%100000);


    sort(l.begin(),l.end(),comp);


        cout<<"Fine"<<endl;









    return 0;
}