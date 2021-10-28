#include <iostream>
using namespace std;

void inserisciDato(int& valore,int& counter);

int main(){
	
	
	
	int prec = 0,cur = 0,suc = 0;

	
	int index = 0;
    int numeroPicchi = 0;
	
	cin>>suc;
		
	
	while(suc >= 0)
	{
		index += 1;
			
		if(index >= 3 && cur > prec && cur > suc)
		{
			numeroPicchi += 1;			
			cout<<cur<<"\t"<<(index - 1)<<endl;
			
		}		
		prec = cur;
		cur = suc;
		
		
		cin>>suc;
		
		
	}
	
	
	cout<<"NUMERO PICCHI TOTALI: "<<numeroPicchi<<endl;
	cout<<"NUMERO TOTALE DATI: "<<index<<endl;
	
	
	
	return 0;
}


void inserisciDato(int& valore,int& counter)
{
	cout<<"Inserisci Valore Giornaliero: ";
	cin>>valore;
	counter += 1;
}
