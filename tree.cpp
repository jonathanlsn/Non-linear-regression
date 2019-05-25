#include "tree.h"
#include <iostream>
#include "node.h"

int nulltab[2];

//constructor
Tree::Tree(Node * node){
//Initialisation of a tree
  FirstNode_ = node;
  Fitness_ = 0;
  NbrNode_ = 1;
  nextTree_ = nullptr; 
  generation_ = -1;
}





Tree::Tree( Tree* tree){
  Node * FirstNode_init=tree->FirstNode();
  //Node * node =new Node (tree->FirstNode_);
  //FirstNode_ = node;
  Fitness_ = 0;
  NbrNode_ = tree->NbrNode_;
  nextTree_ = nullptr; 
  generation_ = tree->generation_;
  Node * tmp=new Node(true);
  int i=0;
  copy_nodes(FirstNode_init,tmp,i);
}



void Tree::copy_nodes(Node * node, Node * father, int i){
  
  if (node->values()=="&&" or node->values()=="||" or node->values()=="!"){
   
    Node * op_node=new Node(node->values(), father);
    
    if (i==0){
      FirstNode_=op_node;
    }
    ++i;
    
    father=op_node;  

    Node * nextnode1_init=node->NextNode1();
    Node * nextnode2_init=node->NextNode2();
      
    if (node->NextNode1() !=nullptr){  
      copy_nodes(nextnode1_init, father,i);
    }
    if (node->NextNode2() !=nullptr){
      copy_nodes(nextnode2_init, father,i);
    }
  } 
  
  else{
    std::cout<<"lala"<<std::endl;
    Node * param_node=new Node (node->values(), father); 
    if (i==0){
      FirstNode_=param_node;
    }
    ++i;
  } 
}



Tree::~Tree(){}  // Destructor


void Tree::mutation2(){
  int mut_type=rand()%2;
  int mut_switch=rand()%2;
  int mut_param=rand()%2;
  
  //std::cout<< "choix de la mutation : " << mut_type <<std::endl;
  
  Node * node=choose();
  
  if (mut_switch==0){
    if (node->values()=="&&" or node->values()=="||"){switch_op(node);}
  }
  
  if (mut_param==0){
    if (node->values()=="true" or node->values()=="false" or node->values()=="x1" or node->values()=="x2"){
      switch_param(node);
    }
  }
  
  else{
    if (mut_type==0){
      //insertion de "!"
      insertion(node);
    }
  
    if (mut_type==1){
      // Substitution
      substitution(node);
    }
  }
}



Node * Tree::choose(){
  return(crossing(FirstNode_));
}

Node * Tree::crossing(Node * node){
  int mutation_rate=rand()%3;  //taux de mutation
  //std::cout<< "taux de mutation : " << mutation_rate <<std::endl;
  if (mutation_rate==0){
    return(node);
  }

  else{
    int left_right=rand()%2;
    if (left_right==0){   // On se déplace vers le NextNode1
      if (node->NextNode1()==nullptr){   //extrémité de l'arbre
        return(crossing(FirstNode_));
      }
      else{  //coeur de l'arbre
        return(crossing(node->NextNode1()));
      }
    }
    else{  //On se déplace vers le NextNode2
      if (node->NextNode2()==nullptr){   //extrémité de l'arbre
        return(crossing(FirstNode_));
      }
      else{  //coeur de l'arbre
        return(crossing(node->NextNode2()));
      }
    }
  }
}



void Tree::switch_op(Node * node){
  std::string ou="||";
  std::string et="&&";
  if (node->values()=="&&"){node->setvalues(ou);}
  if (node->values()=="||"){node->setvalues(et);}
}

void Tree::switch_param(Node * node){
  std::string param[]={"true","false","x1","x2"};
  int i=rand()%4;
  if (node->values()==param[i]){switch_param(node);}
  else {node->setvalues(param[i]);}
  
}


void Tree::insertion(Node * node){
  
  Node * father=node->FatherNode();
  std::string non="!";
  Node * new_node=new Node(non);
  
  if (node==FirstNode_){FirstNode_=new_node;}
  
  if (father!=nullptr and father->NextNode1()==node){
    father->setNextNode(new_node);
  }
  if (father!=nullptr and father->NextNode2()==node){
    father->setNextNode2(new_node);
  }
  
  new_node->setNextNode(node);
  new_node->setFatherNode(father);
  
  node->setFatherNode(new_node);
}


