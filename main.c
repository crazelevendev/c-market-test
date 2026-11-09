#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
	char name[100];
	char position[3];
	float price;
	size_t quantity;
} Article;

Article createNew(char name[100], char position[3], float price, size_t quantity);

int main(void) {
	Article article1 = createNew("Article 1", "AAA", 10.0, 50);
	printf("We have %d %s at position %s, the price for one unit is %.2f$\n", article1.quantity,article1.name,article1.position,article1.price);
	return 0;
}

Article createNew(char name[100], char position[3], float price, size_t quantity) {
	char articleName[100];
	char articlePisition[3];
	strncpy(articleName, name, sizeof(articleName));
	strncpy(articlePosition, position, sizeof(articlePosition));
	Article newArticle = {articleName, articlePosition, price, quantity};
	return newArticle;
}
