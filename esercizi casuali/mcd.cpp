#include <iostream>
using namespace std;

#including <cmath>

int mcd(int m,int n);


int main(){
	
	
	
	int n1,n2;
	cin>>n1>>n2;
	
	
	
	
	n1 = abs(n1);
	n2 = abs(n2);
	
	
	//giusto per girare i valori se necessario
	if(n2 > n1)
	{
		int v = n1;
		n1 = n2;
        n2 = v; 		
	}
	
	
	
	cout<<"Massimo comun divisore: "<< mcd(n1,n2)<<endl;
	
	return 0;
	
}


int mcd(int m,int n)
{
	
	int r = m % n;
	int q = m / n;
	
	if(r == 0)
		return n;
	
	
	return mcd(n,r);
	
}
