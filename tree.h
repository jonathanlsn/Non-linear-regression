#include "node.h"
#include <cstdlib>
#include "forest.h"

#ifndef TREE
#define TREE
class Tree{
  
  public:

//constructor
    Tree(Node * node);
    Tree(Tree tree);
//getter
    Node * FirstNode();
    int Fitness();
    NbrNode();
//setter
  
//method


  protected:
    Node * FirstNode_;
    int Fitness_;
    int NbrNode_;
    Tree * nextTree_; 
  
};
#endif
