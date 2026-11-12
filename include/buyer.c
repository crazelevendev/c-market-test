// buyer.c

#include <stdio.h>
#include "article.h"
#include "buyer.h"

void printBuyerInv(const Buyer *buyer) {
  for (size_t i = 0; i < buyer->nb_item; i++) {
    printf("Slot %zu of %s's inventory is filled with %zu \"%s\"\n", i,
           buyer->name, buyer->inventory[i].quantity,
           buyer->inventory[i].name);
  }
}
