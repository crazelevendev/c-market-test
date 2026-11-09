#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char name[100];
  char position[4]; // here we choose 4 because of the null terminator \0
  float price;
  size_t quantity;
} Article;

typedef struct {
  float wallet;
  size_t nb_item;
  Article *inventory[10];
  char name[100];
} Buyer;

void buyItem(Buyer *buyer, Article *article, size_t quantity);
bool canBuyItem(Buyer *buyer, size_t quantity, Article *article);
void printBuyerInv(Buyer *buyer);

int main(void) {
  Buyer myself = {100.00f, 0, {}, "Craz"};
  Article article1 = {"Article 1", "AAA", 1.0, 50};
  Article article2 = {"Article 2", "AAB", 15.99, 20};
  Article article3 = {"Article 3", "AAC", 2.99, 7};
  printf("We have %llu %s at position %s, the price for one unit is %.2f$\n",
         article1.quantity, article1.name, article1.position, article1.price);
  printf("We have %llu %s at position %s, the price for one unit is %.2f$\n",
         article2.quantity, article2.name, article2.position, article2.price);
  buyItem(&myself, &article2, 1);
  buyItem(&myself, &article3, 1);
  printBuyerInv(&myself);
  buyItem(&myself, &article1, 8);
  printBuyerInv(&myself);
}

void printBuyerInv(Buyer *buyer) {
  for (size_t i = 0; i < buyer->nb_item; i++) {
    printf("Slot %llu of %s's inventory is filled with %llu \"%s\"\n", i,
           buyer->name, buyer->inventory[i]->quantity,
           buyer->inventory[i]->name);
  }
}

bool canBuyItem(Buyer *buyer, size_t quantity, Article *article) {
  if (buyer->nb_item >= sizeof(buyer->inventory) / sizeof(Article *)) {
    printf("Your inventory is full\n"); // tested
    return false;
  } else if (quantity >
             (sizeof(buyer->inventory) / sizeof(Article *) - buyer->nb_item)) {
    printf(
        "You cannot buy more than your inventory room left (%llu slots left)\n",
        (sizeof(buyer->inventory) / sizeof(Article *) -
         buyer->nb_item)); // tested
    return false;
  } else if (quantity > article->quantity) {
    printf("There is only %llu \"%s\" left\n", article->quantity,
           article->name); // tested
    return false;
  } else if (buyer->wallet < (article->price * quantity)) {
    printf("You only have %.2f$ left! You cant buy %llu \"%s\" (%.2f$)\n",
           buyer->wallet, quantity, article->name,
           article->price * quantity); // tested
    return false;
  }
  return true;
}

void buyItem(Buyer *buyer, Article *article, size_t quantity) {
  if (!canBuyItem(buyer, quantity, article)) {
    return;
  }
  article->quantity -= quantity;

  for (size_t i = buyer->nb_item; i < buyer->nb_item + quantity; i++) {
    buyer->inventory[i] = article;
    buyer->inventory[i]->quantity = 1;
  }

  buyer->nb_item += quantity;
  buyer->wallet -= article->price * quantity;
}
