//Include of documents
#include "node.h"
#include "tree.h"
#include "forest.h"
#include "matrix.h"

//Include of libraries
#include <iostream>
#include <time.h> 


int main()
{
  
  
  std::cout<< std::endl;

  // test matrix
  std::cout<< "tests matrix"<< std::endl;
  std::cout<< std::endl;
/*  
  int tab[]={1,0,0,0,1,0,1,1,1};  // (!x1||!x2)||(x1&&x2)

  bool tab2[]={1,0,1,0,1,1,1,1,1};  // (x1||x2)||(x1&&x2)
  int nligne_=3;
  int ncolonne_=3;
  Matrix matrix(tab2,nligne_,ncolonne_);
  matrix.show();
  */
  std::cout<< std::endl;

  // Utilisation de la fiteness avec la matrice de données
  std::string et="&&";
  std::string ou="||";
  std::string non="!";
  std::string True="true";
  std::string False="false";
  std::string x1="x1";
  std::string x2="x2";





 

bool tab3[]={1,0,0,0,1,0,1,1,1};  // (x1||x2)||(x1&&x2)
bool tab4[]={1,0,0,0,0,1,1,0,1,1,1,1,1,0,1,1,0,0,1,0};
int nligne=5;
int ncolonne=4;
Matrix matrix_(tab4,nligne,ncolonne);

std::cout<< "matrice :" <<std::endl;
matrix_.show();
std::cout<<std::endl;

std::cout<<"test du nouveau constructeur de matrice : " <<std::endl;

bool **x=matrix_.x();
bool *y=matrix_.y();

Matrix matrix2_(x,y,nligne,ncolonne);
matrix2_.show();
std::cout<<std::endl;


Node no(True);
//Node no1(x1,&no);
//Node no2(x2,&no);
Tree tr(&no);
tr.calcul_fitness(matrix_);


std::cout<<std::endl;
std::cout<< "1er arbre : " <<tr.show() <<std::endl;
std::cout<< "fitness du 1er arbre : " <<tr.Fitness() <<std::endl;
std::cout<<std::endl;

Forest fo(15);
fo.PushBack(&tr);



fo.generation(10,matrix_);
//fo.show();


Tree * t=fo.showlast();
std::cout<< "solution : " << t->show() <<std::endl;


//resolve(matrix_);


  return 0;
}
