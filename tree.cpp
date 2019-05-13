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




//Tree::Tree(Tree tree){ 
//Creation of a Tree by copy using Node copy

  
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

Tree * Tree::nextTree(){
  return(nextTree_);
}

void Tree::generation(){
  std::cout << generation_ <<std::endl;
}


//method
 void Tree::mutation(){

    //choix d'un numéro de noeud aléatoirement   
    srand(time(NULL));
    int NumeroNode=rand()%NbrNode_+1;    //entre 1-NbrNode_
    std::cout <<"Le numéro du noeud visé: "<<NumeroNode<<std::endl;


    //descente dans l'arbre
    Node* a= FirstNode_;
    std::cout <<"Lecture des noeuds avant la mutation"<<std::endl;

    //Affichage du noeud
    if (a ->type()== "bool"){
      std::cout <<a-> bool_values()<<std::endl;
    } 
    if(a->type()=="op"){
      std::cout <<a-> values()<< std::endl;
    }

    //Descsente dans l'arbre
    for (int i=1; i<NumeroNode; ++i){ 
      if (a ->NextNode1()!=nullptr){
        a=a->NextNode1();
      if (a ->type()== "bool"){
        std::cout <<a-> bool_values()<<std::endl;
      } 
      if(a->type()=="op"){
        std::cout <<a-> values()<< std::endl;
      }
      }
      else if (a ->NextNode1()==nullptr && a->NextNode2()!=nullptr){
        a=a->NextNode2();
      if (a ->type()== "bool"){
        std::cout <<a-> bool_values()<<std::endl;
      } 
      if(a->type()=="op"){
        std::cout <<a-> values()<< std::endl;
      }
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

    //Choix de la modification
    srand(time(NULL));
    int mut=rand()%3+1;    //entre 1-NbrNode_
    int choice=rand()%3+1;
    std::cout<< "   "<< std::endl;
    std::cout <<"le nombre choisi pour la mutation : "<< mut <<std::endl;
    std::cout <<"le noeud visé : " <<std::endl;
      if (a ->type()== "bool"){
        std::cout <<a-> bool_values()<<std::endl;
      } 
      if(a->type()=="op"){
        std::cout <<a-> values()<< std::endl;
      }
    std::cout<< "   "<< std::endl;


    //Remplacer un noeud    

  if (mut==1){
        if (a->values()=="!"){
        //choix d'une autre opération
        std::cout<< "rien n'est fait"<< std::endl;
        }
        else if (a->values()=="||"){
          a->setvalues("&&");
          std::cout<< "c'est une inversion"<< std::endl;
        }
        else {
          std::cout<< "c'est une inversion"<< std::endl;
          a->setvalues("||");
        }
  }

   if (mut==2){
      //Recherche du nombre de fils
      int nb_elem=0;
      this->cross(a,nulltab,nb_elem); //Met en forme le nb elmt du fils
      std::cout<< NbrNode_ <<"avant"<< std::endl;
      std::cout<< nb_elem-1 <<"c'est le nombre d'élements du dessous" << std::endl;

      //Mise a jour du nombre d'élements
      NbrNode_=NbrNode_-(nb_elem-1);
      std::cout<< NbrNode_ <<"apres"<< std::endl;

      a->setNextNodeNull();
      std::cout<< "c'est une deletion"<< std::endl;
      a->setvalues("");
      a->setboolvalues(true);   
      a->settype("bool"); 


    }


    //Ajouter un noeud
    if (mut==3){ //C'est le cas ou on ajoute un noeud
    //choix de l'operateur
    std::cout<< "choice pour l'opérateur "<< choice <<std::endl;   

    std::string str="!";
    std::string str1="&&";
    std::string str2="||";
    Node* NodeNot = new Node(str);
    Node* NodeAnd= new Node(str1);
    Node* NodeOr = new Node(str2);
    Node* NodeT= new Node(true);   
    Node* NodeF= new Node(false);  


    //Operateur Not

    if (choice==2){ //L'operateur Not qui est ajouté
      std::cout<< str <<std::endl;  
      if (a ->FatherNode() !=nullptr){
          std::string typ = a ->FatherNode()->type(); 
          Node* pere= new  Node(a ->FatherNode(),typ); 
        if (pere->NextNode1()==a){
          NodeNot->setNextNode(a);
          NodeNot->setFatherNode(pere);
          pere->setNextNode(NodeNot);
        }
         else{     
          NodeNot->setNextNode(a);
          a->setFatherNode(NodeNot);
          NodeNot->setFatherNode(pere);
          pere->setNextNode2(NodeNot);
         } 
      }
      else{
          NodeNot->setNextNode(a);
          a->setFatherNode(NodeNot);  
          this ->FirstNode_=NodeNot;    
       }
    

      //incrémentation du nombre de noeud du a la mutation
      NbrNode_=NbrNode_+1;       
    }

    if (choice==3){ //L'opérateur ET
      std::cout<< str1 <<std::endl;  
      if (a ->FatherNode() !=nullptr){
          std::string typ = a ->FatherNode()->type(); 
          Node* pere= new  Node(a ->FatherNode(),typ); 
        if (pere->NextNode1()==a){
          NodeAnd->setNextNode(a);
          NodeAnd->setFatherNode(pere);
          a->setFatherNode(NodeAnd);
          NodeT->setFatherNode(NodeAnd);
          NodeAnd->setNextNode2(NodeT);
          pere->setNextNode(NodeAnd);
        }
         else{    
          NodeAnd->setNextNode(a);
          a->setFatherNode(NodeAnd);
          NodeAnd->setNextNode2(NodeF);
          NodeF->setFatherNode(NodeAnd);
          NodeAnd->setFatherNode(pere);
          pere->setNextNode2(NodeAnd);
         } 
      }
      else{
          NodeAnd->setNextNode(a);
          NodeAnd->setNextNode2(NodeT);
          NodeT->setFatherNode(NodeAnd);
          a->setFatherNode(NodeAnd);  
          this ->FirstNode_=NodeAnd;    
       }
    

      //incrémentation du nombre de noeud du a la mutation
      NbrNode_=NbrNode_+2;       
    }

    if (choice==1){ //L'operateur Ou
      std::cout<< str1 <<std::endl;  


      if (a ->FatherNode() !=nullptr){
          std::string typ = a ->FatherNode()->type(); 
          Node* pere= new  Node(a ->FatherNode(),typ); 
        if (pere->NextNode1()==a){
          NodeOr->setNextNode(a);
          NodeOr->setFatherNode(pere);
          a->setFatherNode(NodeOr);
          NodeT->setFatherNode(NodeOr);
          NodeOr->setNextNode2(NodeT);
          pere->setNextNode(NodeOr);
        }
         else{    

          NodeOr->setNextNode(a);
          a->setFatherNode(NodeOr);
          NodeOr->setNextNode2(NodeF);
          NodeF->setFatherNode(NodeOr);
          NodeOr->setFatherNode(pere);
          pere->setNextNode2(NodeOr);
         } 
      }
      else{
          NodeOr->setNextNode(a);
          NodeOr->setNextNode2(NodeT);
          NodeT->setFatherNode(NodeOr);
          a->setFatherNode(NodeOr);  
          this ->FirstNode_=NodeOr;    
       }
    

      //incrémentation du nombre de noeud du a la mutation
      NbrNode_=NbrNode_+2;       
    }
}
    //Application de la modification
    /*
    //La substitution
    if (mut==3){

      //Pour les opérateurs
      if (op==2){
        if (a->values()=="!"){
          srand(time(NULL));
          mut=rand()%2+1; ;//choix d'une autre opération
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
      //Pour les valeurs
      if(op==1){
        if (a->bool_values()==true){
          std::cout<< "c'est une substitution"<< std::endl;
        }
        else{
          std::cout<< "c'est une substitution"<< std::endl;
        }
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

    */
  
    std::cout<< "   "<< std::endl;
    std::cout<< "   "<< std::endl;



    std::cout <<"Final"<<std::endl;

    //Affichage de l'arbre au final 
    Node* b= FirstNode_;
    if (b ->type()== "bool"){
      std::cout <<b-> bool_values()<<std::endl;
    } 
    if(b->type()=="op"){
      std::cout <<b-> values()<< std::endl;
    }

    for (int i=1; i<10; ++i){ 
      if (b ->NextNode1()!=nullptr){
        b=b->NextNode1();
      //Affichage des noeuds
      if (b ->type()== "bool"){
        std::cout <<b-> bool_values()<<std::endl;
      } 
      if(b->type()=="op"){
        std::cout <<b-> values()<< std::endl;
      }
      }
      else if (b ->NextNode1()==nullptr && b->NextNode2()!=nullptr){
        b=b->NextNode2();
      //Affichage des noeuds
      if (b ->type()== "bool"){
        std::cout <<b-> bool_values()<<std::endl;
      } 
      if(b->type()=="op"){
        std::cout <<b-> values()<< std::endl;
      }
      }

    

    }

}

void Tree::calcul_fitness(int * x,bool y){
  int nb_elem=0;
  if (cross(FirstNode_,x,nb_elem)!=y){
    Fitness_-=1;
  }
}


bool Tree::cross(Node * node,int * x, int &nb_node_son){ // WARNING &nb_node_son permet de compter le nombre de noeud à partir du node passé en paramètre, ce n'est pas le nombre d'élément de l'arbre en entier!!! Il est passé en adresse et oblige de l'initialiser à 0 à chaque utilisation de cross//
  if (node ->values()=="&&"){
    nb_node_son=nb_node_son+1;
    return (cross(node -> NextNode1(),x,nb_node_son) && cross(node -> NextNode2(),x,nb_node_son));

  }
  if (node -> values()=="||"){
    nb_node_son=nb_node_son+1;
    return (cross(node -> NextNode1(),x,nb_node_son) || cross(node -> NextNode2(),x,nb_node_son));
  }
  if (node -> values()=="!"){
    nb_node_son=nb_node_son+1;
    return (!cross(node -> NextNode1(),x,nb_node_son));
  }
  if (node -> type()=="x1"){
    nb_node_son=nb_node_son+1;
    return (x[0]);
  }
  if (node -> type()=="x2"){
    nb_node_son=nb_node_son+1;
    return (x[1]);
  }
}


/*
bool Tree::cross(Node * node, int &nb_node_son, bool copy, Node initialcopy ){ // WARNING &nb_node_son permet de compter le nombre de noeud à partir du node passé en paramètre, ce n'est pas le nombre d'élément de l'arbre en entier!!! Il est passé en adresse et oblige de l'initialiser à 0 à chaque utilisation de cross//
//  +la posiiblite de copier

  if (copy==true){
    if (node ->values()=="&&"){
      Node* Nodecopy = new Node(node);
      if (&nb_node_son==0){
        initialcopy= Nodecopy;
      }
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son,copy, initialcopy) && cross(node -> NextNode2(),nb_node_son,copy,initialcopy));

    }
    if (node -> values()=="||"){
      Node* Nodecopy = new Node(node);
      if (&nb_node_son==0){
        initialcopy= Nodecopy;
      }
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son,copy,initialcopy) || cross(node -> NextNode2(),nb_node_son,copy,initialcopy));
    }
    if (node -> values()=="!"){
      Node* Nodecopy = new Node(node);
      if (&nb_node_son==0){
        initialcopy= Nodecopy;
      }
      nb_node_son=nb_node_son+1;
      return (!cross(node -> NextNode1(),nb_node_son,copy,initialcopy));
    }
  
    else{
      Node* Nodecopy = new Node(node);
      if (&nb_node_son==0){
        initialcopy= Nodecopy;
      }
      nb_node_son=nb_node_son+1;
      return (node -> bool_values());
    }
  }


  else{
    if (node ->values()=="&&"){
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son,copy,initialcopy) && cross(node -> NextNode2(),nb_node_son,copy,initialcopy));

    }
    if (node -> values()=="||"){
      nb_node_son=nb_node_son+1;
      return (cross(node -> NextNode1(),nb_node_son,copy,initialcopy) || cross(node -> NextNode2(),nb_node_son,copy,initialcopy));
    }
    if (node -> values()=="!"){
      nb_node_son=nb_node_son+1;
      return (!cross(node -> NextNode1(),nb_node_son,copy,initialcopy));
    }
  
    else{
      nb_node_son=nb_node_son+1;
      return (node -> bool_values());
    }
  }
}
*/



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



void Tree::link(Tree tree){
  nextTree_=&tree;
}


/*
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
*/

