#include <stdio.h>

int func(int num) {
	for (int i = 2; i < num; i++) { // num = num % i
		if (num %= i) {
			printf("�Ҽ���");
		}
		else {
			printf("�Ҽ� �ƴ�");
		}
	}

	return 1;
}

int main(void) {
	int num = 0;

	printf("�Է�: ");
	scanf_s("%d", &num);

	func(num);
}