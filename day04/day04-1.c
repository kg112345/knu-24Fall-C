#include <stdio.h>

int main(void) {
	int num1 = 100;
	int num2 = 100;

	int* ptr = &num1;
	(*ptr) += 30;

	ptr = &num2;
	(*ptr) -= 30;

	printf("%d \n", num1);
	printf("%d \n", num2);

	
}