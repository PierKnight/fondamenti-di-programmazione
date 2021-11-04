#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"
using namespace std;


template <class T>
class Iterator;

template <class T>
class List
{
    friend class Iterator<T>;

    protected:
    Node<T>* start;
    Node<T>* end;
    int size;

    Node<T>* newNode(const T& v);

    public:
    List():start(nullptr),end(nullptr),size(0){}


    //distruttore
    ~List();

    void pushFront(const T&);
    void pushBack(const T&);
    bool popFront(T&);
    bool popBack(T&);

    bool find(const T&);
    bool empty(){return start == nullptr;}
    void print();
    int getSize(){return size;}

    
};

template <class T>
List<T>::~List()
{
    if(start == nullptr)
        return;
        
    Node<T>* node = start;
    while(node != nullptr)
    {
        Node<T>* tmp = node;
        node = tmp -> next;
        //cout<<"destroy"<<tmp<<endl;
        delete tmp;        
        
    }
}

template<class T>
Node<T>* List<T>::newNode(const T& value){return new Node<T>(value);}

template <class T>
void List<T>::pushFront(const T& value)
{
    Node<T>* node = newNode(value);
    if(start == nullptr) //se è vuota la lista si aggiunge direttamente
    {
        start = node;
        end = node;
    }
    else //altrimenti si collegano il primo corrente e il nuovo nodo, e solo dopo si aggiorna il primo elemento della lista
    {
        start->back = node;
        node->next = start;
        start = node;
    }
    size++;
}

template <class T>
void List<T>::pushBack(const T& value)
{
    Node<T>* node = newNode(value);
    if(start == nullptr)
    {
        start = node;
        end = node;
    }
    else
    {
        end->next = node;
        node->back = end;
        end = node;
    }
    size++;
}

template <class T>
bool List<T>::popFront(T& v)
{
    if(start == nullptr)
        return false;
    
    //prendo il valore del primo elemento
    v = start -> value;
    //faccio una copia
    Node<T>* tmp = start;
    //ora il primo elemento è quello dopo
    start = start ->next;
    //questo nuovo primo elemento non ha nessun back value
    start->back = nullptr;
    //elimina il vecchio primo
    delete tmp;
    size--;
    return true;
}

template <class T>
bool List<T>::popBack(T& v)
{
    if(start == nullptr)
        return false;
    
    v = end -> value;
    Node<T>* tmp = end;
    end = end ->back;
    end->next = nullptr;
    delete tmp;
    size--;
    return true;
}


template <class T>
void List<T>::print()
{
    Node<T>* node = start;
    while(node != nullptr)
    {
        cout<<node->value<<endl;
        node = node -> next;
    }
}

template <class T>
bool List<T>::find(const T& v)
{
    Node<T>* node = start;
    while(node != nullptr)
    {
        if(node -> value == v)
            return true;
        node = node ->next;
    }
    return false;
}



#endif