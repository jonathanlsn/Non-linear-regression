#ifndef MATRIX
#define MATRIX

#include <iostream>
class Matrix{
  public:
//constructeur
    Matrix(int * tab, int nLignes,int nColonnes);

//getter
    int nlignes();
    int ncolonnes();
    void show();
    int ** matrix();
    int ** x();
    int * y();
  
  protected:
    int nLignes_;
    int nColonnes_;
    int **matrix_;
};

#endif
