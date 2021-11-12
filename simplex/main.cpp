#include "Matrix.h"


#include "Matrix.h"
#include "StandardSimplex.h"

using namespace std;

int main()
{

    
    Matrix costi(1,5,0);
    int costiValues[5] = {-1,-1,0,0,0};
    costi.readFromArray(costiValues);

    Matrix risorse(3,1,0);
    int risorseValues[3] = {2,1,1};
    risorse.readFromArray(risorseValues);


    Matrix matrix(3,5,0);
    int matrixValues[15] = {-1,1,1,0,0, 1,1,0,-1,0,  1,0,0,0,1};
    matrix.readFromArray(matrixValues);


    Matrix soluzioneIniziale(5,1,0);
    int solValues[5] = {0,1,1,0,1};
    soluzioneIniziale.readFromArray(solValues);


    StandardSimplex problema(risorse,costi,matrix,true);

    problema.getOptimalValue(soluzioneIniziale);
   

    
    return 0;

}