#include <iostream>
using namespace std;


double long pow(int a,int b);


int main()
{
	
	
	int number,p;
	cin>>number>>p;
	
	
	
	cout<<"La potenza di: "<< number<<" alla "<<p<<" = "<<pow(number,p)<<endl; 
	
	return 0;
}




double long pow(int a,int b)
{
	
	double long result = 1;
	
	for(int i = 0;i < b;i++)
		result *= a;
	
	return result;
	
}

