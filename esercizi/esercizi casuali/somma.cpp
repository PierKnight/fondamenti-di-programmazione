#include <iostream>
using namespace std;

int main(){
	
	
	int input;
	int somma = 0;
	
	
	
	//termina quando avviene errore in questo caso se l'input non è un numero valido (ad esempio una stringa)
	while(cin>>input)
		somma += input;
	
	
	cout<<"Somma Totale"<<"\t"<<somma<<endl;
	
	
	return 0;
}