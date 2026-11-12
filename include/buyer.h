// buyer.h

#ifndef BUYER_H
#define BUYER_H

#define INVENTORY_SIZE 10
#define USERNAME_SIZE 100

typedef struct {
  float wallet;
  size_t nb_item;
  Article inventory[INVENTORY_SIZE];
  char name[USERNAME_SIZE];
} Buyer;

void printBuyerInv(const Buyer *buyer);

#endif
