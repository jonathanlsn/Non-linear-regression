#include "node.h"
#include "forest.h"

#ifndef TREE
#define TREE
class Tree{
  
  public:

//constructor
    Tree(Node * node);
    Tree(Tree tree);
//getter
    Node FirstNode();
    int Fitness();
//setter
  
//method


  protected:
    Node * FirstNode_;
    int Fitness_;
    int 
  
};
#endif
