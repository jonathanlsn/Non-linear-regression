#ifndef NODE
#define NODE
class Node{
  
  public:
    //getters
    Node NextNode1();
    Node NextNode2();
    char value();
    //setters
    
    //constructor
  protected:
    char value_;
    Node * Nextnode1_;
    Node * Nextnode2_;
};
#endif
