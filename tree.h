

#ifndef TREE
#define TREE

#include "node.h"
#include <cstdlib>


class Tree{
  
  friend class Forest;
  
  public:

//constructor
    Tree(Node* node);
    //Tree(const Tree&);

//getter
    Node* FirstNode();
    int Fitness();
    int NbrNode();

//setter
  
    void generation();

//method
    int cross(Node * node);
    void calcul_fitness();
    void mutation();



  protected:
    Node * FirstNode_;
    bool Fitness_;
    int NbrNode_;
    Tree * nextTree_; 
    int generation_;
};
#endif


