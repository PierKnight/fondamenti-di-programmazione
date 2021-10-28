#include <iostream>
using namespace std;

//Dire quante volte un numero è divisibile per un altro tramite un metodo ricorsivo. 
int divAmount(int a,int b);



//questo utilizza la variabile statica come contatore
int divAmount(int a,int b);


//questo usa come contatore un argomento
int divAmount(int a,int b,int counter);

int main()
{
	
	
	int val1,val2;
	
	cin>>val1>>val2;
	
	
	
	cout<<"Il numero "<<val1<< " e' divisibile "<<divAmount(val1,val2,0)<<" volta con "<< val2;
	
    return 0;
	
}



int divAmount(int a,int b)
{
	static int amount = 0;
	
	if(a % b == 0)
	{
		++amount;
		return divAmount(a / b,b);
	}
	return amount;
	
	
}

int divAmount(int a,int b,int counter)
{
	
	if(a % b == 0)
		return divAmount(a / b,b,counter + 1);
	
	return counter;
}