#include <iostream>
using namespace std;

/**
 Scrivere un programma che sia in grado di stabilire se un dato numero intero è primo oppure no, utilizzando la ricorsione senza usare i cicli. 

**/

bool primo(int a);
bool primo(int i, int n);

int main()
{
	
	
	int val1;
	
	cin>>val1;
	
	
	
    
	cout<<"Il numero"<< val1<<" e' primo? "<< primo(2,val1)<<endl;
	
    return 0;
	
}


bool primo(int i, int n){
   cout<<i<<"\t "<<n%i<<endl;
   return n%i==0 ? n==i : primo(i+1,n);
}

bool primo(int a)
{
	
	if(a % 2 == 0)
		return false;
	
	
	static int i = 3;
	
	if(i >= a || a == 2 || a == 3)
		return true;
	
	
	
	if(a % i == 0)
		return false;
	
	
	
	cout<<i<<endl;
	
	
	i += 2;
	
	
	cout<<i<<endl;
	return primo(a);
		
	
	
	
}