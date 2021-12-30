#ifndef COMB_H
#define COMB_H

#include <iostream>
#include <vector>

class Combinazione 
{
    private:
    int lunghezza;
    int k;
    std::vector<int> comb;

    public:
    Combinazione(int l,int elementi):lunghezza(l),comb(l,0),k(elementi){}

    const std::vector<int>& getCombination()
    {
        return comb;
    }

    void next()
    {
        for(int i = 0;i < lunghezza;i++)
        {
            if(comb[i] == k - 1)
            {
                comb[i] = 0;
            }
            else
            {
                ++comb[i];
                return;
            }
        }
    }

    bool last()
    {
        for(int i = 0;i < lunghezza;i++)
            if(comb[i] != k - 1)
               return false;
        return true;
    }

    bool first()
    {
        for(int i = 0;i < lunghezza;i++)
            if(comb[i] != 0)
               return false;
        return true;
    }

    void reset()
    {
        comb.assign(lunghezza,0);
    }




};


#endif