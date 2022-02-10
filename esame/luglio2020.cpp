#include <iostream>
#include "GrafoPesato.h"



bool esercizio1(const GrafoPesato& grafo)
{
    for(int i = 0;i < grafo.n();i++)
    {
        int sommaTotale = 0;
        for(int j = 0;j < grafo.n();j++)
            if(grafo(i,j) && i != j)
                sommaTotale += grafo.w(i,j);

        for(int j = 0;j < grafo.n();j++)
           if(grafo(i,j) && i != j)
           for(int k = 0;k < grafo.n();k++)
              if(grafo(j,k) && j != k)
                  if(grafo.w(j,k) > sommaTotale)
                     return false;
    }
    return true;

} 