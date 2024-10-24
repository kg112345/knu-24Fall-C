#include <stdio.h>

struct Product {
	int id;
	char name[100];
	int price;
};

void printProduct(struct Product product) {
	printf("상품 id: %d\n", product.id);
	printf("상품 name: %s\n", product.name);
	printf("상품 price: %d\n\n", product.price);
}

int main(void) {
	struct Product productArray[5];
	int hoice;
	int i;

	for (i = 0; i < 5; i++) {
		printf("상품 정보 입력(입력 중단은 id에 0 입력)\n");

		printf("상품 id:");
		scanf_s("%d", &productArray[i].id);
		if (productArray[i].id == 0) {
			break;
		}

		printf("상품 name:");
		scanf_s("%s", &productArray[i].name, sizeof(productArray[i].name));

		printf("상품 price:");
		scanf_s("%d", &productArray[i].price);

		printf("\n");
	}

	printf("\n\n<<입력한 상품>>\n");
	for (int j = 0; j < i; j++) {
		printProduct(productArray[j]);
	}
}
