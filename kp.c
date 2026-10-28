#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "kp.h"

double read_x(void) {
    return 0.0;
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
        return (q > 50) ? 2 : 1;
    }
    return 0;
}


void print_state(int state) {

}

void statistics(const double* q, int n) {

}