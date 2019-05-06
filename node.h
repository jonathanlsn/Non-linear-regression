#ifndef NODE
#define NODE
class Node{
  
  public:
    //getters
    Node NextNode1();
    Node NextNode2();
    char value();
    //setters
    
    //constructors//
    Node (int var): //Node variable ou constante
    Node (int var,Node* next_node1); // Node pour opérateur not
    Node (int var,Node* next_node1, Node* next_node2); // node pour opérateur
  
  protected:
    char[] valeur_;
    Node* next_node1_;
    Node* next_node2_; 
};
#endif
