#ifndef DINAMICO_H
#define DINAMICO_H

#include <iostream>
using namespace std;



template <class T>
class Dinamico
{
	
	
	
	friend ostream& operator<<(ostream& out,Dinamico& d)
	{
		
		for(int i = 0;i < d.index;i++)
			out<<d.array[i]<<endl;
		
		return out;
		
	}
	
	T& operator[](int);
	
	T* array;
	
	
	int index = 0;
	int capacity;
	int increase = 10;
	
    public:
	Dinamico()
	{
	   	capacity = increase;		
		array = new T[capacity];		
	}
	
	Dinamico(int size)
	{
		increase = size;
	   	capacity = increase;		
		array = new T[capacity];		
	}
	
	~Dinamico()
	{
		delete [] array;
		cout<<"DEAD";
	}
	
	T get(int index)
	{
		return array[index];
	}
	
	void set(T valore,int index)
	{
		array[index] = valore;
	}
	
	int getSize(){return index;}
	int getDim(){return capacity;}
	
    void aggiungi(T valore)
	{
		if(index >= capacity)
		{
			T* temp = new T[capacity + increase];
			for(int i = 0;i < capacity;i++)
				temp[i] = array[i];
			
			delete [] array;
			
			array = temp;
			
			capacity += increase;
			
		}
		
		array[index++] = valore;
	}
	
	T rimuoviUltimo()
	{
		
	    T valore = array[--index];
		
		if(capacity - index >= increase)
		{
			capacity -= increase;
			
			T* temp = new T[capacity];
			for(int i = 0;i < index;i++)
				temp[i] = array[i];
			
	        delete [] array;		
		    array = temp;	
		}
			
	    return valore;
			
	}
	
	
	
	
	
};

template <class T>
T& Dinamico<T>::operator[](int index)
	{
		return array[index];
	}
	


#endif