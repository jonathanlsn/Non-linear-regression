#include "node.h"
#include <iostream>

//constructor



Node::Node(const Node * node){  // Copy constructor
  FatherNode_ = nullptr;
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  type_=this->type();
  values_=this->values();
  if (type_=="bool"){
    bool_values_=this->bool_values();
  }
}



Node::Node(std::string str){
  values_ = str;
  FatherNode_ = nullptr;
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  if (str=="true"){
    type_= "bool";
    bool_values_ =true;
  }
  if (str=="false"){
    type_= "bool";
    bool_values_ =false;
  }
  if (str=="x1" or str=="x2" or str=="x3"){
    type_="param";
  }
  else{
    type_= "op";
  }
}




Node::Node(std::string str, Node* precedent){
  values_ = str;
  FatherNode_ = precedent; 
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  
  if (str=="true"){
    type_= "bool";
    bool_values_ =true;
  }
  if (str=="false"){
    type_= "bool";
    bool_values_ =false;
  }
  if (str=="x1" or str=="x2" or str=="x3"){
    type_="param";
  }
  else{
    type_= "op";
  }

  if (FatherNode_ ->NextNode1_ == nullptr){
    FatherNode_ ->NextNode1_ = this;
  }
  else {
    FatherNode_ ->NextNode2_ = this;
  }
}




//getter
std::string Node::values(){
  return values_;
}

bool Node::bool_values(){
  return bool_values_;
}

Node* Node:: FatherNode(){
  return FatherNode_;
}

Node* Node::NextNode1(){
  return NextNode1_;
}

Node* Node:: NextNode2(){
  return NextNode2_;
}

std::string Node::type(){
  return type_;
}

//setter
void Node::setNextNode(Node* NextNode){
  NextNode1_=NextNode;
}

void Node::setNextNodeNull(){
  NextNode1_=nullptr;
  NextNode2_=nullptr;
}

void Node::setvalues(std::string str){
  values_=str;
}
void Node::setFatherNode(Node* father){
  FatherNode_=father;
}

void Node::setNextNode2(Node* next){
  NextNode2_=next;
}

void Node::setboolvalues(bool str){
  bool_values_=str;
}

void Node::settype(std::string str){
  type_=str;
}



void Node::deleted(Node * node){
  if (node->values()=="x" or node->values()=="num"){
    delete node;
  }
  else{
    deleted(NextNode1_);
    deleted(NextNode2_);
    delete node;
  }
}


void Node::sup(){
  deleted(this);
}



