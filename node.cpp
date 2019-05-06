#include "node.h"
#include <iostream>

//constructor
Node::Node(std::string str);{
  values = str;
  FatherNode_ = nullptr;
  NextNode1_ = nullptr;
  Nextnode2_ = nullptr;
}

Node::Node(std::string str, Node precedent){
  values_ = str;
  FatherNode_ = &precedent; 
  NextNode1_ = nullptr;
  Nextnode2_ = nullptr;

  if (NextNode1_ == nullptr){
    precedent.NextNode1_ = &this;
  }
  else {
    precedent.NextNode2_ = &this;
  }

}

//getter
Node::std::string values(){
  return values_;
}

Node::Node * FatherNode(){
  return FatherNode;
}

Node::Node * NextNode1(){
  return NextNode1_;
}

Node::Node * NextNode2(){
  return NextNode2_;
}
