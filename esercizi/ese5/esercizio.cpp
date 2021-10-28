#include <iostream>
using namespace std;



void insertValue(int& val);
void instogramma(int x);

int main(){
	
	
	
	
	
	
	
	int val;
	
	insertValue(val);
	
	while(val >= 0)
	{
		instogramma(val);
		cin>>val;
	}
	
	
	return 0;
}


void insertValue(int& val)
{
	
	cout<<"Inserisci Valore: ";
	cin>>val;
}


//somma più volte fino a y volte x con result
void instogramma(int x )
{
	
	for(int i = 0;i < x;i++)
		cout<<"*";
	
	cout<<endl;
	
}
