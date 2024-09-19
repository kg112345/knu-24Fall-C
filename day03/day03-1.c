#include <stdio.h>

int main(void) {
	int num = 0;

	printf("소수 입력: ");
	scanf_s("%d", &num);

	for (int i = 2; i < num; i++) {
		if (num %= i) {
			printf("소수임");
		}
		else {
			printf("소수 아님");
		}
	}
}