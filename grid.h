#pragma once
#include "size.h"
#include "type.h"

typedef struct {
  size size;
  size_t data_size;
  byte *cell;
} grid;

grid grid_new(size size, size_t data_size);
void* grid_get(const grid* grid, int x, int y);
void grid_set(grid* grid, int x, int y, void* value);
