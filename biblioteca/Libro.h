#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
using namespace std;

#include <string>




class Libro
{
	
	
	friend istream& operator>>(istream& in,Libro& libro)
	{
		cout<<"Inserire Titolo Libro: "; in>>libro.nome;
		cout<<"Inserire Casa Editrice del Libro: "; in>>libro.casaEditrice;
		
		string val;
		
		cout<<"Inserire Autore: ";
		
		while(in>>val && val != "-1")
		{
			
			libro.aggiungiAutore(val);
			cout<<"Inserire Autore: ";
		}
		
		return in;
	}
	
	friend ostream& operator<<(ostream& out,Libro& libro)
	{
		out<<"Titolo Libro: "<<libro.nome<<endl;
		out<<"Casa Editrice Libro: "<<libro.casaEditrice<<endl;
		out<<"Codice Libro: "<<libro.codice<<endl;
		
		out<<"Autori: ";
		for(int i = 0;i < libro.sizeAutori;i++)
			out<<libro.autori[i]<<" , ";
		
		out<<endl;
		
		return out;
	}
	
	
	private:
	
	
	  const int INCREASE = 5;
	  
	  int codice;
	  
	  string nome;
	  string casaEditrice;
	  
	  //array autori
	  int sizeAutori;
	  int capAutori;
	  string* autori;
	  
	  bool prestato;
	
	public:
	  static int CONTATORE;
	  
	  Libro()
	  {
		  codice = CONTATORE++;
		  nome = "";
		  casaEditrice = "";
		  prestato = false;
		  capAutori = INCREASE;
		  autori = new string[capAutori];
		  sizeAutori = 0;
	  }
	
	  Libro(string nome,string casaEditrice)
	  {
		  codice = CONTATORE++;
		  this -> nome = nome;
		  this -> casaEditrice = casaEditrice;
		  prestato = false;
		  
		  capAutori = INCREASE;
		  autori = new string[capAutori];
		  sizeAutori = 0;

		  
	  }
	  
	  //distruttore
	  ~Libro()
	  {
		  delete [] autori;
		  
		  
		  cout<<"DISTRUGGI PRIMA CHE FINISCA MALISSIMO!";
	  }
	  
	  //getters
	  int getCodice(){return codice;}
	  string getNome() {return nome;}
	  string getCasaEditrice() {return casaEditrice;}
	  
	  void aggiungiAutore(string autore)
	  {
		  if(sizeAutori >= capAutori)
		  {
			  string* temp = new string[capAutori + INCREASE];
			  
			  for(int i = 0;i < sizeAutori;i++)
				  temp[i] = autori[i];
			  
			  delete [] autori;
			  
			  autori = temp;
			  
			  capAutori += INCREASE;
			  		  
		  }
		  
		  autori[sizeAutori++] = autore;
	  }
	  

};
#endif