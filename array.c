#include "array.h"
#include "random.h"
#include "macro.h"
#include "memory.h"
#include <stdlib.h>

array
array_new(size_t size) {
  return (array){
    .size = size,
    .element = memory_allocate(size,  sizeof(void*))
  };
}

void
array_shuffle(array* array) {
  for (size_t a = array->size - 1; a > 0; a--) {
    size_t b = random_range(0, a);
    swap(array->element[a], array->element[b]);
  }
}

void
array_resize(array* array, size_t size) {
  array->element = memory_resize(array->element, sizeof(void*) * size);
  array->size = size;
}

void
array_free(array* array) {
  free(array->element);
}
