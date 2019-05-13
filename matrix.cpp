#include "matrix.h"
#include <iostream>

//Constructor
Matrix::Matrix(int * tab, int nLignes,int nColonnes){
  nLignes_=nLignes;
  nColonnes_=nColonnes;
  matrix_ = new int* [ nLignes ];
  for (int i=0; i < nLignes; i++){
    matrix_[i] = new int[ nColonnes ];
  }
  int k=0;
  for (int h=0; h < nLignes; h++){
    for (int j=0; j < nColonnes; j++){
      matrix_[h][j] = tab[k];
      k+=1;
    }
  }
}    
  
//getters
void Matrix::show(){
  for (int i=0; i < nLignes_; i++) {
    for (int j=0; j < nColonnes_; j++){
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int Matrix::nlignes(){
  return(nLignes_);
}

int Matrix::ncolonnes(){
  return(nColonnes_);
}

int **Matrix::matrix(){
  return(matrix_);
}

int** Matrix::x(){
  int **x;
  x=new int*[nLignes_];
  for (int i=0; i < nLignes_; i++){
    x[i] = new int[ nColonnes_-1 ];
  }
  for (int h=0; h < nLignes_; h++){
    for (int j=0; j < nColonnes_-1; j++){
      x[h][j] = matrix_[h][j];
    }
  }
  return(x);
}

int* Matrix::y(){
  int *y;
  y=new int [nLignes_];
  for (int h=0; h < nLignes_; h++){
    y[h] = matrix_[h][nColonnes_-1];
  }
  return(y);
}

