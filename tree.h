#ifndef TREE
#define TREE

#include "node.h"
#include <cstdlib>


class Tree{
  
  friend class Forest;
  
  public:

//constructor
    Tree(Node* node);
    Tree(Tree* Tree);

//getter
    Node* FirstNode();
    int Fitness();
    int NbrNode();

//setter
    Tree * nextTree();
    void generation();

//method

    bool cross(Node * node,int &nb_elem, bool copy, Node initialcopy,  Node * passant);
    bool cross(Node * node, int &nb_node_son );
    void calcul_fitness(bool y);
    void mutation();


    bool cross(Node * node,int * x,int &nb_elem);
    void calcul_fitness(int * x, bool y);
    bool cross(Node * node,int &nb_elem, bool copy, Node initialcopy);



    std::string show();
    std::string parcour(Node * node);
    void link(Tree * tree);


  protected:
    Node * FirstNode_;
    int Fitness_;
    int NbrNode_;
    Tree * nextTree_; 
    int generation_;
};
#endif


