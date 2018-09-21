#pragma once

#include <stddef.h>

typedef struct {
  size_t size;
  void** element;
} array;

array array_new(size_t size);
void array_shuffle(array* array);
void array_resize(array* array, size_t size);
void array_free(array* array);
