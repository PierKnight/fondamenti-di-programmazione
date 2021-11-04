#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class List;

template <class T>
class Iterator;

template <class T>
class Node
{
  
  
    friend class List<T>;
    friend class Iterator<T>;

    private:
    Node<T>* next;
    Node<T>* back;
    T value;

    public:
    Node(T v): back(nullptr),next(nullptr),value(v){}
    T getValue() const {return value;}


};

#endif
