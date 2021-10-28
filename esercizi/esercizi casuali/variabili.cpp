#include <iostream>
using namespace std;

const unsigned int COSTANTE = 10;

bool flag = false;

const string parola_importante = "Assomiglia un casino a java!";


int main()
{
	const int COSTANTE = 5;
	
	int input;
	string spam;
	
	cin>>input>>spam;
	int i = 0;
	while(i++ < input)
		cout<<spam<<"\n";
	
	return 0;

}