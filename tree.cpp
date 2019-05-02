#include "tree.h"

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
Node Tree::FirstNode(){
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

