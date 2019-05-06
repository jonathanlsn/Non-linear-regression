

#ifndef NODE
#define NODE



#include <iostream>
class Node{
  public:
//constructeur
    Node(std::string str);
    Node(std::string str,Node precedent);

//getter
    std::string values();
    Node * FatherNode();
    Node * NextNode1();
    Node * NextNode2();
  
  protected:

    std::string values_;
    Node * FatherNode_;
    Node * NextNode1_;
    Node * NextNode2_;


};
#endif
