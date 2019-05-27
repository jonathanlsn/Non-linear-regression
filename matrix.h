#ifndef MATRIX
#define MATRIX

#include <iostream>
class Matrix{
  public:
//constructeur

    Matrix(bool * tab, int nLignes,int nColonnes);

    Matrix(bool ** tab_X,bool* tab_Y, int nLignes,int nColonnes);


//getter
    int nlignes();
    int ncolonnes();
    void show();
    bool ** matrix();

    bool ** x();
    bool * y();

  
  protected:
    int nLignes_;
    int nColonnes_;
    bool **matrix_;
};

#endif
