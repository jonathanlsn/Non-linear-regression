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
    //Ajouter un noeud
    if (mut==3){
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

    if (choice==2){
      std::cout<< str <<std::endl;  
      if (a ->FatherNode() !=0){
          std::string typ = a ->FatherNode()->type(); 
          Node* pere= new  Node(a ->FatherNode(),typ); 
        if (pere->NextNode1()==a){
          std::cout<< "lala "<<std::endl;    
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

    if (choice==3){
      std::cout<< str1 <<std::endl;  
      if (a ->FatherNode() !=0){
          std::string typ = a ->FatherNode()->type(); 
          Node* pere= new  Node(a ->FatherNode(),typ); 
        if (pere->NextNode1()==a){
          std::cout<< "lala et "<<std::endl;    
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

    if (choice==1){
      std::cout<< str1 <<std::endl;  
      if (a ->FatherNode() !=0){
          std::string typ = a ->FatherNode()->type(); 
          Node* pere= new  Node(a ->FatherNode(),typ); 
        if (pere->NextNode1()==a){
          std::cout<< "lala et "<<std::endl;    
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

    //Creation des noeuds (il faut METTRE DES NEWS ATTENTION)
    std::string str="!";
    std::string str1="&&";
    std::string str2="||";
    Node NodeNot(str);
    Node NodeAnd(str1);
    Node NodeOr(str2);
    Node NodeT(true);   
    Node NodeF(false);  

    //L'insertion
    if (mut==1){
     std::cout<< op << std::endl;  
 
      //Pour les operateurs
      if (op==2){
        srand(time(NULL));
        int choice=rand()%3+1;//choix de l'operateur
        std::cout<< "choice "<< choice <<std::endl;   
        //Operateur Not
        /*if (choice==1){
          std::cout<< "choice "<< choice <<std::endl;   
          if (a ->FatherNode()->NextNode1()==a){
            std::cout<< "lala "<< choice <<std::endl;    //PBBBBBBBBBB
            a->setNextNode(&NodeNot);
          }
          //else{
            a->setNextNode2(&NodeNot);         
          }
          NodeNot.setFatherNode(a->FatherNode());
          a->setFatherNode(&NodeNot);
          //NodeNot.setNextNode1(a);

          //incrémentation du nombre de noeud du a la mutation
          NbrNode_=NbrNode_+1;       
        }

        //Operateur And
        if (choice==2){
          a->setNextNode(&NodeAnd);
          a->setFatherNode(&NodeAnd); 
          //incrémentation du nombre de noeud du a la mutation
          NbrNode_=NbrNode_+2;       
        }
 
        //Operateur Or
        if (choice==3){
          a->setNextNode(&NodeOr);
          a->setFatherNode(&NodeOr);        
        }!

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

    */
  
    std::cout<< "   "<< std::endl;
    std::cout<< "   "<< std::endl;



    std::cout <<"Final"<<std::endl;
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
