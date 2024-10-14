#include <stdio.h>
#include <time.h>

#define SIZE 10

void fillRandom(int arr[SIZE][SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % 20 + 1; // 1~20����
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

        printf("���� ��ġ: (%d, %d), �迭�� ��: %d\n", x, y, current);

        y += current;

        if (y >= SIZE) {
            x += y / SIZE;
            y = y % SIZE;  
        }
		
    }
	x -= current / SIZE;
	y -= current % SIZE;

	if (y < 0) {
		x += ((y % 10 != 0) ? y / SIZE -1 : y / SIZE); //�����
		y = 10 + y;
	}
	printf("�� �̻� �̵����� ����\n");
	printf("���� ��ġ: (%d, %d), �迭�� ��: %d", x, y, current);
}

int main(void) {
	int arr[SIZE][SIZE];

	srand(time(NULL));

	fillRandom(arr);
	printArray(arr);
	movePointer(arr);

	
}