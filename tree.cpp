#include "tree.h"

//constructor
Tree::Tree(Node * node){
  FirstNode_ = node;
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

//setter


//method
