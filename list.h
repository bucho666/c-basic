#pragma once
#include <stddef.h>

#define list_each(element, list) for (iterator* (element) = (list).begin; (element); (element) = (element)->next)

typedef struct iterator {
  struct iterator* next;
  struct iterator* prev;
  void *element;
} iterator;

typedef struct {
  size_t size;
  iterator* begin;
  iterator* end;
} list;

inline list list_new() {
  return (list) {
    .size = 0,
    .begin = NULL,
    .end = NULL
  };
}

void list_add(list* list, void* element);
void* list_pop(list* list);
void* list_shift(list* list);
void* list_remove(list* list, iterator* itr);
void list_clear(list* list);