void Tree::substitution(Node * node){
  std::string options[]={"true","false","x1","x2","&&","||","!"};
  
  int i=rand()%7;   // Choix d'une option
  //std::cout<< "position : " << i <<std::endl;

  Node * father=node->FatherNode();
  Node * new_node= new Node(options[i]) ;
  
  if (node==FirstNode_){FirstNode_=new_node;}
  
  if (options[i]=="&&" or options[i]=="||"){
  
    int param1=rand()%4;  //choix d'un paramètre
    int param2=rand()%4;  //choix d'un paramètre
    
    //std::cout<< "param1 : " << param1 <<std::endl;
    //std::cout<< "param2 : " << param2 <<std::endl;
    
    new Node(options[param1],new_node);
    new Node(options[param2],new_node);
    
  }
  if (options[i]=="!"){
  
    int param1=rand()%4;  //choix d'un paramètre
    //std::cout<< "param1 : " << param1 <<std::endl;
    
    new Node(options[param1],new_node);
  }
  
  if (options[i]=="true"){
    new_node->setboolvalues(true);
  }
  if (options[i]=="false"){
    new_node->setboolvalues(false);
  }
  
  
  if (father!=nullptr and father->NextNode1()==node){
    father->setNextNode(new_node);
  }
  if (father!=nullptr and father->NextNode2()==node){
    father->setNextNode2(new_node);
  }
  new_node->setFatherNode(father);
}

  
  
  
  
/*
Tree::Tree(Tree* tree){ 
//Creation of a Tree by copy using Node copy
  FirstNode_ = new Node  (FirstNode());
  Fitness_ = 0;
  NbrNode_ = 1;
  nextTree_ = nullptr; 
  generation_ = -1;

} */ 

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

Tree * Tree::nextTree(){
  return(nextTree_);
}

void Tree::generation(int x){
  generation_=x;
}







void Tree::calcul_fitness(bool * x,bool y){
  int nb_elem=0;
  bool fit=cross(FirstNode_,x,nb_elem);
  if (fit!=y){
    Fitness_-=1;
  }
}


bool Tree::cross(Node * node,bool * x, int &nb_node_son){ // WARNING &nb_node_son permet de compter le nombre de noeud à partir du node passé en paramètre, ce n'est pas le nombre d'élément de l'arbre en entier!!! Il est passé en adresse et oblige de l'initialiser à 0 à chaque utilisation de cross//
  if (node ->values()=="&&"){
    return (cross(node -> NextNode1(),x,nb_node_son) and cross(node -> NextNode2(),x,nb_node_son));
  }
  if (node -> values()=="||"){
    return (cross(node -> NextNode1(),x,nb_node_son) or cross(node -> NextNode2(),x,nb_node_son));
  }
  if (node -> values()=="!"){
    return (not cross(node -> NextNode1(),x,nb_node_son));
  }
  if (node -> values()=="x1"){
    return (x[0]);
  }
  if (node -> values()=="x2"){
    return (x[1]);
  }
  else{
    return (node->bool_values());
  }
}


