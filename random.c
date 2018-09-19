#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "random.h"

int random_range(int min, int max) {
  static bool initialize = false;
  if (!initialize) {
    srand(time(NULL));
    initialize = true;
  }
  return (rand() % (max - min + 1)) + min;
}


