#include "forest.h"

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
    for (int i=1; i<nb_elmts ;++i){
      temp = dernier -> nextTree_ ;
      dernier = temp;
    }
    dernier -> nextTree_ = nouveau;
   
  }
}

int Forest::nb_elmts(){
	return nb_elmts_;
}
