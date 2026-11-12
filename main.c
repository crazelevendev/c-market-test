// main.c

#include <stdbool.h>
#include <stdio.h>

#define ARTICLE_NAME_SIZE 100
#define POSITION_SIZE 4 // here we choose 4 because of the null terminator \0
#define INVENTORY_SIZE 10
#define USERNAME_SIZE 100
#define RESELL_RATIO 0.8

typedef struct {
  char name[ARTICLE_NAME_SIZE];
  char position[POSITION_SIZE];
  float price;
  size_t quantity;
} Article;

typedef struct {
  float wallet;
  size_t nb_item;
  Article inventory[INVENTORY_SIZE];
  char name[USERNAME_SIZE];
} Buyer;

void printBuyerInv(const Buyer *buyer);
bool canBuyItem(const Buyer *buyer, const size_t quantity, const Article *article);
void buyItem(Buyer *buyer, const size_t quantity, Article *article);
void sellItem(Buyer *buyer, size_t position); // executive decision :
// selling an item does not put it back in the Articles; its consummed.
bool canSellItem(Buyer *buyer, size_t position);

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
  sellItem(&myself, 0);
  printBuyerInv(&myself);
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

void printBuyerInv(const Buyer *buyer) {
  for (size_t i = 0; i < buyer->nb_item; i++) {
    printf("Slot %zu of %s's inventory is filled with %zu \"%s\"\n", i,
           buyer->name, buyer->inventory[i].quantity,
           buyer->inventory[i].name);
  }
}

// position for selling is index starting from 0
bool canSellItem(Buyer *buyer, size_t position) {
  if (buyer->nb_item == 0) {
    printf("You have no item to sell");
    return false;
  }
  else if (position > (INVENTORY_SIZE - 1)) {
    printf("You only have %d inventory slot, please choose an inventory number between 0 and %d", INVENTORY_SIZE, (INVENTORY_SIZE - 1));
    return false;
  }
  else if (position > (buyer->nb_item - 1)) {
    printf("You only have %zu items, please choose a number between 1 and %zu", buyer->nb_item, (buyer->nb_item));
    return false;
  }
  return true;
}

void sellItem(Buyer *buyer, size_t position) {
  if (!canSellItem(buyer, position)) {
    return;
  }
  buyer->wallet += (buyer->inventory[position].price * RESELL_RATIO);
  for (size_t i = position; i < buyer->nb_item; i++) {
    buyer->inventory[i] = buyer->inventory[i + 1];
  }
  (buyer->nb_item)--;
}
