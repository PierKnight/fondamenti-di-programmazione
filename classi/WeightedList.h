#ifndef WEIGH_L
#define WEIGH_L

#include <iostream>
#include <vector>
#include <ctime>
#include <random>


template <class T>
class WeightedList
{
    std::vector<int> weights;
    std::vector<T> elements;
    int totalWeight;
    public:
    WeightedList(){
        std::srand(std::time(nullptr));
        totalWeight = 0;
    }

    float percentage(int i)
    {
        return (float)weights[i] / (float)totalWeight;
    }

    void addElement(T l,int weight)
    {
        weights.push_back(weight);
        elements.push_back(l);
        totalWeight += weight;
    }

    void removeElement(int i)
    {
        totalWeight -= weights[i];
        weights.erase(weights.begin() + i);
        elements.erase(elements.begin() + i);
    }
    
    //get random element, gives an exception if the list is empty
    T get()
    {
        int r = std::rand() % (totalWeight + 1);
        
        int sum = 0;
        

        for(int i = 0; i < weights.size();i++)
        {
            sum += weights[i];

            if(r <= sum)
               return elements[i];
        }
    }

};

#endif