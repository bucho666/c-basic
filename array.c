#include "array.h"
#include "random.h"
#include <stdlib.h>

array
array_new(size_t size) {
  return (array){
    .size = size,
    .element = (void**)calloc(size,  sizeof(void*))
  };
}

void
array_shuffle(array* array) {
  for (size_t a = array->size - 1; a > 0; a--) {
    size_t b = random_range(0, a);
    void* tmp = array->element[b];
    array->element[b] = array->element[a];
    array->element[a] = tmp;
  }
}

void
array_free(array* array) {
  free(array->element);
}
