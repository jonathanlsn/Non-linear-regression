#ifndef MATRIX
#define MATRIX

#include <iostream>
class Matrix{
  public:
//constructeur

    Matrix(bool * tab, int nLignes,int nColonnes);  // add a new matrix from an array. the constructor is obsolete.

    Matrix(bool ** tab_X,bool* tab_Y, int nLignes,int nColonnes);  // add a new matrix from a matrix of xi arguments and an array of y values


//getter
    int nlignes();  // return the number of lines of the matrix
    int ncolonnes();  // return the number of collumns of the matrix 
    void show();  // show the representation of the matrix
    bool ** matrix();  // return the matrix

    bool ** x();  // return the matrix of xi arguments
    bool * y();  // return the collumn of y values

  
  protected:
    int nLignes_;  //  nummber of lines
    int nColonnes_;  //  number of collumns
    bool **matrix_;  // the matrix
};

#endif
