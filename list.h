#pragma once

#include "type.h"
#include <stddef.h>

typedef struct iterator {
  struct iterator* next;
  struct iterator* prev;
  void* data;
} iterator;

typedef struct {
  size_t length;
  iterator* begin;
  iterator* end;
} list;

inline list list_new(size_t size) {
  return (list) {
    .length = 0,
    .begin = NULL,
    .end = NULL
  };
}

void list_add(list* list, void* data);
void* list_pop(list* list);
void* list_shift(list* list);
void* list_remove(list* list, iterator* itr);
void list_clear(list* list);
