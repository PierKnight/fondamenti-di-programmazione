#include <iostream>
using namespace std;


const int dim = 10;

//nel caso di array di char si potrebbe fare direttamente cin>>array;
//ma lo faccio manualmente per provare

int main()
{
	
	
	char array[dim];
	
	cin>>array[0];
	int max = array[0];
	
	for(int i = 1;i < dim;i++)
	{
		
		cin>>array[i];
		
		if(array[i] > max)
			max = array[i];		
	}
	
	
	for(int i = 0;i < dim;i++)
	{
		int scarto = max - array[i];
		cout<<array[i]<<" ---->"<<scarto<<endl;
	}  
	
	
	return 0;
	
	
}