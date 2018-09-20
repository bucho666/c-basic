#include "random.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int
main() {
  size_t size = 5;
  array a = array_new(size);
  a.element[0] = "1";
  a.element[1] = "2";
  a.element[2] = "3";
  a.element[3] = "4";
  a.element[4] = "5";
  array_shuffle(&a);
  for (int i = 0; i < a.size; i++) {
    printf("%c ", *(char*)a.element[i]);
  }
  printf("\n");
  array_free(&a);
  return 0;
}
