#include <iostream>
using namespace std;


int log(int,int);


int main()
{
	
	
	int base,n;
	cin>>base>>n;
	
	
	
	cout<<"Log base : "<< base<<" di "<<n<<" = "<<log(base,n)<<endl; 
	
	return 0;
}


int log(int base,int numero)
{
	
	//log3 9 = 2
	
	
    if(base == 0)
		return -1;
	
	
	int count = 0;
	int mul = 1;
	while(mul <= numero)
	{
		
		mul *= base;
		
		count +=1;
	}
	if(mul > numero)
		return count - 1;
	
	
	return count;
	
}


