#include <iostream>
using namespace std;



int sum(int x,int y);
int mul(int x ,int y);

int main(){
	
	
	
	
	int a,b;
	
	
	cin>>a>>b;
	
	
	cout<<mul(a,b)<<endl;
	
	return 0;
}

//somma
int sum(int x,int y)
{
	return x + y;
}



//somma più volte fino a y volte x con result
int mul(int x ,int y)
{
	int result = 0;
	
	for(int i = 0;i < y;i++)
		result = sum(result,x);
	return result;
}
