#ifndef TEMP_H
#define TEMP_H
#include <stdlib.h>

typedef struct Article Article;

void initArticle(Article *self, char *name, char *position, float price,
                 size_t quantity);
Article *createNew(void);
char* getName(Article* self);
char* getPosition(Article* self);
size_t getQuantity(Article* self);
float getPrice(Article* self);

void setName(Article* self, char* name);

#endif
