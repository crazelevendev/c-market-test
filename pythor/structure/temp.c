#include "temp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initArticle(Article *self, char *name, char *position, float price,
                 size_t quantity) {
  strncpy(self->name, name, sizeof(self->name));
  strncpy(self->position, position, sizeof(self->position));
  self->price = price;
  self->quantity = quantity;
}

Article *createNew(void) {
  Article *article = malloc(sizeof(Article));
  if (!article)
    return NULL;
  return article;
}
