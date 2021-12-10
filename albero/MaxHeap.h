#ifndef MAX_HEAP
#define MAX_HEAP

#include <iostream>
#include <vector>



class MaxHeap
{
    private:
    std::vector<int> v;

    void heapify(int index)
    {
        
        int father = (index - 1) / 2;

        if(father < 0)
           return;

        if(v[father] < v[index])
        {
            //swap
            int value = v[index];
            v[index] = v[father];
            v[father] = value;

            heapify(father);
        }
    }

    public:
    MaxHeap(){}

    

    void add(int value)
    {
        v.push_back(value);
        heapify(v.size() - 1);
    }


    friend std::ostream& operator<<(std::ostream& out,const MaxHeap& heap)
    {
        for(int i = 0;i < heap.v.size();i++)
            out<<i<<" -> "<<heap.v[i]<<std::endl;
        return out;
    }


};

#endif
