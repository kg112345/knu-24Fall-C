#include <stdio.h>

struct Vector {
	int x;
	int y;
	int z;
};

struct Vector add(struct Vector v1, struct Vector v2) {
	struct Vector resultVector;

	resultVector.x = v1.x + v2.x;
	resultVector.y = v1.y + v2.y;
	resultVector.z = v1.z + v2.z;
	
	return resultVector;
}

struct Vector sub(struct Vector v1, struct Vector v2) {
	struct Vector resultVector;

	resultVector.x = v1.x - v2.x;
	resultVector.y = v1.y - v2.y;
	resultVector.z = v1.z - v2.z;

	return resultVector;
}

int inner(struct Vector v1, struct Vector v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct Vector outter(struct Vector v1, struct Vector v2) {
	struct Vector resultVector;

	resultVector.x = v1.y * v2.z - v1.z * v2.y;
	resultVector.y = v1.z * v2.x - v1.x * v2.z;
	resultVector.z = v1.x * v2.y - v1.y * v2.x;

	return resultVector;
}

int main(void) {
	struct Vector v1;
	struct Vector v2;
	v1.x = 1, v1.y = 3, v1.z = 4;
	v2.x = 2, v2.y = 4, v2.z = 1;

	printf("첫 번째 벡터: 1, 3, 4\n");
	printf("첫 번째 벡터: 2, 4, 1\n");

	printf("1. 합\n2. 차\n3. 내적\n4. 외적\n5. 종료\n");

	while (1) {
		int choice;

		printf("명령 입력: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("벡터의 합(x,y,z): %d, %d, %d\n\n", add(v1, v2).x, add(v1, v2).y, add(v1, v2).z);
			break;
		case 2:
			printf("벡터의 차(x,y,z): %d, %d, %d\n\n", sub(v1, v2).x, sub(v1, v2).y, sub(v1, v2).z);
			break;
		case 3:
			printf("벡터의 내적(x,y,z): %d\n\n", inner(v1, v2));
			break;
		case 4:
			printf("벡터의 외적(x,y,z): %d, %d, %d\n\n", outter(v1, v2).x, outter(v1, v2).y, outter(v1, v2).z);
			break;
		case 5:
			return 0;
		}

	}
}
