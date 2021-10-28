#include <iostream>
#include "programmatore.h"
#include "cassert"
using namespace std;

const int numero = 5;


unsigned numeroProgrammatoriConNome(const string& nome,Programmatore programmatori[]);
float stipendioMedio(Programmatore programmatori[]);
const Programmatore& getJuniorPiuEsperto(Programmatore programmatori[]);
unsigned trovareLaDifferenzaDiEta(Programmatore programmatori[]);
bool anzianita(Programmatore programmatori[]);

int main()
{
	
	Programmatore programmatori[numero];
	
	for(int i = 0;i < numero;i++)
		cin>>programmatori[i];
	
	
	
	
	return 0;
}


//numero programmatori con lo stesso nome
unsigned numeroProgrammatoriConNome(const string& nome,Programmatore programmatori[])
{
	unsigned numero = 0;
	
	for(int i = 0;i < numero;i++)
		if(programmatori[i].getNome() == nome)
			numero++;
	return numero;
	
}

//restituire stipendio medio dei programmatori
float stipendioMedio(Programmatore programmatori[])
{
	float totale = 0;
	unsigned seniors = 0;
	
	for(int i = 0;i < numero;i++)
		if(programmatori[i].isSenior())
		{
			totale += programmatori[i].getStipendio();
			seniors++;
		}
	if(seniors == 0)
		return 0;
    return totale / seniors;
	
}

//restituire il programmatore non senior con più anni di esperienza
const Programmatore& getJuniorPiuEsperto(Programmatore programmatori[])
{
	unsigned anniMax = 0;
	int indice = -1;
	
	for(int i = 0;i < numero;i++)
	{
		if(!programmatori[i].isSenior() && programmatori[i].getAnniEsperienza() >= anniMax)
		{
			indice = i;
			anniMax = programmatori[i].getAnniEsperienza();
		}	
	}
	
	assert(indice != -1);
		
	return programmatori[indice];
			
}


//trovare la differenza di età tra quello più vecchio e quello più giovane
unsigned trovareLaDifferenzaDiEta(Programmatore programmatori[])
{
	unsigned minEta = programmatori[0].getEta();
	unsigned maxEta = programmatori[0].getEta();
	
	for(int i = 1;i < numero;i++)
	{
		if(programmatori[i].getEta() > maxEta)
			maxEta = programmatori[i].getEta();
		
		if(programmatori[i].getEta() < minEta)
			minEta = programmatori[i].getEta();	
	}


    return maxEta - minEta;
}

//ritorna true se tutti rispettano il criterio di anzianità
//ovvero ogni programmatore ha SEMPRE un reddito maggiore rispetto a quelli più giovani di lui
bool anzianita(Programmatore programmatori[])
{
	for(int i = 0;i < numero;i++)
	{
		
		unsigned stipendioC = programmatori[i].getStipendio();
		unsigned etaC = programmatori[i].getEta();
		
		for(int j = 0;j < numero;j++)
		{					
			if(programmatori[j].getEta() < etaC && stipendioC <= programmatori[j].getStipendio())
				return false;				
		}		
	}
	return true;
}


