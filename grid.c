#include "size.h"
#include "grid.h"
#include "memory.h"

grid
grid_new(size size) {
  return (grid) {
    .size = size,
    .cell = memory_allocate(size.height * size.width, sizeof(void*)),
  };
}
