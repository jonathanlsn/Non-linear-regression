#include "tree.h"
#include "forest.h"
#include "matrix.h"


Forest::Forest() {
  this -> nb_elmts_ = 0; 
  this -> firstTree_ = nullptr;
  this -> lastTree_= nullptr;
  this -> lambda_= 5;
}


Forest::Forest(int lambda) {
  this -> nb_elmts_ = 1; 
  this -> lambda_= lambda;
  std::string True="true";
  Node * node = new Node (True);
  Tree * tree = new Tree (node);
  this -> firstTree_ = tree;
  this -> lastTree_= tree;
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
    std::cout<< "génération "<< i << " : " << tmp->show() <<std::endl;
    tmp = tmp->nextTree();
  }
}


Tree * Forest::showlast(){
  //std::cout<< lastTree_->show() << " : " << lastTree_->Fitness() << std::endl;
  return(lastTree_);
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


void Forest::evolve(Matrix matrix_){

  if (lastTree_==firstTree_){firstTree_->calcul_fitness(matrix_);}  

  Tree * fiel[lambda_+1]; //Stock children and one parent
  Tree * best = this->lastTree();
  
  Tree * parent=lastTree_; 
  fiel[0]=parent;
  best=parent;
  srand(time(NULL));
	for (int k=1;k<lambda_+1;++k){   // lambda enfants
		//mutation
		fiel[k]= new Tree(parent);  // Copie de l'arbre parent 
		fiel[k]->mutation();  // Mutation 

		fiel[k]->calcul_fitness(matrix_);  // Calcul la fitness de l'enfant
		
	  if (best->Fitness()<=fiel[k]->Fitness()){
	    best=fiel[k];
  	}
  }
  
	PushBack(best);
}


void Forest::generation(int nb_gen,Matrix matrix_){
  for (int g=0;g<nb_gen;++g){ 
  //Tree * last=lastTree_;
  //while(last->Fitness()!=0){

    //last=lastTree_;
    //if(last->Fitness()==0){return;}
    evolve(matrix_);
    
  }
  std::cout<< "Best : " << lastTree_->show() << " ||| Fitness : "<< lastTree_->Fitness()  <<std::endl;
}


