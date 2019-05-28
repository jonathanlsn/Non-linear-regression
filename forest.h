#ifndef FOREST_
#define FOREST_

#include "tree.h"
#include "matrix.h"
#include "node.h"


class Forest{

    friend class Tree;
  
  public:
     // Methods for insertions
     void PushBack(Tree* tree); // this method allows us to add a Tree at the end. It takes a Tree as parameter.
     void evolve(Matrix matrix_);  // this method allow to generate a new generation of trees from the best tree of previous generation
     void generation(int nb_gen,Matrix matrix_);  // this method allow to repeat evolve while forest contain nb_gen generations

		// Constructors
    Forest();  
    Forest(int lambda);   // condition : lambda=nombre d'enfants par génération
    Forest(const Forest&)=delete;  

        // Destructors
    ~Forest()=default; 
	
        // getter
    int nb_elmts(); // return the value of the attribut nb_elmts_ of the list.
    void show();   // renvoi le meilleur arbre de chaque génération
    Tree * showlast();  // return le dernier arbre de la forêt
    Tree * lastTree();  // return le dernier arbre de la fôret
    Tree * firstTree();  // return le premier arbre de la forêt
    
  protected:
    Tree* firstTree_;  // pointeur su le 1er arbre
    Tree* lastTree_;  // pointeur sur le dernier arbre
    int nb_elmts_;  // nombre d'arbres dans la forêt ( donc de générations )
    int lambda_;  // nombre d'enfants par génération 
};


#endif // FOREST_






