#include "temp.h"
#include <stdio.h>

int main(void) {
  Article *article1 = createNew(); // HEAP

  initArticle(article1, "Article 1", "AAA", 10.0f, 50);
  printf("We have %zu %s at position %s, the price for one unit is %.2f$\n",
         getQuantity(article1), getName(article1), getPosition(article1),
         getPrice(article1));
  setName(article1, "Salut Article 2 mtn");
  printf("We have %zu %s at position %s, the price for one unit is %.2f$\n",
         getQuantity(article1), getName(article1), getPosition(article1),
         getPrice(article1));
  return 0;
}
