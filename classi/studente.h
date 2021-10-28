#ifndef STUDENTE_H
#define STUDENTE_H

#include <iostream>
#include <string>
using namespace std;

class Studente
{
	  
	friend istream& operator>>(istream& in,Studente& s)
	{
		cout<<"Inserisci matricola: "; in>>s.matricola;
		cout<<"Inserisci eta: "; in>>s.eta;
		
		cout<<"Aggiungere Esami Svolti? 1 per si"<<endl;
		
		bool flag;
		cin>>flag;
		if(flag)
		{
			
			do
			{		
			  string nome;
			  unsigned voto;
			  unsigned cfu;
			
			  cout<<"Inserisci nome esame: "; in>>nome;
			  
			  if(nome == "stop")
				  return in;
			  
		      cout<<"Inserisci voto esame: "; in>>voto;
			  cout<<"Inserisci cfu esame: "; in>>cfu;
			
			  flag = s.aggiungiEsame(nome,voto,cfu);
			}
			while(flag);
			
		}
	
		
		
	    return in;
	}
	  
	friend ostream& operator<<(ostream& out,Studente& s)
	{
		out<<"Matricola: "<<s.matricola<<endl;
		out<<"Eta: "<<s.eta<<endl;
		out<<"Esami Sostenuti: "<<s.esami_sostenuti<<endl;
		
		for(int i = 0;i < s.esami_sostenuti;i++)
		{
			out<<"Esame Sostenuto: "<<s.nomiEsami[i]
			<<" ,Voto: "<<s.votiEsami[i]
			<<" ,CFU: "<<s.cfuEsami[i]
			<<endl;		
		}
		
		
		
	    return out;
	}
	
	
	private:
	  string matricola;
	  unsigned eta,esami_sostenuti;
	  
	  string nomiEsami[24];
	  unsigned votiEsami[24];
	  unsigned cfuEsami[24];
	  
	  
	public:
	   
	  Studente()
      {
		 matricola = "";
		 eta = 0;
		 esami_sostenuti = 0;
	  }
	
	  Studente(string matricola,unsigned eta)
	  {
		  this -> matricola = matricola;
		  this -> eta = eta;
		  esami_sostenuti = 0;
	  }
	  
	  
	  string getMatricola() const { return matricola;}
	  unsigned getEta() const { return eta;}
	  unsigned getEsamiSostenuti() const { return esami_sostenuti;}
	  
	  void setMatricola(string matricola){ this -> matricola = matricola;}
	  void setEta(unsigned eta){ this -> eta = eta;}
	  void setEsamiSostenuti(unsigned esami_sostenuti){ this -> esami_sostenuti = esami_sostenuti;}
	  
	  //ritorna false se non è stato possibile aggiungere l'esame 
	  bool aggiungiEsame(string nome,unsigned voto,unsigned cfu)
	  {
		  if(esami_sostenuti >= 24)
			  return false;
		  
		  nomiEsami[esami_sostenuti] = nome;
		  votiEsami[esami_sostenuti] = voto;
		  cfuEsami[esami_sostenuti] = cfu;
		  esami_sostenuti++;
		  return true;
		  	  
	  }
	  
	  void rimuoviUltimoEsame()
	  {
		  if(esami_sostenuti > 0)
			  esami_sostenuti--;
	  }
	  
	  
	  unsigned getVoto(int indice) const
	  {
		  if(indice >= esami_sostenuti)
			  return 0;
		  
		  return votiEsami[indice];
	  }
	  
	  unsigned getVotoPiuBasso() const
	  {
		  int voto = votiEsami[0];
		  for(int i = 1;i < esami_sostenuti;i++)
			  if(votiEsami[i] < voto)
				  voto = votiEsami[i];		  
		  return voto;
	  }
	  
	  unsigned getVotoPiuAlto() const
	  {
		  int voto = votiEsami[0];
		  for(int i = 1;i < esami_sostenuti;i++)
			  if(votiEsami[i] > voto)
				  voto = votiEsami[i];		  
		  return voto;
	  }
	  
	  float getMediaVoti() const
	  {
		  if(esami_sostenuti == 0)
			  return 0;
		  
		  float somma = 0;
		  for(int i = 0;i < esami_sostenuti;i++)
			  somma += votiEsami[i];
		  
		  return somma / esami_sostenuti;
	  }
	  
	  float getMediaPonderata() const
	  {
		  if(esami_sostenuti == 0)
			  return 0;
		  
		  float somma = 0;
		  float sommaCfu = 0;
		  for(int i = 0;i < esami_sostenuti;i++)
		  {
			  somma += votiEsami[i] * cfuEsami[i];
			  sommaCfu += cfuEsami[i];
		  }
		  return somma / sommaCfu;
	  }
	  
	  
	  
	
	
};

#endif