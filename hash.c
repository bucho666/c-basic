#include "hash.h"
#include "memory.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bucket removed;

static inline void
free_bucket(bucket* b) {
  free(b->key);
  free(b);
}

static inline int
calculate_usable_buckets(int size) {
  return (size * 2 + 1) / 3;
}

static inline unsigned long
calculate_hash(const char* key) {
  unsigned long hash_value = 0;
  for (const char* c = key; *c != '\0'; c++) {
    hash_value = (hash_value + *c) * 23 % 65536;
  }
  return hash_value;
}

static inline int
find_open_index(hash* hash, int index) {
  while (hash->table[index] != NULL || hash->table[index] == &removed) {
    index = (index + 1) % hash->size;
  }
  return index;
}

static int
get_index_of_key(hash* hash, const char* key) {
  int index = calculate_hash(key) % hash->size;
  int last = (hash->size + index - 1) % hash->size;
  for (; index != last; index = (index + 1) % hash->size) {
    if (hash->table[index] == NULL) break;
    if (hash->table[index] == &removed) continue;
    if (strcmp(hash->table[index]->key, key)) continue;
    return index;
  }
  return -1;

}

static void rehash(hash* hash) {
  int old_size = hash->size;
  bucket** old_table = hash->table;
  hash->size = old_size * 2;
  hash->usable_buckets = calculate_usable_buckets(hash->size);
  hash->table  = memory_allocate(hash->size, sizeof(bucket*));
  for (int i = 0; i < old_size; i++) {
    if (old_table[i] == NULL) continue;
    bucket* b = old_table[i];
    int index = find_open_index(hash, b->hash % hash->size);
    hash->table[index] = b;
  }
  free(old_table);
}


hash
hash_new() {
  int initial_size = 8;
  return (hash) {
    .table = memory_allocate(initial_size, sizeof(bucket*)),
    .size = initial_size,
    .usable_buckets = calculate_usable_buckets(initial_size)
  };
}

void
hash_set(hash* hash, const char* key, void* data) {
  bucket* new_bucket = memory_allocate(1, sizeof(bucket));
  new_bucket->data = data;
  new_bucket->hash = calculate_hash(key);
  new_bucket->key = strcpy(memory_allocate(strlen(key) + 1, sizeof(char)), key);
  int index = find_open_index(hash, new_bucket->hash % hash->size);
  hash->table[index] = new_bucket;
  hash->usable_buckets--;
  if (hash->usable_buckets == 0) rehash(hash);
}

void*
hash_get(hash* hash, const char* key) {
  int index = get_index_of_key(hash, key);
  if (index == -1) return NULL;
  return hash->table[index]->data;
}

void*
hash_remove(hash* hash, const char* key) {
  int index = get_index_of_key(hash, key);
  if (index == -1) return NULL;
  void* data = hash->table[index]->data;
  free_bucket(hash->table[index]);
  hash->table[index] = &removed;
  return data;
}

void
hash_clear(hash* hash) {
  for (int i = 0; i < hash->size; i++) {
    bucket *b = hash->table[i];
    if (b && b != &removed) free_bucket(b);
    hash->table[i] = NULL;
  }
}

void
hash_free(hash *hash) {
  hash_clear(hash);
  free(hash->table);
}
