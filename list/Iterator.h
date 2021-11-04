#ifndef LINK_ITERATOR
#define LINK_ITERATOR

#include <iostream>
#include "List.h"

template<class T>
class Iterator
{
    protected:
    List<T>& l;
    Node<T>* curr;

    public:
    Iterator(List<T>& le): l(le),curr(le.start){}

    T getValue(){return curr ->value;};


    void setValue(const T& val)
    {
        if(curr != nullptr)
             curr -> value = val;
    }

    void begin()
    {
        curr = l.start;
    }

     void end()
    {
        curr = l.end;
    }

    bool operator!(){return curr != nullptr;}

    T operator*(){return getValue();}
    void operator++(){if(curr != nullptr) curr = curr ->next;}
    void operator--(){if(curr != nullptr) curr = curr ->back;}

    void remove()
    {
        if(curr == nullptr)return;

     
        //collego i due elementi
        if(curr->back != nullptr)
           curr->back ->next = curr -> next;
        if(curr->next != nullptr)
           curr->next ->back = curr -> back;

        //aggiorno la lista
        if(curr == l.start)
           l.start = l.start->next;
        else if(curr == l.end)
           l.end = l.end -> back;
        //elimino il vecchio
        Node<T>* tmp = curr;
        curr = curr -> next;
        delete tmp;
        l.size--;
    }


};

#endif