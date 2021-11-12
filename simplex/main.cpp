#include "Matrix.h"


#include "Matrix.h"
#include "StandardSimplex.h"

using namespace std;

int main()
{

    
    // ESEMPIO 1
    Matrix costi(1,5,0);
    double costiValues[5] = {-1,-1,0,0,0};
    costi.readFromArray(costiValues);

    Matrix risorse(3,1,0);
    double risorseValues[3] = {2,1,1};
    risorse.readFromArray(risorseValues);


    Matrix matrix(3,5,0);
    double matrixValues[15] = {-1,1,1,0,0, 1,1,0,-1,0,  1,0,0,0,1};
    matrix.readFromArray(matrixValues);


    Matrix soluzioneIniziale(5,1,0);
    double solValues[5] = {0,1,1,0,1};
    soluzioneIniziale.readFromArray(solValues);
    

    // ESEMPIO 2 ammissibile ma non di base
    /*
    Matrix costi(1,6,0);
    double costiValues[6] = {6,-7,9,0,0,0};
    costi.readFromArray(costiValues);

    Matrix risorse(3,1,0);
    double risorseValues[3] = {8,4,5};
    risorse.readFromArray(risorseValues);


    Matrix matrix(3,6,0);
    double matrixValues[18] = {2,-1,1,1,0,0, 
                              1,1,-5,0,1,0,
                              0,1,2,0,0,1};
    matrix.readFromArray(matrixValues);


    Matrix soluzioneIniziale(6,1,0);
    double solValues[6] = {0,2,0,10,2,3};
    soluzioneIniziale.readFromArray(solValues);

    */
    
    double ob = -1;
    

    StandardSimplex problema(risorse,costi,matrix,true);
    
    
    problema.getOptimalValue(soluzioneIniziale,ob);
   
    cout<<"Valore Obiettivo ottimo: "<<ob<<endl;
    
    return 0;

}