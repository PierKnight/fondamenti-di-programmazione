#include <iostream>
using namespace std;

#include "punto.h"



void resetVariable(int & valore);

int main()
{
	
	punto punto1,punto2;
	
	punto1.x = 0;
	punto1.y = 0;
	
	punto2.x = 1;
	punto2.y = 1;
	
	
	punto* indirizzo = &punto1;
	
	cout<<indirizzo<<endl;
	
	cout<<distanza(punto1,punto2)<<endl;
	
    return 0;
}


void resetVariable(int& valore)
{
	valore = 0;
}