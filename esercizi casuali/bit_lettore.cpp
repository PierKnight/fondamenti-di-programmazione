#include <iostream>
using namespace std;


int main()
{
	int amount;
	
	int numero;
	cin>>numero;
	
	
	
	
	
	int totale = 0;
	
	while(numero != 0)
	{
		int bit = numero & 1;
		if(bit == 1)
			++totale;
		
		numero = numero >> 1;
				
	}
	
	cout<<"Il numero ha "<<totale<<" 1"<< endl;
	
   
   return 0;
		
	
}
