#include <stdio.h>
#include <math.h>


double f(double xk_1) {
	return pow(xk_1, 2) + 1;
}

int main() {
	
	double a, b, n;

	printf("입력 (a, b, n):");
	scanf_s("%lf %lf %lf", &a, &b, &n);
	
	for (long i = 1; i <= pow(2, n); i *= 2) {
		
		double dx = (b - a) / i;
		double sum = 0.0;
		
		for (long k = 1; k <= i; k++) {
			double xk_1 = a + dx * (k - 1);
			double result = f(xk_1) * dx;
			sum += result;
		}

		printf("n: %ld, sum: %lf\n", i, sum);
	}

	return 0;
}
