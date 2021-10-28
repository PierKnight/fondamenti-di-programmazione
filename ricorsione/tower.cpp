#include <iostream>
using namespace std;

int tower(int n,char from,char to,char aux);

//torre di hanoi
int main()
{

  int val;
  
  cout<<"Inserire Numero di dischi: ";
  cin>>val;
  
  
  
  
  int ciao = tower(val,'A','B','C');
  
  
  cout <<endl<<"Totale Passaggi: "<< ciao<<endl;
  return 0;

	
}




void muovi(int n, char from,char to)
{
	cout<<"Disco Mosso da rod: " << from<< " -> rod: "<<to<<endl;
		
}


int tower(int n,char from,char to,char aux)
{
	//se la pila da spostare è solo un pezzo allora si può tranquillamente portare in to;
	
	static int passi = 0;
	
	if(n == 1)
	{
		cout<<"Disco Mosso da rod: " << from<< " -> rod: "<<to<<endl;
	
		return ++passi;
	}
	
	//bisogna prima di tutto spostare la pila n - a verso aux
	
	tower(n-1,from,aux,to);
	
	//e adesso spostare da aux a to;
	
	 ++passi;
	
	cout<<"Disco Mosso da rod: " << from<< " -> rod: "<<to<<endl;
	
	
	tower(n-1, aux, to, from);
	
	
	
	
	
}