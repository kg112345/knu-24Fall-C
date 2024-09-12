//조건문 실습

#include <stdio.h>

int main(void) {
	printf("원하는 기능을 입력하세요.\n1.더하기 2.빼기 3.곱하기 4.나누기");
	float num1 = 0;
	float num2 = 0;
	float func = 0;
	float result = 0;

	printf("기능: ");
	scanf_s("%f", &func);

	printf("숫자 1:");
	scanf_s("%f", &num1);

	printf("숫자 2:");
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
		printf("잘못 입력함");
	}
}