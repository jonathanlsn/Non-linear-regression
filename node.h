#ifndef NODE
#define NODE

#include <iostream>
class Node{
  public:
//constructeur
    Node(std::string str);  // constructor from str value
    Node(std::string str,Node* precedent);  // constructor from str value and adress of previous node

    Node(const Node * node);  // copy constructor
    
//getter
    std::string values();  // return the value of the node
    bool bool_values();  // if node have a "true" or "false" value, it return the boolean value 
    Node * FatherNode();  // Adress of the previous node
    Node * NextNode1();  // Return the adress of the left side following node 
    Node * NextNode2();  // Return the adress of the right side following node
    std::string type();


//setter

    void setNextNodeNull();  // set NextNode1 et NextNode2 to nullptr

    void setvalues(std::string str);  // set the value of the node

    void setFatherNode(Node* father);  // set the adress of the previous node

    void setNextNode2(Node* next);  // set the adress of the right side following node

    void setNextNode(Node* NextNode);  // set the adress of the left side following node
 
    void setboolvalues(bool str);  // set the boolean value 

    void settype(std::string str);  // set the type of the node

//destructor 
   
   ~Node()=default;
   void deleted(Node * node);
   
   void sup();
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
