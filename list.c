#include "list.h"
#include "memory.h"
#include <stdlib.h>

static void*
iterator_remove(iterator* itr) {
  if (itr == NULL) return NULL;
  iterator* prev = itr->prev;
  iterator* next = itr->next;
  if (prev != NULL) prev->next = next;
  if (next != NULL) next->prev = prev;
  byte* data = itr->data;
  free(itr);
  return data;
}

void
list_add(list* list, void* data) {
  iterator* itr = memory_allocate(1, sizeof(iterator));
  itr->prev = list->end;
  itr->next = NULL;
  itr->data = memory_allocate(1, list->size);
  memory_copy(data, itr->data, list->size);
  if (list->begin == NULL) {
    list->begin = itr;
  } else {
    list->end->next = itr;
  }
  list->end = itr;
  list->length++;
}

void*
list_pop(list* list) {
  list->length--;
  return iterator_remove(list->end);
}

void*
list_shift(list* list) {
  list->length--;
  return iterator_remove(list->begin);
}

void
list_remove(list* list, iterator* itr) {
  for (iterator* i = list->begin; i; i = i->next) {
    if (i != itr) continue;
    list->size--;
    free(iterator_remove(i));
  }
}

void
list_clear(list* list) {
  iterator* itr = list->begin;
  iterator* next;
  while(itr) {
    next = itr->next;
    free(itr->data);
    free(itr);
    itr = next;
  }
  list->length = 0;
  list->begin = list->end = NULL;
}
