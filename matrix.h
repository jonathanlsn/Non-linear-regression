#ifndef MATRIX
#define MATRIX

#include <iostream>
class Matrix{
  public:
//constructeur
    Matrix(bool ** tab_X,bool* tab_Y, int nLignes,int nColonnes);

//getter
    int nlignes();
    int ncolonnes();
    void show();
    bool ** matrix();
    int ** x();
    int * y();
  
  protected:
    int nLignes_;
    int nColonnes_;
    bool **matrix_;
};

#endif
