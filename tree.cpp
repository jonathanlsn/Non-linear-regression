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
    
      std::string str="!";
      std::string str1="&&";
      std::string str2="||";
      Node NodeNot(str);
      Node NodeAnd(str1);
      Node NodeOr(str2);
      Node NodeT(true);   
      Node NodeF(false);  

    if (mut==1){
      if (op==2){
          srand(time(NULL));
          int choice=rand()%3+1;
        Node Nodef();
        if (choice==1){
          if (a ->FatherNode()->NextNode1()==a){
          a->setNextNode(&NodeNot);
          }
          else{
          a->setNextNode2(&NodeNot);         
          }
          NodeNot.setFatherNode(a->FatherNode());
          a->setFatherNode(&NodeNot);
          //NodeNot.setNextNode1(a);

          //incrémentation du nombre de noeud du a la mutation
          NbrNode_=NbrNode_+1;       
        }
        if (choice==2){
          a->setNextNode(&NodeAnd);
          a->setFatherNode(&NodeAnd); 
          //incrémentation du nombre de noeud du a la mutation
          NbrNode_=NbrNode_+2;       
        }
        if (choice==3){
          a->setNextNode(&NodeOr);
          a->setFatherNode(&NodeOr);        
        }
        std::cout<< "c'est une insertion"<< std::endl;
        
      }

    }
    if (mut==2){
      //a->NextNodep(nullptr);
      //a->NextNodep(nullptr);
      std::cout<< "c'est une deletion"<< std::endl;
      a->setvalues("");
      //a->setboolvalues(true);   //ICI FAUDRAIT QUE CE SOIT DEJA INITIALISER
      a->settype("bool");
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
