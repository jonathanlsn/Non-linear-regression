#include "tree.h"

//constructor
Tree::Tree(Node * node){
  FirstNode_ = node;
  Fitness_ = 1;
  NbrNode_ = 1;
  nextTree_ = nullptr; 
}

Tree::Tree(Tree tree){
  
}

//getter
Tree::Node FirstNode(){
  return FirstNode_;
}

Tree::int Fitness(){
  return Fitness_;
}

Tree::int NbrNode(){
  return NbrNode_;
}

//setter


//method
