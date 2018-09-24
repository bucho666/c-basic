#pragma once
#include "size.h"
#include "type.h"
#include "memory.h"

typedef struct {
  size size;
  void** cell;
} grid;

grid grid_new(size size);

inline grid grid_new(size size) {
  return (grid) {
    .size = size,
    .cell = memory_allocate(size.height * size.width, sizeof(void*)),
  };
}

inline void* grid_get(const grid* grid, int x, int y) {
  return grid->cell[grid->size.width * y + x];
}

inline void grid_set(grid* grid, int x, int y, void* value) {
  grid->cell[grid->size.width * y + x] = value;
}
