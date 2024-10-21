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
	int count = 0, choice;

	while (count < 5) {
		printf("상품 정보 입력(입력 중단은 id에 0 입력)\n");

		printf("상품 id:");
		scanf_s("%d", &productArray[count].id);
		if (productArray[count].id == 0) {
			break;
		}

		printf("상품 name:");
		scanf_s("%s", &productArray[count].name, sizeof(productArray[count].name));
		
		printf("상품 price:");
		scanf_s("%d", &productArray[count].price);

		printf("\n");

		count++;
	}
	
	printf("\n\n<<입력한 상품>>\n");
	for (int i = 0; i < count; i++) {
		printProduct(productArray[i]);
	}
}
