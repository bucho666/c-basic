#include "list.h"
#include "size.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int
main() {
  size size = size_new(3, 4);
  bool map[size.height][size.width];
  for (int y = 0; y < size.height; y++) {
    for (int x = 0; x < size.width; x++) {
      printf("x:%d y:%d v:%d\n", x, y, map[y][x]);
    }
  }
}
