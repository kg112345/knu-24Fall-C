//���ǹ� �ǽ�

#include <stdio.h>

int main(void) {
	printf("���ϴ� ����� �Է��ϼ���.\n1.���ϱ� 2.���� 3.���ϱ� 4.������");
	float num1 = 0;
	float num2 = 0;
	float func = 0;
	float result = 0;

	printf("���: ");
	scanf_s("%f", &func);

	printf("���� 1:");
	scanf_s("%f", &num1);

	printf("���� 2:");
	scanf_s("%f", &num2);
	
	if (func == 1) {
		result = num1 + num2;
		printf("%f + %f = %f", num1, num2, result);
	}
	else if (func == 2) {
		result = num1 - num2;
		printf("%f - %f = %f", num1, num2, result);
	}
	else if (func == 3) {
		result = num1 * num2;
		printf("%f * %f = %f", num1, num2, result);
	}
	else if (func == 4) {
		result = num1 / num2;
		printf("%f / %f = %f", num1, num2, result);
	}
	else {
		printf("�߸� �Է���");
	}
}