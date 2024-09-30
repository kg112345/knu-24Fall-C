#include <stdio.h>

int main(void) {
	int layer;

	printf("ÇÇ¶ó¹Ìµå Ãþ: ");
	scanf_s("%d", &layer);

	for (int i = 0; i < layer; i++) {
		for (int j = i; j < layer - 1 ; j++) {
			printf(" ");
		}

		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}

		printf("\n");
	}
}