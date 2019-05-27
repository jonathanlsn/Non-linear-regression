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




/*
std::cout<<std::endl;
std::cout<<std::endl;

  // Début du vrai programme
  
std::cout<< "Programme principal :" <<std::endl;
std::cout<<std::endl;
  
bool tab2[]={1,0,1,0,1,1,1,1,1};  // (x1||x2)||(x1&&x2)
int nligne=3;
int ncolonne=3;
Matrix matrix_(tab2,nligne,ncolonne);

std::cout<< "matrice :" <<std::endl;
matrix_.show();
std::cout<<std::endl;

bool ** xt_=matrix_.x();
bool * yt_=matrix_.y(); 

Forest forest;
Node nodet(True);
Tree Treet(&nodet);//Creation of firest Tree with variable
forest.PushBack(&Treet);//Initialisation of forest

//forest.init();   // Initialisation de la forêt
int lambda=5; //Nbe children tests
Tree * fiel[lambda+1]; //Stock children and one parent
Tree * best = &Treet; // To store the best individual

for (int g=0;g<10;++g){       // génération (after while+condition)
  Tree * parent=forest.lastTree(); 
  fiel[0]=parent;
  best=parent;

  for (int k=1;k<lambda+1;++k){   // potentiels enfants
    //mutation

    //Tree cop_parent(parent);
    fiel[k]=parent;//cop
    //std::cout<<parent->show()<<std::endl;
    //std::cout<<fiel[k]->show()<<std::endl;

     //cop_parent.mutation();

    for (int i=0;i<nligne;++i){//Calcul of fitness
      int xt[ncolonne];
      xt[0]=xt_[i][0];
      xt[1]=xt_[i][1];
      int yt=yt_[i];
      //std::cout<<fiel[k]->show()<<std::endl;
      fiel[k] -> calcul_fitness(m);
    }
    if (best->Fitness()<fiel[k]->Fitness()){
      best=fiel[k];
    }
    
  }
  forest.PushBack(best);
}

forest.show();

std::cout<<std::endl;

Tree * Tree_i=forest.show(3);    // arbre de la 3ème génération
std::cout<<Tree_i->show()<<std::endl;  //aperçu de l'arbre

std::cout<<std::endl;
*/
/*
  std::cout<<" " <<std::endl;
  std::cout<<"lala " <<tr1.nextTree()<<std::endl;
  tr1.link(&Tree1);
  std::cout<<"lala " <<tr1.nextTree()<<std::endl;
  std::cout<<&Tree1<<std::endl;

*/

/*   
  std::cout<<std::endl;
  
  Node n1(et);
  Node n2(x1,&n1);
  Node n3(x2,&n1);
  Tree arbre(&n1);
  std::cout<< arbre.show() <<std::endl;
  
  int xtest[ncolonne];
  xtest[0]=xt_[0][0];
  xtest[1]=xt_[0][1];
  bool ytest=yt_[0];
  arbre.calcul_fitness(xtest,ytest);
  std::cout<< arbre.Fitness() <<std::endl;
  
  std::cout<<std::endl;
  
 


 
 /* 
  //Test constructor de Tree by copy 
  std::cout<< "Test constructeur de Tree par copie :" <<std::endl;
  Tree arbre3(&tree2);
  std::cout<< "arbre d'origine : " << tree2.show() <<std::endl;
  std::cout<< "arbre copié : " <<arbre3.show() <<std::endl;


  std::cout<<std::endl;

  std::cout<< "Test mutations :" <<std::endl;
  std::cout<< "arbre d'origine : " << tree2.show() <<std::endl;
  tree2.mutation2();
  std::cout<< "arbre muté : " <<tree2.show() <<std::endl;
  tree2.mutation2();
  std::cout<< "arbre muté 2 fois : " <<tree2.show() <<std::endl;
  tree2.mutation2();
  std::cout<< "arbre muté 3 fois : " <<tree2.show() <<std::endl;
  tree2.mutation2();
  std::cout<< "arbre muté 4 fois : " <<tree2.show() <<std::endl;
  tree2.mutation2();
  std::cout<< "arbre muté 5 fois : " <<tree2.show() <<std::endl;
*/
 

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


Tree * t=fo.show(fo.nb_elmts()-1);
std::cout<< "solution : " << t->show() <<std::endl;


//resolve(matrix_);


  return 0;
}
