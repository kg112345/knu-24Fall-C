#include <stdio.h>

int main(void) {
	int num = 0;

	printf("�Ҽ� �Է�: ");
	scanf_s("%d", &num);

	for (int i = 2; i < num; i++) {
		if (num %= i) {
			printf("�Ҽ���");
		}
		else {
			printf("�Ҽ� �ƴ�");
		}
	}
}