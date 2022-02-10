#ifndef HASHM_H
#define HASHM_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



template<class K,class T>
struct Pair
{
    private:
    K key;

    public:
    T c;
    Pair(K key_,T& c_):key(key_),c(c_){}

    K getKey()const {return key;}
    T& getValue() {return c;}

};

template<class K,class T,class P>
class HashMap
{
    typedef std::vector<Pair<K,T>> LIST;
    private:
    std::vector<LIST> elements;
    P prov;

    public:
    HashMap()
    {
        elements.resize(1000);
        for(int i = 0;i < 1000;i++)
        {
            LIST l;
            elements.push_back(l);
        }
    }

    void put(const K& key,T value)
    {
        size_t hash = prov(key) % 1000;
        Pair<K,T> p(key,value);
        

        for(int i = 0;i < elements[hash].size();i++)
        {
            if(elements[hash][i].getKey() == key)
            {
                elements[hash][i] = p;
                return;
            }
        }
        elements[hash].push_back(p);
    

    }

    T& find(const K& key,T& fallback)
    {
        size_t hash = prov(key) % 1000;
        for(int i = 0;i < elements[hash].size();i++)
        {
            if(elements[hash][i].getKey() == key)
            {
                return elements[hash][i].c;
            }
            
        }
        return fallback;
    }
    

    void erase(const K& key)
    {
         size_t hash = prov(key) % 1000;
        for(auto pos = elements[hash].begin();pos != elements[hash].end();pos++)
        {
            if((*pos).getKey() == key)
            {
                elements[hash].erase(pos);
                return;
            }      
        }
    }



};

#endif

