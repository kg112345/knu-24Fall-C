#include <stdio.h>

int func(int num) {
	for (int i = 2; i < num; i++) { // num = num % i
		if (num %= i) {
			printf("소수임");
		}
		else {
			printf("소수 아님");
		}
	}

	return 1;
}

int main(void) {
	int num = 0;

	printf("입력: ");
	scanf_s("%d", &num);

	func(num);
}