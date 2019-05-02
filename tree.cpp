#include "tree.h"

tree::mutation(){
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
  }  
}
