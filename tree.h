#include "node.h"
#include <cstdlib>
#include "forest.h"

#ifndef TREE
#define TREE
class Tree{
  
  friend class Forest;
  
  public:

//constructor
    Tree(Node * node);
    //Tree(const Tree&);
//getter
    Node FirstNode();
    int Fitness();
    int NbrNode();
//setter
  
void generation();

//method


  protected:
    Node * FirstNode_;
    int Fitness_;
    int NbrNode_;
    Tree * nextTree_; 
    int generation_;
  
};
#endif
