#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "RUS");
    double x, q, deviation;
    printf("Введите значение X: ");
    scanf("%lf", &x);
    if (x < 20) {
        q = 6 * sqrt(fabs(x - 20)) + 5;
    }
    else if (x <= 32) {
        q = 2 * (x - 26) + 50;
    }
    else {
        q = 0.25 * (x - 32) * (x - 32) + 55;
    }

    printf("Q(X) = %.2f\n", q);
    deviation = fabs(q - 50.00);
    if (deviation > 10) {
        if (q > 50) {
            printf("Состояние: АВАРИЯ (Превышение)\n");
        }
        else {
            printf("Состояние: АВАРИЯ (Понижение)\n");
        }
    }
    else {
        printf("Состояние: Норма\n");
    }
    return 0;
}