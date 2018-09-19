#pragma once

typedef struct {
  int width;
  int height;
} size;

inline size size_new(int width, int height) { return (size){ .width = width, .height = height }; }
