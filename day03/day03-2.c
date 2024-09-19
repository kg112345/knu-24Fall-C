#include <stdio.h>

int func(num) {
	int res;
	if (num == 0 || num == 1) {
		res = 1;
		return res;
	}
	
	res = num * func(num - 1);
	return res;
}

int main(void) {
	int num = 0;

	printf("ÀÔ·Â: ");
	scanf_s("%d", &num);

	int result = func(num);
	printf("result = %d \n", result);
}