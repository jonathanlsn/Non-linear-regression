#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"

B::B(int val){
  b = val;
  array = (A**) malloc (b * sizeof(A*));
  for (int i = 0; i < b; i ++){
    array[i] = new A(i);
  }
}

B::~B(){
  for (int i = 0; i < b; i ++){
    delete array[i];
  }
  free(array);
}

void B::Print(){
    printf("*****************************************************\n");
    printf("––––––PRINTING B–––––\n");
    printf("b: %i\n",b);
    printf("----------values in array------------\n");
    for(int i = 0; i < b; i ++){
        array[i]->Print();
    }
    printf("*****************************************************\n");
    printf("\n");
}
