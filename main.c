#include "hash.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int
main() {
  hash h = hash_new();
  hash_set(&h, "a", "1");
  hash_set(&h, "b", "2");
  hash_set(&h, "c", "3");
  hash_remove(&h, "b");
  printf("%s: %s\n", "a", hash_get(&h, "a"));
  printf("%s: %p\n", "b", hash_get(&h, "b"));
  printf("%s: %s\n", "c", hash_get(&h, "c"));
  hash_clear(&h);
  printf("%s: %p\n", "a", hash_get(&h, "a"));
  printf("%s: %p\n", "b", hash_get(&h, "b"));
  printf("%s: %p\n", "c", hash_get(&h, "c"));
  hash_free(&h);
  return 0;
}
