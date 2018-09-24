#include "size.h"
#include "grid.h"
#include "memory.h"

static inline size_t
index_of(const grid* grid, int x, int y) {
  return (grid->size.width * y + x) * grid->data_size;
}

grid
grid_new(size size, size_t data_size) {
  return (grid) {
    .size = size,
    .data_size = data_size,
    .cell = memory_allocate(size.height * size.width, data_size),
  };
}

void* grid_get(const grid* grid, int x, int y) {
  return grid->cell + index_of(grid, x, y);
}

void grid_set(grid* grid, int x, int y, void* value) {
  void* p = grid->cell + index_of(grid, x, y);
  memory_copy(value, p, grid->data_size);
}
