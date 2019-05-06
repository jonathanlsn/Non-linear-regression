
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
 
  std::string str="!";
  Node Node3(str);
  Node Node1(true,Node3);
  Node Node2(true);
  
  Tree Tree1(&Node1);  
  Tree Tree2(&Node3);
  
  //Verification des parametres

  std::cout<< "Verification des parametres" <<std::endl;
  std::cout<< Node1.bool_values() <<std::endl;
  std::cout<< Node3.values() <<std::endl;


  std::cout<< "Verification des parametres" <<std::endl;
  std::cout<< std::boolalpha << (Node1.NextNode1()==nullptr) <<std::endl;
  std::cout<< std::boolalpha << (Node1.NextNode2()==nullptr) <<std::endl;
  
  //Verification des types
  std::cout<< "Verification des types" <<std::endl;
  std::cout<< Node2.type()<<std::endl;
  std::cout<< Node1.type()<<std::endl;

   //Verification des arbres
  std::cout<< "Verification des arbres" <<std::endl;
  std::cout<< Tree1.FirstNode()<<std::endl;
  std::cout<< Tree1.FirstNode() -> type()  <<std::endl;

  std::cout<< Tree1.Fitness() << std::endl;
  std::cout<< Tree1.NbrNode() << std::endl;

  //resultat arbre
  std::cout<< "resultat arbre"<< std::endl;
  std::cout << (Tree1.cross(Tree1.FirstNode())==0) << std::endl;

  //resultat sur l arbre avec un opérateur
  std::cout<< "resultat arbre operateur"<< std::endl;
  //std::cout << Tree2.cross(Tree2.FirstNode()) << std::endl;
  std::cout<< Node3.NextNode1()<< std::endl;




  //Creation of forest
  //Forest1.PushBack(Tree2);


  return 0;
}
