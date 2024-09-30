#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    double x, y, pi;
    int count = 0, circle = 0;
    long long billion = 1000000000; // 10억
    int tenMillion = 10000000;  // 1천만
    double r = 1.0;
    
    srand(time(NULL));
    
    for (long long i = 1; i <= billion; i++) {
        x = (double)rand() / RAND_MAX;  
        y = (double)rand() / RAND_MAX;
        
        double sum = sqrt(pow(x, 2) + pow(y, 2));

        if (sum <= r) { // 부채꼴 안에 점이 존재하는  경우
            circle++;
        }
        
        if (i % tenMillion == 0) {
            pi = 4.0 * circle / i;
            int procedure = i / tenMillion;
            printf("%02d%% 진행, 원주율: %f \t", procedure, pi);
            

            for (int j = 0; j < procedure / 5; j++) {
                printf("O");
            }

            for (int j = procedure / 5; j < 20; j++) {
                printf("X");
            }
            printf("\n");
        }
    }

    printf("원주율: %f", pi);
}
