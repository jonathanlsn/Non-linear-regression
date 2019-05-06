#ifndef NODE
#define NODE

#include <iostream>
class Node{
  public:
//constructeur
    Node(std::string str);
    Node(std::string str,Node precedent);
    Node(bool boleen,Node precedent);
    Node(bool boleen);

//getter
    std::string values();
    bool bool_values();
    Node * FatherNode();
    Node * NextNode1();
    Node * NextNode2();
    std::string type();
  
  protected:

    std::string values_;
    bool bool_values_;
    Node * FatherNode_;
    Node * NextNode1_;
    Node * NextNode2_;
    std::string type_;

};
#endif
