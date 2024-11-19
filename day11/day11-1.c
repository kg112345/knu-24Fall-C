#include <stdio.h>
#include <math.h>


int main(void) {
	double a, b, c;

	printf("입력: ");
	scanf_s("%lf %lf %lf", &a,&b,&c);

	
	double pan = pow(b, 2) - 4 * a * c;

	if (pan > 0) {
		double num1 = (-b + sqrt(pan)) / (2 * a);
		double num2 = (-b - sqrt(pan)) / (2 * a);
		printf("실근: %.2lf, %.2lf", num1, num2);
	}
	else if (pan == 0) {
		double num = -b / (2 * a);
		printf("중근: %.2lf", num);
	}
	else {
		printf("허근");
	}
}
