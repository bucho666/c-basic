#include "array.h"
#include "memory.h"
#include "random.h"

typedef char byte;

array
array_new(size_t length, size_t size) {
  return (array) {
    .length = length,
    .size = size,
    .element = memory_allocate(length,  size),
  };
}

void
array_shuffle(array* array) {
  byte temp[array->size];
  size_t size = array->size;
  for (size_t i = array->length - 1; i > 0; i--) {
    size_t t = random_range(0, i);
    memory_copy(array->element + (i * size), temp, size);
    memory_copy(array->element + (t * size), array->element + (i * size), size);
    memory_copy(temp, array->element + (t * size), size);
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
