#include "node.h"
#include <iostream>

//constructor
Node::Node(std::string str){
  values_ = str;
  FatherNode_ = nullptr;
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;
}

Node::Node(std::string str, Node precedent){
  values_ = str;
  FatherNode_ = &precedent; 
  NextNode1_ = nullptr;
  NextNode2_ = nullptr;

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

Node* Node:: FatherNode(){
  return FatherNode_;
}

Node* Node::NextNode1(){
  return NextNode1_;
}

Node* Node:: NextNode2(){
  return NextNode2_;
}
