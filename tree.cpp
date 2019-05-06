#include "tree.h"
#include <iostream>


//constructor
Tree::Tree(Node * node){
  FirstNode_ = node;
  Fitness_ = 1;
  NbrNode_ = 1;
  nextTree_ = nullptr; 
  generation_ = -1;
}

//Tree::Tree(Tree tree){
  
//}

//getter
Node* Tree::FirstNode(){
  return FirstNode_;
}

int Tree::Fitness(){
  return Fitness_;
}

int Tree::NbrNode(){
  return NbrNode_;
}

//setter

void Tree::generation(){
  std::cout << generation_ <<std::endl;
}

bool Tree::Tree_reading(){
  Node* actual_Node = FirstNode_;
  if (){
  
  }
  else{
  
  }
}

//method
/* void Tree::mutation(){
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
} */


Tree::void calcul_fitness(){
  fitness_=cross(FirstNode_);
  return fitness_;
}

int cross(Node * node){
  if (node.value()=="&&"){
    return (cross(node.NextNode1()) && cross(node.NextNode2()));
  }
  if (node.value()=="||"){
    return (score=cross(node.NextNode1()) || cross(node.NextNode2()));
  if (node.value()=="!"){
    return (score=!cross(node.NextNode1()));
  }
  else{
    return (node.value());
  }
}
