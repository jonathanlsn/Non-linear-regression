#ifndef NODE
#define NODE

#include <iostream>
class Node{
  public:
//constructeur
    Node(std::string str);
    Node(std::string str,Node* precedent);
    Node(bool boleen,Node* precedent);
    Node(bool boleen);
    //Node(std::string param,bool boleen);
    Node(Node* node,std::string type);
    Node( Node * node);
    
//getter
    std::string values();
    bool bool_values();
    Node * FatherNode();
    Node * NextNode1();
    Node * NextNode2();
    std::string type();


//setter

    void setNextNodeNull();

    void setvalues(std::string str);

    void setFatherNode(Node* father);

    void setNextNode2(Node* next);

    void setNextNode(Node* NextNode);
 
    void setboolvalues(bool str);

    void settype(std::string str);

  protected:  

    std::string values_;
    bool bool_values_;
    int param_values_;
    Node * FatherNode_;
    Node * NextNode1_;
    Node * NextNode2_;
    std::string type_;

};
#endif
