// main.c

#include <stdbool.h>
#include <stdio.h>
#include "article.h"
#include "buyer.h"

bool canBuyItem(const Buyer *buyer, const size_t quantity, const Article *article);
void buyItem(Buyer *buyer, const size_t quantity, Article *article);

int main(void) {
  Buyer myself = {.wallet = 100.00f, .nb_item = 0, .name = "Craz"};
  Article article1 = {"Article 1", "AAA", 1.0f, 50};
  Article article2 = {"Article 2", "AAB", 15.99f, 20};
  Article article3 = {"Article 3", "AAC", 2.99f, 7};
  printf("We have %zu %s at position %s, the price for one unit is %.2f$\n",
         article1.quantity, article1.name, article1.position, article1.price);
  printf("We have %zu %s at position %s, the price for one unit is %.2f$\n",
         article2.quantity, article2.name, article2.position, article2.price);
  buyItem(&myself, 1, &article2);
  buyItem(&myself, 1, &article3);
  printBuyerInv(&myself);
  buyItem(&myself, 8, &article1);
  printBuyerInv(&myself);
  printf("Article 1 has %zu articles left\n", article1.quantity);
}

bool canBuyItem(const Buyer *buyer, const size_t quantity, const Article *article) {
  if (buyer->nb_item >= INVENTORY_SIZE) {
    printf("Your inventory is full\n"); // tested
    return false;
  } else if (quantity >
             (INVENTORY_SIZE - buyer->nb_item)) {
    printf(
        "You cannot buy more than your inventory room left (%zu slots left)\n",
        (INVENTORY_SIZE -
         buyer->nb_item)); // tested
    return false;
  } else if (quantity > article->quantity) {
    printf("There is only %zu \"%s\" left\n", article->quantity,
           article->name); // tested
    return false;
  } else if (buyer->wallet < (article->price * quantity)) {
    printf("You only have %.2f$ left! You cant buy %zu \"%s\" (%.2f$)\n",
           buyer->wallet, quantity, article->name,
           article->price * quantity); // tested
    return false;
  }
  return true;
}

void buyItem(Buyer *buyer, const size_t quantity, Article *article) {
  if (!canBuyItem(buyer, quantity, article)) {
    return;
  }
  article->quantity -= quantity;

  for (size_t i = buyer->nb_item; i < buyer->nb_item + quantity; i++) {
    buyer->inventory[i] = *article;
    buyer->inventory[i].quantity = 1;
  }

  buyer->nb_item += quantity;
  buyer->wallet -= article->price * quantity;
}
