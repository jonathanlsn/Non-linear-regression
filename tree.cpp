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
   
    Node * op_node=new Node(node->values(), father) ;
    
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
    new Node (node->values(), father); 
  }
  
}



Tree::~Tree(){}  // Destructor


void Tree::mutation2(){
  int mut_type=rand()%2;
  int mut_switch=rand()%2;
  
  std::cout<< "choix de la mutation : " << mut_type <<std::endl;
  
  Node * node=choose();
  
  if (mut_switch==0){
    if (node->values()=="&&" or node->values()=="||"){switch_op(node);}
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
  std::cout<< "taux de mutation : " << mutation_rate <<std::endl;
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
  std::cout<< "position : " << i <<std::endl;

  Node * father=node->FatherNode();
  Node * new_node= new Node(options[i]) ;
  
  if (node==FirstNode_){FirstNode_=new_node;}
  
  if (options[i]=="&&" or options[i]=="||"){
  
    int param1=rand()%4;  //choix d'un paramètre
    int param2=rand()%4;  //choix d'un paramètre
    
    std::cout<< "param1 : " << param1 <<std::endl;
    std::cout<< "param2 : " << param2 <<std::endl;
    
    new Node(options[param1],new_node);
    new Node(options[param2],new_node);
    
  }
  if (options[i]=="!"){
  
    int param1=rand()%4;  //choix d'un paramètre
    std::cout<< "param1 : " << param1 <<std::endl;
    
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


//method
 void Tree::mutation(){

    //choix d'un numéro de noeud aléatoirement   
    srand(time(NULL));
    int NumeroNode=rand()%NbrNode_+1;    //entre 1-NbrNode_
    std::cout <<"Le numéro du noeud visé: "<<NumeroNode<<std::endl;


    //descente dans l'arbre
    Node* a= FirstNode_;
    std::cout <<"Lecture des noeuds avant la mutation"<<std::endl;



    //Descsente dans l'arbre
    for (int i=1; i<NumeroNode; ++i){ 
      if (a ->NextNode1()!=nullptr){
        a=a->NextNode1();
      if (a ->type()== "bool"){
      } 
      if(a->type()=="op"){

      }
      }
      else if (a ->NextNode1()==nullptr && a->NextNode2()!=nullptr){
        a=a->NextNode2();
      if (a ->type()== "bool"){

      } 
      if(a->type()=="op"){

      }
      }

    }
     std::cout<<this->show()<<std::endl;

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



    std::cout <<"Final tree after mutation:"<<std::endl;

    //Affichage de l'arbre au final 

      std::cout<<this->show()<<std::endl;

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


