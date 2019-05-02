#include "forest.h"
#include "tree.h"

Forest::Forest() {
  this -> nb_elmts_ = 0; 
  this -> firstTree_ = nullptr;
}

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

void Forest::afficherForest(){
  Tree* tmp = firstTree_ ; // temporary pointer that will go through the list
  while(tmp != nullptr){
  	Tree* a = tmp;
    a -> generation();
    tmp = tmp -> nextTree_;      
  }
}

int Forest::nb_elmts(){
	return nb_elmts_;
}
