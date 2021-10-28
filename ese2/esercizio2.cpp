#include <iostream>
using namespace std;


int main(){
	
	
		
	int val;
	
	cin>> val;
	
	
	
	int size = 0,maxSize = 0;
	
	int familyAmount = 0;
	
	while(val != -1)
	{
		if(val == 0)
		{
		   if(size > maxSize)
			{
				maxSize = size;
		    }
			
			familyAmount += 1;			
			size = 0;
			
		}
		else
		{
			size += 1;
		}
		
		
		cin>> val;
	
	}
	
	if(val != -1)
	   familyAmount += 1;	
	
	
	
	cout<<"CARDINALITA FAMIGLIE: "<<familyAmount<<endl;
	cout<<"FAMIGLIA MAX: "<<maxSize<<endl;
	
	
	
	return 0;
}

