#include "random.h"
#include <stdio.h>

main() {
  for (int i = 0; i < 100; i++) {
    printf("%d ", random_range(4, 6));
    if (i % 10 == 9) printf("\n");
  }
}
