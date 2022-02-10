#include <iostream>
#include <list>
#include <assert.h>
using namespace std;

template<class T>
class Test : private list<T>
{

    public:
    Test(){}

    void push(T x){ list<T>::push_back(x);}

    T getAndRemove()
    {
        assert(!list<T>::empty());
        T value = list<T>::back();
        list<T>::pop_back();
        return value;
    }

    int size(){return list<T>::size();}

    T getTop(){return list<T>::back();}
};

int main()
{
    Test<int> e;

    e.push(5);
    e.push(2);
    e.push(3);


    cout<<e.getAndRemove()<<endl;

    cout<<e.size()<<endl;
}