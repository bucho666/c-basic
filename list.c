#include "list.h"
#include "memory.h"
#include <stdlib.h>

static void* iterator_remove(iterator* itr) {
  if (itr == NULL) return NULL;
  iterator* prev = itr->prev;
  iterator* next = itr->next;
  void* element = itr->element;
  if (prev != NULL) prev->next = next;
  if (next != NULL) next->prev = prev;
  free(itr);
  return element;
}

void list_add(list* list, void* element) {
  iterator* itr = memory_allocate(1, sizeof(iterator));
  itr->prev = list->end;
  itr->next = NULL;
  itr->element = element;
  if (list->begin == NULL) {
    list->begin = itr;
  } else {
    list->end->next = itr;
  }
  list->end = itr;
  list->size++;
}

void* list_pop(list* list) {
  list->size--;
  return iterator_remove(list->end);
}

void* list_shift(list* list) {
  list->size--;
  return iterator_remove(list->begin);
}

void* list_remove(list* list, iterator* itr) {
  list_each(i, *list) {
    if (i != itr) continue;
    list->size--;
    return iterator_remove(i);
  }
  return NULL;
}

void list_clear(list* list) {
  iterator* itr = list->begin;
  iterator* next;
  while(itr) {
    next = itr->next;
    free(itr);
    itr = next;
  }
  list->size = 0;
  list->begin = list->end = NULL;
}
