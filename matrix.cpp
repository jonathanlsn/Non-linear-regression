#include "matrix.h"
#include <iostream>

//Constructor

Matrix::Matrix(bool * tab, int nLignes,int nColonnes){
  nLignes_=nLignes;
  nColonnes_=nColonnes;
  matrix_ = new bool* [nLignes ];
  for (int i=0; i < nLignes; i++){
    matrix_[i] = new bool[nColonnes];
  }
  int k=0;
  for (int h=0; h < nLignes; h++){
    for (int j=0; j < nColonnes; j++){
      matrix_[h][j] = tab[k];
      ++k;
    }
  }
}    

Matrix::Matrix(bool ** tab_X,bool* tab_Y, int nLignes,int nColonnes){
  nLignes_=nLignes;
  nColonnes_=nColonnes;
  matrix_ = new bool* [nLignes ];
  for (int i=0; i < nLignes; i++){
    matrix_[i] = new bool[nColonnes];
  }
  for (int h=0; h < nLignes; h++){
    for (int j=0; j < nColonnes; j++){
      if (j == nColonnes-1){
        matrix_[h][j] = tab_Y[h];
	  }
      else{
		    matrix_[h][j] = tab_X[j][h];
	    }
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

bool **Matrix::matrix(){
  return(matrix_);
}

bool** Matrix::x(){
  bool **x;
  x=new bool*[nLignes_];
  for (int i=0; i < nLignes_; i++){
    x[i] = new bool[ nColonnes_-1 ];
  }
  for (int h=0; h < nLignes_; h++){
    for (int j=0; j < nColonnes_-1; j++){
      x[h][j] = matrix_[h][j];
    }
  }
  return(x);
}

bool* Matrix::y(){
  bool *y;
  y=new bool [nLignes_];
  for (int h=0; h < nLignes_; h++){
    y[h] = matrix_[h][nColonnes_-1];
  }
  return(y);
}

