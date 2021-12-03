
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool ordinaDecrescente(int a,int b)
{
    return a < b;
}
//somma minima fra k elementi del vettore usando la tecnica golosa
//è effettivamente la soluzione ottima ma questo algoritmo costa O(nlog(n)) invece del vero e proprio algoritmo ottimo O(n * k)
int getSommaMinimaGolosa(vector<int> nums,int k)
{
    
    sort(nums.begin(),nums.end(),ordinaDecrescente);

    int somma = 0;

    for(int i = 0;i < k && i < nums.size();i++)
        somma += nums[k];
    return k;
}

int main()
{
    
    return 0;
}

//metodo che trova il cammino minimo usando l'approccio goloso
//il mopo sarebbe scegliere sempre il nodo meno costoso tra quelli collegati al nodo corrente

