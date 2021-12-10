#include <iostream>
#include <vector>
#include "alberoB.h"

using namespace std;

void addElement(vector<int>& a,int i);

void heapSort(vector<int>& v);

int main()
{
    vector<int> heap = {4,62,1,67,1,23};

    heapSort(heap);


    for(int i = 0;i < heap.size();i++)
        cout<<i<<" --> "<<heap[i]<<endl;

    return 0;
}

void swapElements(vector<int>& v,int i,int j)
{
    int value = v[i];
    v[i] = v[j];
    v[j] = value;
}

void heapify(vector<int>& v,int n,int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
 
    
    if (l < n && v[l] > v[largest])
        largest = l;
 
    if (r < n && v[r] > v[largest])
        largest = r;
 
    if (largest != i) {
        swapElements(v,i,largest);
        heapify(v, n, largest);
    }
}

void heapSort(vector<int>& v)
{
    for(int i = v.size() / 2 - 1;i >= 0;i--)
        heapify(v,v.size(),i);
    
    for (int i = v.size() - 1; i > 0; i--) {

        

        swapElements(v,0,i);

        heapify(v,i,0);

    }

}

