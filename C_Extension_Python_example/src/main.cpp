#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"

int main(int argc, char const *argv[]) {
  A my_a = A(12);
  printf("a\n");
  my_a.Print();
  A my_b = A(3);
  printf("b\n");
  my_b.Print();
  my_a.Clone(&my_b);
  printf("a\n");
  my_a.Print();
  printf("---------------------\n");
  B my_B = B(3);
  my_B.Print();
}
