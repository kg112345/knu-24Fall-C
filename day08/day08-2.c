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

void movePointer(int arr[SIZE][SIZE]) {
    int x = 0; 
    int y = 0;
    int current;

    
    while (x < 10) {
        current = arr[x][y];

        printf("현재 위치: (%d, %d), 배열의 값: %d\n", x, y, current);

        y += current;

        if (y >= SIZE) {
            x += y / SIZE;
            y = y % SIZE;  
        }
		
    }
	x -= current / SIZE;
	y -= current % SIZE;

	if (y < 0) {
		x += ((y % 10 != 0) ? y / SIZE -1 : y / SIZE); //어려움
		y = 10 + y;
	}
	printf("더 이상 이동하지 못함\n");
	printf("종료 위치: (%d, %d), 배열의 값: %d", x, y, current);
}

int main(void) {
	int arr[SIZE][SIZE];

	srand(time(NULL));

	fillRandom(arr);
	printArray(arr);
	movePointer(arr);

	
}