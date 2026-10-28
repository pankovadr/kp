#ifndef KP_H
#define KP_H
double read_x(void);
double compute_q(double x);
int control(double q);
void print_state(int state);
void statistics(const double* q, int n);

#endif#pragma once
