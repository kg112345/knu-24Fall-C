#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int* num;
	char** name;
	int* score;

	printf("수 입력: ");
	scanf_s("%d", &n);

	num = (int*)malloc(n * sizeof(int));
	score = (int*)malloc(n * sizeof(int));
	name = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < n; i++) {
		printf("학번: ");
		scanf_s("%d", &num[i]);

		printf("이름: ");
		scanf_s("%s", name[i], 100);

		printf("점수: ");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("학번: %d, 이름: %s, 점수: %d \n", num[i], name[i], score[i]);
	}

	free(num);
	free(score);
	free(name);
}