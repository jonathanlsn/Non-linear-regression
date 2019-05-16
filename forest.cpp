#include "tree.h"
#include "forest.h"
#include "matrix.h"


Forest::Forest() {
  this -> nb_elmts_ = 0; 
  this -> firstTree_ = nullptr;
  this -> lastTree_= nullptr;
}



void Forest::PushBack(Tree * tree){
  if (firstTree_!=nullptr){
    lastTree_->link(tree);
  }
  if (firstTree_==nullptr){
    firstTree_=tree;
  }
  lastTree_=tree;
  tree->generation(nb_elmts_);
  nb_elmts_+=1;
} 



void Forest::show(){
  Tree * tmp=firstTree_;
  for (int i=0;i<=nb_elmts_-1;++i){
    std::cout<< "génération "  << i << " : " << tmp->show() <<std::endl;
    tmp = tmp->nextTree();
  }
}

Tree * Forest::show(int i){
  Tree * tmp=firstTree_;
  int k=0;
  while (k != i){
    tmp = tmp->nextTree();
    ++k;
  }
  return(tmp);
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

