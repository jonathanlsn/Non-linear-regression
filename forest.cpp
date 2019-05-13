#include "tree.h"
#include "forest.h"
#include "matrix.h"


Forest::Forest() {
  this -> nb_elmts_ = 0; 
  this -> firstTree_ = nullptr;
  this -> lastTree_= nullptr;
}

/*
// insertion at the head of the list
void Forest::PushBack(Tree x){
	// creation of the new arbre
	Tree* nouveau = new Tree(x); 
	
    // we have to update the number of elements in the list
	this -> nb_elmts_ = nb_elmts_ +1;

	// if the list is empty, the head_ takes the value of nouveau
  if (this -> firstTree_ == nullptr){
    this -> firstTree_ = nouveau;
  }
  
  else {
    Tree* dernier = firstTree_;
    Tree* temp = nullptr;
    for (int i=1; i<nb_elmts_ ;++i){
      temp = dernier -> nextTree_ ;
      dernier = temp;
    }
    dernier -> nextTree_ = nouveau;
   
  }
}
*/


void Forest::PushBack(Tree tree){
  if (firstTree_!=nullptr){
    lastTree_->link(tree);
    std::cout<< "Nope" <<std::endl;
  }
  if (firstTree_==nullptr){
    firstTree_=&tree;
    std::cout<< "Coucou" <<std::endl;
  }
  lastTree_=&tree;
  nb_elmts_+=1;
  std::cout<< nb_elmts_ <<std::endl;
  std::cout<< firstTree_->show() <<std::endl;
} 




void Forest::afficherForest(){
  Tree* tmp = firstTree_ ; // temporary pointer that will go through the list
  while(tmp->nextTree() != nullptr){
  	Tree* a = tmp;
    a -> generation();
    tmp = tmp -> nextTree_;      
  }
}

void Forest::show(){
  Tree * tmp=firstTree_;
  for (int i=0;i<nb_elmts_;++i){
    std::cout<< "génération "  << i << " : " << tmp->show() <<std::endl;
    tmp = tmp->nextTree();
    //std::cout<< "Nope" <<std::endl;
    ++i;
  }
}


int Forest::nb_elmts(){
	return nb_elmts_;
}

Tree * Forest::lastTree(){
  return(lastTree_);
}

Tree * Forest::firstTree(){
  return(firstTree_);
}

