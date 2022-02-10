
#ifndef NO_ORD_GRAF
#define NO_ORD_GRAF

#include "Grafo.h"
class GrafoNonOrientato : public Grafo
{
    public:
    GrafoNonOrientato(unsigned n):Grafo(n) {}

    void operator()(unsigned i, unsigned j, bool b) {
        assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
        bool esisteArco = this->archi[i][j];
        if ((!esisteArco && b) || (esisteArco && !b)) {
            this->archi[i][j] = b;  // arco i->j
            this->archi[j][i] = b; // arco j->i 
            if (b)
                vm++;
            else
                vm--;
        }
    }

      void svuota() {
        for (unsigned i = 0; i < this->n(); i++)
            for (unsigned j = 0; j < this->n(); j++) {
                archi[i][j] = false;
            }
        vm = 0;
    }

};

#endif