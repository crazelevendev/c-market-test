#include <stdio.h>
#include <string.h>

typedef struct {
  char name[100];
  char position[4]; // here we choose 4 because of the null terminator \0
  float price;
  size_t quantity;
} Article;

int main(void) {
  Article article1 = {"Article 1", "AAA", 10.0, 50};
  Article article2 = {"Article 2", "AAB", 15.99, 20};
  printf("We have %llu %s at position %s, the price for one unit is %.2f$\n",
         article1.quantity, article1.name, article1.position, article1.price);
  printf("We have %llu %s at position %s, the price for one unit is %.2f$\n",
         article2.quantity, article2.name, article2.position, article2.price);
}
