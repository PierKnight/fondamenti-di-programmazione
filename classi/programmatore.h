#include <iostream>
using namespace std;
#include <string>


#ifndef PROGRAMMATORE_H
#define PROGRAMMATORE_H


class Programmatore
{
	
	private:
	  string nome;
	  unsigned eta,stipendio,anni_esperienza;
	  bool senior;
	
	
	public:
      //il costruttore di copia non è necessario visto che questa classe contiene solo dati e bon causa gravi problemi copiarli superficialmente;
	
	  void setNome(string nome){ this -> nome = nome;}
	  void setEta(unsigned eta){ this -> eta = eta;}
	  void setStipendio(unsigned stipendio){ this -> stipendio = stipendio;}
	  void setAnniEsperienza(unsigned anni_esperienza){ this -> anni_esperienza = anni_esperienza;}
	  void setSenior(bool senior){ this -> senior = senior;}
	  
	  //getter
	  string getNome() const {return nome;}
	  unsigned getEta() const {return eta;}
	  unsigned getStipendio() const {return stipendio;}
	  unsigned getAnniEsperienza() const {return anni_esperienza;}
	  bool isSenior() const {return senior;}
	  
	  friend istream& operator>>(istream& in,Programmatore& p)
	  {
		  cout<<"Inserire Nome: "; in>>p.nome;		  
		  cout<<"Inserire Eta: "; in>>p.eta;		  
		  cout<<"Inserire Stipendio: "; in>>p.stipendio;		  
		  cout<<"Inserire Anni Esperienza: "; in>>p.anni_esperienza;		  
		  cout<<"Inserire Senior (0 se non e' senior): "; in>>p.senior;		  	  
		  return in;
	  }
	  
	  friend ostream& operator<<(ostream& out,const Programmatore& p)
	  {
		  out<<"Nome: "<<p.nome<<endl;
		  out<<"Eta: " <<p.eta<<endl;
		  out<<"Stipendio: " <<p.stipendio<<endl;
		  out<<"Anni Esperienza: " <<p.anni_esperienza<<endl;	  
		  if(p.senior)
			  out<<"Senior: si"<<endl;
		  else
			  out<<"Senior: no"<<endl;
		  return out;
	  }
};

#endif