bool Tree::cross(Node * node, int &nb_node_son, bool copy, Node initialcopy, Node * passant  ){ // WARNING &nb_node_son permet de compter le nombre de noeud à partir du node passé en paramètre, ce n'est pas le nombre d'élément de l'arbre en entier!!! Il est passé en adresse et oblige de l'initialiser à 0 à chaque utilisation de cross//
//  +la posiiblite de copier

  if (copy==true){
    if (node ->values()=="&&"){
      Node* Nodecopy = new Node(node);
      if (&nb_node_son==0){
        initialcopy= &Nodecopy;
        passant=Nodecopy;
        nb_node_son=nb_node_son+1;
      }
      else{
        nb_node_son=nb_node_son+1;

        if (Nodecopy ->NextNode1()==nullptr){
          passant -> setNextNode (Nodecopy);
        }
        else{
          passant -> setNextNode2(Nodecopy);
        }
        Nodecopy ->setFatherNode(passant);
        passant=Nodecopy;
      }
      return (cross(node -> NextNode1(),nb_node_son,copy, initialcopy, passant ) && cross(node -> NextNode2(),nb_node_son,copy,initialcopy, passant));

    }
    if (node -> values()=="||"){
      Node* Nodecopy = new Node(node);
      if (&nb_node_son==0){
        initialcopy= &Nodecopy;
        passant=Nodecopy;
        nb_node_son=nb_node_son+1;
      }
      else{
        nb_node_son=nb_node_son+1;

        if (Nodecopy ->NextNode1()==nullptr){
          passant -> setNextNode (Nodecopy);
        }
        else{
          passant -> setNextNode2(Nodecopy);
        }
        Nodecopy ->setFatherNode(passant);
        passant=Nodecopy;
      }
      return (cross(node -> NextNode1(),nb_node_son,copy,initialcopy, passant) || cross(node -> NextNode2(),nb_node_son,copy,initialcopy,passant));
    }
    if (node -> values()=="!"){
      Node* Nodecopy = new Node(node);
      if (&nb_node_son==0){
        initialcopy= &Nodecopy;
        passant=Nodecopy;
        nb_node_son=nb_node_son+1;
      }
      else{
        nb_node_son=nb_node_son+1;

        if (Nodecopy ->NextNode1()==nullptr){
          passant -> setNextNode (Nodecopy);
        }
        else{
          passant -> setNextNode2(Nodecopy);
        }
        Nodecopy ->setFatherNode(passant);
        passant=Nodecopy;
      }
      return (!cross(node -> NextNode1(),nb_node_son,copy,initialcopy,passant));
    }
  
    else{
      Node* Nodecopy = new Node(node);
      std::cout<<&Nodecopy<< std::endl;
      if (&nb_node_son==0){
        initialcopy= Nodecopy;
        passant=Nodecopy;
        nb_node_son=nb_node_son+1;
      }
      else{
      nb_node_son=nb_node_son+1;

        if (Nodecopy ->NextNode1()==nullptr){
          passant -> setNextNode (Nodecopy);
        }
        else{
          passant -> setNextNode2(Nodecopy);
        }
        Nodecopy ->setFatherNode(passant);
        passant=Nodecopy;
        std::cout<<Nodecopy ->FatherNode()<< std::endl;
      }
    }
      return (node -> bool_values());
    }
  


  else{
    if (node ->values()=="&&"){
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son,copy,initialcopy,passant) && cross(node -> NextNode2(),nb_node_son,copy,initialcopy,passant));

    }
    if (node -> values()=="||"){
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son,copy,initialcopy,passant) || cross(node -> NextNode2(),nb_node_son,copy,initialcopy,passant));
    }
    if (node -> values()=="!"){
      nb_node_son=nb_node_son+1;
      return (!cross(node -> NextNode1(),nb_node_son,copy,initialcopy,passant));
    }
  
    else{
      nb_node_son=nb_node_son+1;
      return (node -> bool_values());
    }
  }
}




std::string Tree::show(){
  return(parcour(FirstNode_));
}


std::string Tree::parcour(Node * node){
  if (node -> values()=="||" or node -> values()=="&&"){
    return("(" + parcour(node->NextNode1()) + node->values() + parcour(node->NextNode2()) + ")");
  }
  if (node -> values()=="!"){
    return(node->values() + parcour(node->NextNode1()));
  }
  if (node -> type()=="bool"){
    return(node->bool_values() ? "true" : "false");
  }
  else{
    return(node->values());
  }
}



void Tree::link(Tree * tree){
  nextTree_=tree;
}






bool Tree::cross(Node * node, int &nb_node_son ){ // WARNING &nb_node_son permet de compter le nombre de noeud à partir du node passé en paramètre, ce n'est pas le nombre d'élément de l'arbre en entier!!! Il est passé en adresse et oblige de l'initialiser à 0 à chaque utilisation de cross//
//  +la posiiblite de copier


    if (node ->values()=="&&"){
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son) && cross(node -> NextNode2(),nb_node_son));

    }
    if (node -> values()=="||"){
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son) || cross(node -> NextNode2(),nb_node_son));
    }
    if (node -> values()=="!"){
      nb_node_son=nb_node_son+1;
      return (!cross(node -> NextNode1(),nb_node_son));
    }
  
    else{
      nb_node_son=nb_node_son+1;
      return (node -> bool_values());
    }
  }


