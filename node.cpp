#include "node.h"
#include <iostream>

//constructor
Node::Node(std::string str){
  values_ = str;
  FatherNode_ = nullptr;
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  type_= "op";
}

Node::Node(bool boleen){
  bool_values_ = boleen;
  FatherNode_ = nullptr;
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  type_= "bool";
}

Node::Node(std::string str, Node* precedent){
  values_ = str;
  FatherNode_ = precedent; 
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  type_= "op";

  if (FatherNode_ ->NextNode1_ == nullptr){
    FatherNode_ ->NextNode1_ = this;
  }
  else {
    FatherNode_ ->NextNode2_ = this;
  }
}

Node::Node(bool boleen,Node* precedent){
  bool_values_ = boleen;
  FatherNode_ = precedent; 
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  type_= "bool";


 
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
