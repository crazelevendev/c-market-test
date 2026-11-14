#ifndef TEMP_H
#define TEMP_H

// typedef struct Article Article;
typedef struct {
  char name[100];
  char position[4];
  float price;
  size_t quantity;
} Article;

void initArticle(Article *self, char *name, char *position, float price,
                 size_t quantity);
Article *createNew(void);

#endif
