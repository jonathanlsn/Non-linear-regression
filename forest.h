#include "tree.h"

#ifndef FOREST
#define FOREST
class Forest{

    friend class Tree;
  
  public:
     // Methods for insertions
     void PushBack(Tree x); // this method allows us to add a Tree in the at the end. It takes a Tree as parameter.

  
  protected:
    Tree* firstTree_;
    int nb_elmts_;
};
#endif
