#include "temp.h"
#include <stdio.h>

int main(void) {
  Article *article1 = createNew(); // HEAP
  Article article2;                // STACK
  initArticle(&article2, "Salut", "AAB", 20.0f, 18);

  initArticle(article1, "Article 1", "AAA", 10.0, 50);
  printf("We have %zu %s at position %s, the price for one unit is %.2f$\n",
         article1->quantity, article1->name, article1->position,
         article1->price);
  printf("We have %zu %s at position %s, the price for one unit is %.2f$\n",
         article2.quantity, article2.name, article2.position, article2.price);
  return 0;
}
