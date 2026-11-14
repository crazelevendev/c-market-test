#include "arraylist.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_ARRAY(arr)                                                       \
  do {                                                                         \
    for (size_t i = 0; i < arr->size; i++) {                                   \
      printf("%d, ", getArrayElement(arr, i));                                 \
    }                                                                          \
    printf("\n");                                                              \
  } while (false)

// typedef struct {
//   size_t capacity; // occupied space
//   size_t size;     // total space
//   int64_t *data;
// } Array;

ArrayList *execute(ArrayList *array, bool (*func)(int num, int *out));
bool square(int num, int *out);
bool isEven(int num, int *out);

int main(void) {
  ArrayList *awiudgawkjyhudgkjwd = createArray(5);
  for (size_t i = 0; i < awiudgawkjyhudgkjwd->capacity; i++) {
    appendToArray(awiudgawkjyhudgkjwd, i);
  }
  PRINT_ARRAY(awiudgawkjyhudgkjwd);
  ArrayList *jahkgdkwjhdg = execute(awiudgawkjyhudgkjwd, square);
  PRINT_ARRAY(jahkgdkwjhdg);
  jahkgdkwjhdg = execute(jahkgdkwjhdg, isEven);
  PRINT_ARRAY(jahkgdkwjhdg);
  return 0;
}

ArrayList *execute(ArrayList *array, bool (*func)(int num, int *out)) {
  ArrayList *new = createArray(array->capacity);

  bool success;
  int result;

  for (int i = 0; i < array->size; i++) {
    success = func(array->data[i], &result);
    if (success)
      appendToArray(new, result);
  }
  return new;
}

bool square(int num, int *out) {
  *out = num * num;
  return true;
}
bool isEven(int num, int *out) {
  *out = num;
  return !(num & 1);
}
