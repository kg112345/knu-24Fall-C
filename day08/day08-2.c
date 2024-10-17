#include <stdio.h>
#include <time.h>

#define SIZE 10

void fillRandom(int arr[SIZE][SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % 20 + 1; // 1~20범위
		}
	}
}

void printArray(int arr[SIZE][SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}

void movePointer(void* arr) {
	int x = 0;
	int y = 0;
	
	while (1) {
		int endX = x;
		int endY = y;
		int value = *((int*)arr + y + 10 * x);
		printf("현재 위치: (%d, %d), 배열의 값: %d\n", x, y, value);

		y += value % 10;
		if (y >= SIZE) {
			y %= SIZE;
			x++;
		}
		x += value / 10;
		
		if (x > 9) {
			printf("종료 위치: (%d, %d), 배열의 값: %d", endX, endY, value);
			return;
		}
	}

}

int main(void) {
	int array[SIZE][SIZE];

	srand(time(NULL));

	fillRandom(array);
	printArray(array);
	movePointer(array);

}
