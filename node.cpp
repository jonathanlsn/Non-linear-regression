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

Node::Node(std::string str, Node precedent){
  values_ = str;
  FatherNode_ = &precedent; 
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  type_= "op";

  if (NextNode1_ == nullptr){
    precedent.NextNode1_ = this;
  }
  else {
    precedent.NextNode2_ = this;
  }
}

Node::Node(bool boleen,Node precedent){
  bool_values_ = boleen;
  FatherNode_ = &precedent; 
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
  type_= "bool";

  if (NextNode1_ == nullptr){
    precedent.NextNode1_ = this;
  }
  else {
    precedent.NextNode2_ = this;
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
