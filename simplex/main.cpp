#include "Matrix.h"

using namespace std;

int main()
{

    Matrix e(3,3,0);


    
    e.readFromInput();

    Matrix inverse(e);

    cout<<e.det()<<endl;

    if(e.inverse(inverse))
        inverse.print();
    else
        cout<<"VOLEVI!";
        

    return 0;

}