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
    bool cross(Node * node,int &nb_elem, bool copy, Node initialcopy);
    bool cross(Node * node, int &nb_node_son );
    void calcul_fitness(bool y);
    void mutation();



  protected:
    Node * FirstNode_;
    int Fitness_;
    int NbrNode_;
    Tree * nextTree_; 
    int generation_;
};
#endif


