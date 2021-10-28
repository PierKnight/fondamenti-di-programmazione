#include <iostream>
using namespace std;

bool palindromo(const char a[],const int size);

const int lenght = 100;

//nel caso di array di char si potrebbe fare direttamente cin>>array;
//ma lo faccio manualmente per provare

int main()
{
	
	
	char c;
		
	int size = 0;
	
	char parola[lenght];
	
	
	while(cin>>c && c != '-' && size < lenght)
	{
		parola[size++] = c;
		
	}
	
	
	
	if(palindromo(parola,size))
		cout<<"Questa parola e' palindroma";
	else
		cout<<"Questa parola non e' palindroma";
	return 0;
	
	
}

bool palindromo(const char a[],const int size){
	
	for(int i = 0; i < size / 2;i++)
	{
		if(a[i] != a[size - i - 1])
			return false;
	}
	
	return true;
	
}