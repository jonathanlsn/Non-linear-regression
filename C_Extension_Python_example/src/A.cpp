#include <stdio.h>
#include <stdlib.h>
#include "A.h"

A::A(int val){
  a = val;
  array = (bool*) malloc (a * sizeof(a));
  for (int i = 0; i < a; i ++){
    array[i] = i*2;
  }
}

void A::Clone(A* other){
    a = other->a;
    array = (bool*) realloc(array, a * sizeof(a));
    for (int i = 0; i < a; i ++){
      array[i] = other->array[i];
    }
}

A::~A(){
  free(array);
}

void A::Print(){
    printf("*****************************************************\n");
    printf("––––––PRINTING A–––––\n");
    printf("a: %d\n",a);
    printf("----------values in array------------\n");
    for(int i = 0; i < a; i ++){
        printf("value at index %d : %d\n",i,array[i]);
    }
    printf("*****************************************************\n");
    printf("\n");
}
