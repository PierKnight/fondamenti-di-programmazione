#include <iostream>
using namespace std;

/**
 Scrivi un algoritmo che acquisisca una coppia di interi n ed m con n≥m che sia in grado di eseguire in modo ricorsivo il prodotto
n·(n-1) ·… ·m 

**/

int fact(int a,int b);

int main()
{
	
	
	int val1,val2;
	
	cin>>val1>>val2;
	
	
	if(val1 < val2)
	{
		cout<<"WEEE v1 deve essere maggiore di v2!"<<endl;
		return 0;
	}
	
	
	cout<<"Fattoriale da "<<val1<<" a "<<val2<<" = "<<fact(val1,val2)<<endl;
	
    return 0;
	
}

//a >= b
int fact(int a,int b)
{
	static int result = a;
	if(a <= b)
		return result;
	
	
	result = result * (a - 1);
	
	return fact(a - 1,b);
		
	
	
	
	
	
	
}