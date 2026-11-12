#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ARTICLE_NAME_SIZE 100
#define POSITION_SIZE 4
#define INVENTORY_SIZE 10
#define USERNAME_SIZE 100
#define ARTICLE_SIZE 120
#define BUYER_SIZE 200

typedef struct {
  char name[ARTICLE_NAME_SIZE];
  char position[POSITION_SIZE]; // here we choose 4 because of the null terminator \0
  float price;
  size_t quantity;
} Article;

typedef struct {
  float wallet;
  size_t nb_item;
  Article *inventory[INVENTORY_SIZE];
  char name[USERNAME_SIZE];
} Buyer;

void buyItem(Buyer *buyer, Article *article, size_t quantity);
bool canBuyItem(Buyer *buyer, size_t quantity, Article *article);
void printBuyerInv(Buyer *buyer);

int main(void) {
  Buyer myself = {100.00f, 0,{}, "Craz"};
  Article article1 = {"Article 1", "AAA", 1.0f, 50};
  Article article2 = {"Article 2", "AAB", 15.99f, 20};
  Article article3 = {"Article 3", "AAC", 2.99f, 7};
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
  if (buyer->nb_item >= INVENTORY_SIZE) {
    printf("Your inventory is full\n"); // tested
    return false;
  } else if (quantity >
             (INVENTORY_SIZE - buyer->nb_item)) {
    printf(
        "You cannot buy more than your inventory room left (%llu slots left)\n",
        (INVENTORY_SIZE -
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
	
	memcpy(buyer->inventory[i], article, ARTICLE_SIZE);
//	strncpy(buyer->inventory[i]->name, article->name, 100);
//	strncpy(buyer->inventory[i]->position, article->position, 4);
//	buyer->inventory[i]->price = article->price;
	buyer->inventory[i]->quantity = 1;
  }

  buyer->nb_item += quantity;
  buyer->wallet -= article->price * quantity;
}
