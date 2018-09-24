#include "random.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int
random_range(int min, int max) {
  static bool initialize = false;
  if (!initialize) {
    srandom(time(NULL));
    initialize = true;
  }
  return (random() % (max - min + 1)) + min;
}
