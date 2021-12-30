#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct PilotaF1
{
    int codice;
    string nome;
    string squadra;

    PilotaF1(int _codice,string _nome,string sq):codice(_codice),nome(_nome),squadra(sq){}


    bool operator==(const PilotaF1& p) const
    {
        return p.codice == this -> codice;
    }

};

template <class T>
class Classifica
{
    vector<T> a;
    vector<int> points;

    void update(int index)
    {
        for(int i = index;i > 0;i--)
        {
            if(points[i - 1] < points[i])
            {
                T temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;

                int temp2 = points[i];
                points[i] = points[i - 1];
                points[i - 1] = temp2;
            }
        }

    }

    
    public:
    Classifica(){}


    void aggiorna(const T& s,int punto)
    {
        auto it = find(a.begin(),a.end(),s);
        if(it != a.end())
        {
            points[it - a.begin()] += punto;
            update(it - a.begin());
        }
        else
        {
        a.push_back(s);
        points.push_back(punto);
        update(a.size() - 1);
        }
    }

    int getPunti(int pos) const
    {
        return points[pos];
    }

    T getElemento(int pos) const
    {
        return a[pos];
    }

    int size() const {return a.size();}

    
};

class Campionato
{
    private:
    Classifica<string> squadre;
    Classifica<PilotaF1> piloti;
    
    vector<string> partecipazioni;


    public:
    Campionato(){}


    

    void aggiungiPilota(string gara,PilotaF1 pilota,int pos)
    {
        string part = gara + to_string(pilota.codice);
        if(find(partecipazioni.begin(),partecipazioni.end(),part) != partecipazioni.end()) return;

        partecipazioni.push_back(part);

        int punti = pos <= 10 ? 11 - pos : 0;

        piloti.aggiorna(pilota,punti);
        squadre.aggiorna(pilota.squadra,punti);

    }

    void stampaClassificaPiloti() const
    {
        for(int i = 0;i < piloti.size();i++)
            cout<<piloti.getElemento(i).nome<<" - "<<piloti.getPunti(i)<<endl;
    }

    void stampaClassificaSquadre() const
    {
        for(int i = 0;i < squadre.size();i++)
            cout<<squadre.getElemento(i)<<" - "<<squadre.getPunti(i)<<endl;
    }

    string getPilotaClassifica(int pos)
    {
        return piloti.getElemento(pos).nome;
    }

};

int main()
{
    Campionato camp;

    PilotaF1 pilota1(1,"Pierluigi","RossI!!");
    PilotaF1 pilota2(2,"Luigi","Verdi!!");
    PilotaF1 pilota3(3,"Mario","Verdi!!");
    
    camp.aggiungiPilota("sos",pilota1,4);
    camp.aggiungiPilota("sos",pilota2,2);
    camp.aggiungiPilota("sos",pilota3,1);
    camp.stampaClassificaPiloti();
    camp.stampaClassificaSquadre();

    return 0;
}