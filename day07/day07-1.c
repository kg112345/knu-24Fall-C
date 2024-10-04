#include <stdio.h>

int main(void) {
	int layer;

	printf("ÇÇ¶ó¹Ìµå Ãþ: ");
	scanf_s("%d", &layer);

	for (int i = 0; i < layer; i++) {
		for (int j = i; j < layer - 1 ; j++) {
			printf(" ");
		}

		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}

		printf("\n");
	}
}

// 1. 층(layer) - 1 만큼의 공간까지 공백 채우기 
// 2. 공백으로 채워야하는 공간은 밑에 층으로 갈수록 점점 적어짐 (j = i)
// 3. 홀수만큼만 별(*)을 채워나감
// ( 뒤에 공백은 신경쓰지 않아도 됨 )
