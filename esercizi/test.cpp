#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include "Combinazione.h"
#include <unordered_map>

using namespace std;


bool te(int i)
{
    return i > 5;
}

int main()
{
    list<int> vec = {7,2,11,4,5};

    //remove(vec.begin(),vec.end(),te);

    

    auto pos = vec.begin();

    int size = vec.size();
    

    vec.erase(remove_if(vec.begin(),vec.end(),te),vec.end());

    //for(auto pos = vec.begin();pos != vec.end();pos++)
    //cout<<*pos<<endl;


    int** matrix = new int*[4];

    for(int i = 0;i < 4;i++)
    {
        matrix[i] = new int[4];
        for(int j = 0;j < 4;j++)
           matrix[i][j] = 2;
    }

    for(int i = 0;i < 4;i++)
      delete [] matrix[i];

    delete [] matrix;


    Combinazione test(14,3);


    unordered_map<string,int> map;


    map["eeee"] = 1;

    map.erase("eeee");
    if(map.find("eeee") == map.end())
        cout<<"Non found!"<<endl;

    





    return 0;
   
    
}

