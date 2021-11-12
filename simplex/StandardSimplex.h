#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <iostream>
#include "Matrix.h"

/*
  algoritmo del simplesso 
*/
class StandardSimplex
{
    private:
    Matrix resource;
    Matrix costs;
    Matrix matrix;
    bool debug;

    public:
    StandardSimplex(Matrix,Matrix,Matrix);
    StandardSimplex(Matrix,Matrix,Matrix,bool);

    //TO-DO prima fase del simplesso

    bool getOptimalValue(Matrix& currSol,double&);

};

StandardSimplex::StandardSimplex(Matrix m1,Matrix m2,Matrix m3):resource(m1),costs(m2),matrix(m3){}
StandardSimplex::StandardSimplex(Matrix m1,Matrix m2,Matrix m3,bool d):resource(m1),costs(m2),matrix(m3),debug(d)
{
    if(debug)
    {
        std::cout<<"---------------Matrice dei coefficenti tecnologici---------------\n";
        matrix.print();
        std::cout<<"---------------Vettore costi---------------\n";
        costs.print();
        std::cout<<"---------------Vettore risorse---------------\n";
        resource.print();
    }
}


//QUESTA E' la seconda fase dell'algoritmo del simplesso!, l'argomento DEVE essere una soluzione ammissibile,
//poi ci pensa lui a controllare se effettivamente è anche di base.

//si lo so, potrebbe essere reso MOLTO più efficente, al momento faccio un sacco di copie inutili
bool StandardSimplex::getOptimalValue(Matrix& currX,double& objective)
{
    int m = matrix.getRows();
    int n = matrix.getCols();

    //tutti i vettori e matrici necessarie per il simplesso
    Matrix costiDiBase(1,m,0);
    Matrix costiFuoriBase(1,n - m,0);
    Matrix matriceN(m,n - m,0);
    Matrix matriceB(m,m,0);
    Matrix xDiBase(m,1,0);

    int fuoriBase = 0;
    int inBase = 0;

    //se componente i è di base allora è true altrimenti false
    bool appartenenza[n];


    for(int i = 0;i < n;i++)
    {
        
        if(currX(i,0) == 0 && fuoriBase < n - m)
        {

            costiFuoriBase(0,fuoriBase) = costs(0,i);

             for(int r = 0; r < m;r++)
                matriceN(r,fuoriBase) = matrix(r,i);

            appartenenza[i] = false;
            ++fuoriBase;
        }
        else if(inBase < m)
        {
             costiDiBase(0,inBase) = costs(0,i);

             xDiBase(inBase,0) = currX(i,0);

             for(int r = 0; r < m;r++)
                matriceB(r,inBase) = matrix(r,i);

            appartenenza[i] = true;

            ++inBase;
        }
        else
        {
            
            std::cout<<"La soluzione inserita non è di base!(valori diversi da 0 >= m!)\n";
            return false;
        }
    }


    

    
    Matrix inverseB(matriceB);
    if(!matriceB.inverse(inverseB))
    {
        std::cout<<"La soluzione inserita non è di base!(matrice non invertibile)\n";
        return false;
    }
    

    Matrix matriceInverseBN = inverseB * matriceN;


    Matrix test = costiDiBase * matriceInverseBN;
    
    Matrix costiRidottiFuoriBase(costiFuoriBase - (test));
    

    int j_value = -1;
    for(int i = 0;i < n - m;i++)
    {
        if(costiRidottiFuoriBase(0,i) < 0)
        {
             j_value = i;
        }
    }

    
    if(j_value == -1)
    {
        std::cout<<"Una soluzione ottima e': \n";
        currX.print();
        std::cout<<"\n";
        return true;
    }
    

    //jesima colonna della matrice B-1 * N;
    Matrix d(m,1,0);

    double step = -1;

    for(int i = 0;i < m;i++)
    {
          d(i,0) = matriceInverseBN(i,j_value);

          if(d(i,0) > 0)
          {
              double rapporto = xDiBase(i,0) / d(i,0);
              if(step == -1 || rapporto < step)
                 step = rapporto;
          }
    }
    if(step == -1)
    {
        std::cout<<"Il Problema è illimitato!\n";
        return false;
    }


    Matrix newSolution(n,1,0);

    int base = 0;
    int fuori_base = 0;

    for(int i = 0;i < n;i++)
    {

        //se è di base
        if(appartenenza[i])
        {
            newSolution(i,0) = currX(i,0) - (d(base++,0) * step);
        }
        else if(fuori_base == j_value)
        {
            newSolution(i,0) = step;
            ++fuori_base;
        }
    }

    objective += costiRidottiFuoriBase(0,j_value) * step;

    if(debug)
    {
        std::cout<<"---------------Soluzione di base ammissibile corrente---------------\n";
        currX.print();
        std::cout<<"---------------Matrice B---------------\n";
        matriceB.print();
        std::cout<<"---------------Matrice N---------------\n";
        matriceN.print();
        std::cout<<"---------------Matrice B-1---------------\n";
        inverseB.print();
        std::cout<<"---------------Matrice B-1N---------------\n";
        matriceInverseBN.print();
         
    }

    return getOptimalValue(newSolution,objective);

}

#endif
