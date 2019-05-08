
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
  std::string str1="&&";
  Node Node4(str);
  Node Node3(str);
  Node Node1(true);
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
  std::cout << (Tree1.cross(Tree1.FirstNode())==true) << std::endl;

  //test de la parenté

  Node Node5 (true, &Node4);

  std::cout<< "test de la parenté"<< std::endl;
  std::cout<< (&Node4==(Node5.FatherNode()))<< std::endl;
  std::cout<< (&Node5==(Node4.NextNode1())) <<std::endl;
 
  //retourner un pointeur nul test
  std::cout<< "test du pointeur nul"<< std::endl;
  int* d =  nullptr;
  std::cout<< std::boolalpha<< (d ==nullptr) << std::endl;

  //resultat sur l arbre avec un opérateur
  std::cout<< "resultat arbre operateur not true"<< std::endl;
  Tree Tree3(&Node4);
  std::cout << (Tree3.cross(Tree3.FirstNode())==false) << std::endl;



  std::cout<< "resultat arbre operateur not false"<< std::endl;
  Node Node7(str);
  Node Node6 (false, &Node7);
  Tree Tree6(&Node7);
  std::cout << (Tree6.cross(Tree6.FirstNode())==true) << std::endl;

  std::cout<< "resultat arbre operateur et FF"<< std::endl;
  Node Node8(str1);
  Node Node9 (false, &Node8);
  Node Node10 (false, &Node8);
  Tree Tree7(&Node8);
  std::cout << (Tree7.cross(Tree7.FirstNode())==false) << std::endl;

  std::cout<< "resultat arbre operateur et FV"<< std::endl;
  Node Node11(str1);
  Node Node12 (false, &Node11);
  Node Node13 (true, &Node11);
  Tree Tree8(&Node11);
  std::cout << (Tree8.cross(Tree8.FirstNode())==false) << std::endl;

  std::cout<< "resultat arbre operateur et VF"<< std::endl;
  Node Node14(str1);
  Node Node15 (true, &Node14);
  Node Node16 (false, &Node14);
  Tree Tree9(&Node14);
  std::cout << (Tree9.cross(Tree9.FirstNode())==false) << std::endl;

  std::cout<< "resultat arbre operateur et VV"<< std::endl;
  Node Node17(str1);
  Node Node18 (true, &Node17);
  Node Node19 (true, &Node17);
  Tree Tree10(&Node17);
  std::cout << (Tree10.cross(Tree10.FirstNode())==true) << std::endl;



  //Creation of forest
  //Forest1.PushBack(Tree2);


  return 0;
}
