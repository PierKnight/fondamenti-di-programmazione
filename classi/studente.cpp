#include <iostream>
using namespace std;

#include "studente.h"


bool bestStudents(Studente studenti[], unsigned numeroStudenti);
unsigned numeroEsamiAllaLaurea(Studente studenti[], unsigned numeroStudenti);
bool stessiVoti(const Studente& s1,const Studente& s2);
string getMatricolaStudenteGiovaneEBravo(Studente studenti[],unsigned numeroStudenti);

int main()
{
    
	cout<<"Inserire numero studenti: ";
	
	int numeroStudenti;
	cin>>numeroStudenti;
	
	
	Studente* studenti = new Studente[numeroStudenti];
	
	
	
	for(int i = 0;i < numeroStudenti;i++)
		cin>>studenti[i];
	
	
	cout<<"Best Students: "<<bestStudents(studenti,numeroStudenti)<<endl;
    cout<<"Esami mancanti allo studente con più esami svolti: "<<numeroEsamiAllaLaurea(studenti,numeroStudenti)<<endl;
	cout<<"Stessi voti: "<<stessiVoti(studenti[0],studenti[1])<<endl;
	
	delete [] studenti;
	
	
	return 0;
}


//ritorna true soltanto se la media ponderata di tutti gli studenti sia maggiore o uguale a 28
bool bestStudents(Studente studenti[], unsigned numeroStudenti)
{
	for(int i = 0;i < numeroStudenti;i++)
		if(studenti[i].getMediaPonderata() < 28)
			return false;
	return true;
}


//ritorna il numero mancante di esami da finire, considerando lo studente con più esami svolti
//conta che il numero di esami totali sono 24
unsigned numeroEsamiAllaLaurea(Studente studenti[],unsigned numeroStudenti)
{
	
	unsigned esamiSvoltiMax = studenti[0].getEsamiSostenuti();
	
	for(int i = 1;i < numeroStudenti;i++)
		if(studenti[i].getEsamiSostenuti() > esamiSvoltiMax)
			esamiSvoltiMax = studenti[i].getEsamiSostenuti();
	
	return 24 - esamiSvoltiMax;
	
}

//restituisca true se e solo se gli studenti s1 ed s2 hanno ottenuto lo stesso numero di volte ogni votazione.
//Ad esempio, il metodo deve restituire true se s1 ha sostenuto l’esame di Inglese con voto pari a 27 e quello di Analisi con voto pari a 25,
//mentre s2ha sostenuto l’esame di Matematica Discreta con voto pari a 25 e quellodi Inglese con voto pari a 27.


//questo ha complessità nel caso peggiore O(n^2) non il massimo insomma
bool stessiVoti(const Studente& s1,const Studente& s2)
{
	//matematicamente impossibile avere lo stesso numero di voti se gli esami sostenuti non sono uguali
	if(s1.getEsamiSostenuti() != s2.getEsamiSostenuti())
		return false;
	
	unsigned count = s1.getEsamiSostenuti();
	
	for(int i = 0;i < count;i++)
	{
		unsigned voto = s1.getVoto(i);
		
		int totale1 = 0;
		int totale2 = 0;
		
		
		for(int j = 0;j < count;j++)
			if(s1.getVoto(j) == voto)
				totale1++;
	
		for(int j = 0;j < count;j++)
			if(s2.getVoto(j) == voto)
				totale2++;
			
		if(totale1 != totale2)
			return false;
	}
	
	return true;
		
}

string getMatricolaStudenteGiovaneEBravo(Studente studenti[],unsigned numeroStudenti)
{
	
	float mediaMax = -1;
	unsigned etaMin = -1;
	unsigned index = -1;
	
	for(int i = 0;i < numeroStudenti;i++)
	{
		Studente s = studenti[i];
		if(s.getEta() >= 20 && s.getEsamiSostenuti() >= 3)
		{
			int media = s.getMediaVoti();
			if(media > mediaMax)
			{
				mediaMax = media;
				etaMin = s.getEta();
				index = i;
			}
			else if(media == mediaMax && s.getEta() < etaMin)
			{
				etaMin = s.getEta();
				index = i;
			}
		}
	}
	
	if(index == -1)
		return "------";
	
	return studenti[index].getMatricola();
	
	
}




