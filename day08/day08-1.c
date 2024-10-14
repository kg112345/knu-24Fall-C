#include <stdio.h>
#include <string.h>

int isAlphabet(char *str) {
    for (int i = 0; i < strlen(str)-1; i++) { // ���ڿ�Ÿ���� �������� ������ ���ⶫ�� -1 ����
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char string[100]; 

    printf("�Է�: ");
    fgets(string, sizeof(string), stdin); // scanf_s�� ������ �������� �����⶧���� fgets �Լ��� ���ڿ��� �״�� �޾Ƶ���

    int n = strlen(string); //���ڿ� ����

    if (isAlphabet(string)) {
        for (int i = 0; i < n / 2; i++) {  // ��Ī���� ��ȯ�ϸ� �ǹǷ� n/2���� �ϸ� ��
            char temp = string[i];
            string[i] = string[n - i - 1];
            string[n - i - 1] = temp;
        }

        printf("������ ���ڿ�: %s\n", string);
    }
    else {
        printf("������ �ƴ�");
    }
}
