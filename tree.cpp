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

    //choix d'un numéro de noeud aléatoirement   
    srand(time(NULL));
    int NumeroNode=rand()%NbrNode_+1;    //entre 1-NbrNode_
    printf("%d\n",NumeroNode);    //teste affichage

    //incrémentation du nombre de noeud du a la mutation
    NbrNode_=NbrNode_+1;

    //descente dans l'arbre
    Node* a= FirstNode_;


    std::cout <<"lecture des noeuds"<<std::endl;
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
    //Test pour savoir quel noeud on modifie
    int op =0;
    if (a ->type()== "bool"){
      op=1;
  
    } 
    if(a->type()=="op"){
       op=2;
    }

    srand(time(NULL));
    int mut=rand()%3+1;    //entre 1-NbrNode_
    std::cout<< "   "<< std::endl;
    std::cout <<"le nombre choisi pour mutation"<<std::endl;
    printf("%d\n",mut);    //teste affichage

    //modification

    if (mut==3){
      if (op==2){
        if (a->values()=="!"){
          srand(time(NULL));
          mut=rand()%2+1; ;
        }
        else if (a->values()=="||"){
          a->setvalues("&&");
          std::cout<< "c'est une substitution"<< std::endl;
        }
        else {
          std::cout<< "c'est une substitution"<< std::endl;
          a->setvalues("||");
        }
      }
       if(op==1){
         if (a->bool_values()==true){
 
           std::cout<< "c'est une substitution"<< std::endl;
         }
         else{
 
           std::cout<< "c'est une substitution"<< std::endl;
         }
      }
      
    }
    
    if (mut==1){
      if (op==2){
        if (a->values()=="!"){
           ;
        }
        else if (a->values()=="||"){
          a->setvalues("&&");
          std::cout<< "c'est une mutation"<< std::endl;}
        else {
          std::cout<< "c'est une mutation"<< std::endl;}
          a->setvalues("||");
        }
       if(op==1){
         if (a->bool_values()==true){
 
          std::cout<< "c'est une mutation"<< std::endl;
         }
         else{
 
          std::cout<< "c'est une mutation"<< std::endl;
         }
      }

    }
    if (mut==2){

      if (op==2){
        if (a->values()=="!"){
          std::cout<< "c'est une deletion"<< std::endl;
        }
        else if (a->values()=="||"){
          a->setvalues("&&");
          std::cout<< "c'est une deletion"<< std::endl;
        }
        else {
          std::cout<< "c'est une deletion"<< std::endl;
          a->setvalues("||");
        }
       if(op==1){
         if (a->bool_values()==true){
 
          std::cout<< "c'est une deletion"<< std::endl;
         }
         else{
 
          std::cout<< "c'est une deletion"<< std::endl;
         }
      }
    }

    
  }
    std::cout<< "   "<< std::endl;
    std::cout<< "   "<< std::endl;
}

void Tree::calcul_fitness(){
  Fitness_=cross(FirstNode_);
}

int Tree::cross(Node * node){
  if (node ->values()=="&&"){
    return (cross(node -> NextNode1()) && cross(node -> NextNode2()));

  }
  if (node -> values()=="||"){
    return (cross(node -> NextNode1()) || cross(node -> NextNode2()));
  }
  if (node -> values()=="!"){
    return (!cross(node -> NextNode1()));
  }
  
  else{
    return (node -> bool_values());
  }
}
