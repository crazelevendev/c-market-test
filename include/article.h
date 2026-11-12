// article.c
#ifndef ARTICLE_H
#define ARTICLE_H

#define ARTICLE_NAME_SIZE 100
#define POSITION_SIZE 4 // here we choose 4 because of the null terminator \0

typedef struct {
  char name[ARTICLE_NAME_SIZE];
  char position[POSITION_SIZE];
  float price;
  size_t quantity;
} Article;

#endif
