#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static inline void*
memory_allocate(size_t number, size_t size) {
  void* m = calloc(number, size);
  if (m) return m;
  fprintf(stderr, "out of memory\n");
  exit (EXIT_FAILURE);
}

static inline void*
memory_resize(void* memory, size_t size) {
  void* m = realloc(memory, size);
  if (m) return m;
  fprintf(stderr, "out of memory\n");
  exit (EXIT_FAILURE);
}

static inline void
memory_copy(const void* src, void* dst, size_t size) {
  memcpy(dst, src, size);
}
