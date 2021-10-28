#include <iostream>
using namespace std;

//Scrivi un metodo ricorsivo chiamandolo sd() che accetta un numero positivo intero n dispari e restituisce la somma di interi dispari da 1 a n. 

int sd(int x);

int main()
{
	
	
	int val1;
	
	cin>>val1;
	
	
	if(val1 % 2 == 0)
	{
		cout<<"WEEE l'ìnput deve essere dispari!"<<endl;
		return 0;
	}
	
	
	cout<<"Somma da 1 a "<<val1<<" = "<<sd(val1)<<endl;
	
    return 0;
	
}


int sd(int x)
{
	static int somma = 0;
	
	
	if(x <= 0)
		return somma;
	
	
	somma += x;
	
	return sd(x - 2);
	
	
	
	
	
	
	
}