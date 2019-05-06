#include "node.h"
#include <cstdlib>

Node::Node(){
  value_=rand()%1 +0;
}


Node::Node(char value){
  if (value=="&&"){
    value_=value;
    Nextnode1_= new Node node();
    Nextnode2_= new Node node();
  }
  if (value=="||"){
    value_=value;
    Nextnode1_= new Node node();
    Nextnode2_= new Node node();
  }
  if (value=="!"){
    value_=value;
    Nextnode1_= new Node node();
  }
  else{
  
  }
}
