#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int* num;
	char** name;
	int* score;

	printf("�� �Է�: ");
	scanf_s("%d", &n);

	num = (int*)malloc(n * sizeof(int));
	score = (int*)malloc(n * sizeof(int));
	name = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < n; i++) {
		printf("�й�: ");
		scanf_s("%d", &num[i]);

		printf("�̸�: ");
		scanf_s("%s", name[i], 100);

		printf("����: ");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("�й�: %d, �̸�: %s, ����: %d \n", num[i], name[i], score[i]);
	}

	free(num);
	free(score);
	free(name);
}