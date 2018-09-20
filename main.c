#include "random.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int
main() {
  array a = array_new(5);
  a.element[0] = "1";
  a.element[1] = "2";
  a.element[2] = "3";
  a.element[3] = "4";
  a.element[4] = "5";
  array_shuffle(&a);
  array_resize(&a, 6);
  a.element[5] = "resize";
  for (int i = 0; i < a.size; i++) {
    printf("%s ", (char*)a.element[i]);
  }
  printf("\n");
  array_free(&a);
  return 0;
}
