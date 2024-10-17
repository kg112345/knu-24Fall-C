#include <stdio.h>
#include <string.h>

int isAlphabet(char *str) {
    for (int i = 0; i < strlen(str)-1; i++) { // 문자열타입은 마지막에 공백이 오기땜에 -1 해줌
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char string[100]; 

    printf("입력: ");
    fgets(string, sizeof(string), stdin);
 

    int n = strlen(string); //문자열 길이
    

    if (isAlphabet(string)) {
        for (int i = 0; i < n / 2 ; i++) {  // 대칭으로 교환하면 되므로 n/2번만 하면 됨
            char temp =string[n - i - 1];
            string[n - i - 1] = string[i];
            string[i] = temp;
        }

        printf("뒤집힌 문자열: %s\n", string);
    }
    else {
        printf("범위가 아님");
    }
}
