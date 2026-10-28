#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "kp.h"

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double x = read_x();

    printf("Введите X: ");
    scanf("%lf", &x);

    double q = compute_q(x);
    printf("Q(X) = %.2f\n", q);

    int state = control(q);

    print_state(state);

    statistics(&q, 1);

    return 0;
}