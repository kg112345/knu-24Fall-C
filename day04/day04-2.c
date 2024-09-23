#include <stdio.h>

void swap(int* a, int* b) {
	a = 20;
	b = 10;

	printf("a: %d, b: %d", a, b);
}

int main(void) {
	int a = 10;
	int b = 20;

	printf("a: %d, b: %d \n", a, b);

	swap(&a, &b);
}