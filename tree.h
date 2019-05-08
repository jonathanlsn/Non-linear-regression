

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
    bool cross(Node * node);
    void calcul_fitness(bool y);
    //void Tree_reading();

//void mutation();


  protected:
    Node * FirstNode_;
    int Fitness_;
    int NbrNode_;
    Tree * nextTree_; 
    int generation_;
};
#endif


