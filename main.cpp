
#include "node.h"
#include "tree.h"
#include "forest.h"

#include <iostream>
#include <time.h> 

int main()
{

  //Creation on an environment of work
  //std::cout<<"Hello World"<<std::endl;
  
  
  //Générateur aléatoire dépendant du temps (change la seed toute les secondes)
  std::cout<< "Tests de random" <<std::endl;
  srand(time(NULL));
  int nbgen=rand()%9+1;    //entre 1-9
  printf("%d\n",nbgen);    //teste affichage
  

  bool a = true;
  bool b = true;
  bool c = false;

  std::cout<< "Tests de nos opérateurs" <<std::endl;
  std::cout<< std::boolalpha << ((a && b) == 1) <<std::endl;
  std::cout<< std::boolalpha << ((a || c) == 1) <<std::endl;
  std::cout<< std::boolalpha << ((! b) == 0) <<std::endl;

  //creation de la foret et de l'arbre
  
  Forest Forest1();
  Node Node1("0");
  Node Node2("1");
  Tree Tree1(&Node1);  
  
  //Verification des parametres
   std::cout<< "Verification des parametres" <<std::endl;
   std::cout<< Node2.values() <<std::endl;

  return 0;
}
