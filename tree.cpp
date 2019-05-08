#include "tree.h"
#include <iostream>
#include "node.h"


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

Node * Tree:: FirstNode(){

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


//method
 void Tree::mutation(){

    NbrNode_=4;
    //choix d'un numéro de noeud aléatoirement   
    srand(time(NULL));
    int NumeroNode=rand()%NbrNode_+1;    //entre 1-NbrNode_
    std::cout<< "nombre aleatoire genéré"<< std::endl;
    printf("%d\n",NumeroNode);    //teste affichage

    //incrémentation du nombre de noeud du a la mutation
    NbrNode_=NbrNode_+1;

    //descente dans l'arbre
    Node* a= FirstNode_;

    if (a ->type()== "bool"){
      std::cout <<a-> bool_values()<<std::endl;
    } 
    if(a->type()=="op"){
      std::cout <<a-> values()<< std::endl;
    }
 
    for (int i=1; i<NumeroNode; ++i){ 
      if (a ->NextNode1()!=nullptr){
        a=a->NextNode1();
      }
      else if (a ->NextNode1()==nullptr && a->NextNode2()!=nullptr){
        a=a->NextNode2();
      }

    if (a ->type()== "bool"){
      std::cout <<a-> bool_values()<<std::endl;
    } 
    if(a->type()=="op"){
      std::cout <<a-> values()<< std::endl;
    }

    }
  }

void Tree::calcul_fitness(){
  Fitness_=cross(FirstNode_);
}

int Tree::cross(Node * node){
  if (node ->values()=="&&"){
    return (cross(node -> NextNode1()) && cross(node -> NextNode2()));

  }
  if (node -> values()=="||"){
    return (cross(node -> NextNode1()) or cross(node -> NextNode2()));
  }
  if (node -> values()=="!"){
    return (!cross(node -> NextNode1()));
  }
  
  else{
    return (node -> bool_values());
  }
}
