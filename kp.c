#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "kp.h" 
double read_x(void) {
    double x;
    printf("Введите значение X: ");
    scanf("%lf", &x);
    return x;
}

double compute_q(double x) {
    if (x < 20) {
        return 6 * sqrt(fabs(x - 20)) + 5;
    }
    else if (x <= 32) {
        return 2 * (x - 26) + 50;
    }
    else {
        return 0.25 * (x - 32) * (x - 32) + 55;
    }
}
int control(double q) {
    double deviation = fabs(q - 50.00);
    if (deviation > 10) {
        if (q > 50) return 2;
        else return 1;
    }
    return 0;
}
void print_state(int state) {
    if (state == 2) {
        printf("Состояние: АВАРИЯ (Превышение)\n");
    }
    else if (state == 1) {
        printf("Состояние: АВАРИЯ (Понижение)\n");
    }
    else {
        printf("Состояние: Норма\n");
    }
}

void statistics(const double* q, int n) {
    (void)q;
    (void)n;
}

int main(void) {
 
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double x = read_x();       
    double q = compute_q(x);      
    printf("Q(X) = %.2f\n", q);

    int state = control(q);        
    print_state(state);            
    double arr[] = { q };
    statistics(arr, 1);

    return 0;
}