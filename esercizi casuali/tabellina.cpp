#include <iostream>
using namespace std;

int main(){
	
	
	

	
	for(int r = 0; r <= 10;r++)
	{
		for(int c = 0; c <= 10;c++)
	    {
			if(r == 0 && c == 0)
			{
				cout<<"\t";
			}
			else if(r == 0)
		    {
				cout<<c<<"\t";
			}
			else if(c == 0)
			{
				cout<<r<<"\t";
			}
			else
			{
				cout<<r * c<<"\t";
			}
		    
	    }
		cout<<endl;
		
	}
	
	
	return 0;
}