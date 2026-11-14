#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdint.h>

typedef struct {
  size_t size;
  size_t capacity;
  int *data;
} ArrayList;

ArrayList *createArray(uint32_t capacity);
char isArrayFull(ArrayList *list);
void appendToArray(ArrayList *list, int value);
int getArrayElement(ArrayList *list, size_t position);
void insertInArrayAt(ArrayList *list, size_t position, int value);

#endif
