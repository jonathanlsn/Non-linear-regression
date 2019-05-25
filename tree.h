#ifndef TREE
#define TREE

#include "node.h"
#include "matrix.h"
#include <cstdlib>


class Tree{
  
  friend class Forest;
  
  public:

//constructor
    Tree(Node* node);
    Tree( Tree* Tree);

//getter
    Node* FirstNode();
    int Fitness();
    int NbrNode();

//setter
    Tree * nextTree();
    void generation(int x);

//method
    
    
    bool cross(Node * node, int &nb_node_son );
    void calcul_fitness(bool y);
    void mutation();


    bool cross(Node * node,bool * x,int &nb_elem);
    void calcul_fitness(Matrix matrix);
    
    
    bool cross(Node * node,int &nb_elem, bool copy, Node initialcopy);

    void copy_nodes(Node * node,Node * father,int i);

    std::string show();
    std::string parcour(Node * node);
    void link(Tree * tree);
    
    void mutation2();
    Node * choose();
    Node * crossing(Node * node);
    void switch_op(Node * node);
    void switch_param(Node * node);
    void substitution(Node * node);
    void insertion(Node * node);

//destructor

    ~Tree();

  protected:
    Node * FirstNode_;
    int Fitness_;
    int NbrNode_;
    Tree * nextTree_; 
    int generation_;
};
#endif


