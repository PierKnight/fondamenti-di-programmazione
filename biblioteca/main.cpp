#include <iostream>
using namespace std;

#include <string>

#include "Dinamico.h"

//#include "Libro.h"

//int Libro::CONTATORE = 0;

int main()
{
    
	
	
	
	
	Dinamico<int> dinamico(2);
	
	

	
	int value;
	
	while(cin>>value && value != -1)
	{
		dinamico.aggiungi(value);
		
	}

	cout<<dinamico;
	
	cout<<"Valori Dim: "<<dinamico.getDim()<<endl;
	
	
	
	//Libro libro;
	
	//cin>>libro;
	
	//cout<<libro;
	
	
	//Libro libro;
	
	//cin>>libro;
	
	//cout<<libro;
	
	return 0;
}
