#include <iostream>
using namespace std;

#include <cmath>


bool primo(int val);



int main(){
	
	
	
	
	cout<<"Inserire Numero: ";
	
	int numero;
	
	cin>>numero;
	
	cout<<"Primo: "<<to_string(primo(numero))<<endl;
	
	
	
	return 0;
}


bool primo(int val)
{
	
	if(val <= 3)
		return true;
	
	if(val % 2 == 0)
		return false;
	
	
	
	int valore = floor(sqrt(val));
	
	cout<<valore<<endl;
	
	
	for(int i = 3;i < valore;i += 2)
		if(val % i == 0)
			return false;
		
		
	return true;
	
	
	
}


