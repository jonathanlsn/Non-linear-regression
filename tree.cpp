#include "tree.h"



//constructor
Tree::Tree(Node * node){
  FirstNode_ = node;
  Fitness_ = 1;
  NbrNode_ = 1;
  nextTree_ = nullptr; 
}

Tree::Tree(Tree tree){
  
}

//getter
Tree::Node FirstNode(){
  return FirstNode_;
}

Tree::int Fitness(){
  return Fitness_;
}

Tree::int NbrNode(){
  return NbrNode_;
}

//setter


//method
Tree::mutation(){
  int aleaMut=rand()%3 +1;
  int aleaNode=rand()%nbNodes_ +1;
  int aleaOpe=rand()%3 +1;
  int aleaVar=rand()//%nombre de variable+1 +0;
  
  if (aleaMut==1){
    std::cout<<"Insertion"<<std::endl;
    if (aleaOpe==1){
      std::cout<<"Operator AND"<<std::endl;
      newNodevaleur=new Node();//"valeur de variable ou cste");
      newNodeoperateur=new Node("AND",,); //adresse du noeud correspondant à aleaNode, adresse du nouveau noeud créé juste avant
    }
    if (aleaOpe==2){
      std::cout<<"Operator OR"<<std::endl;
    }
    if (aleOpe==3){
      std::cout<<"Operator NOT"<<std::endl;
    }
  }
  if (aleaMut==2){
    std::cout<<"Deletion"<<std::endl;
    //parcours de l'arbre à partir du noeud en question et destruction des noeuds les uns après les autres via le parcours.
  }
  if (aleaMut==3){
    std::cout<<"Substitution"<<std::endl;
    //doit regarder si le noeud a modifier est un operateur ou une valeur pour choisir différentes solutions.
  }
}
