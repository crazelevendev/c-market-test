#include "temp.h"
#include <stdio.h>
#include <string.h>

struct Article {
  char name[100];
  char position[4];
  float price;
  size_t quantity;
};

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

char *getName(Article *self) { return self->name; }
char *getPosition(Article *self) { return self->position; }
size_t getQuantity(Article *self) { return self->quantity; }
float getPrice(Article *self) { return self->price; }

void setName(Article *self, char *name) {
  strncpy(self->name, name, sizeof(self->name));
}
