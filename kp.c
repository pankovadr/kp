#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <math.h>
#include "kp.h"

int read_x(double *x)
{
    return scanf("%lf", x) == 1;
}

double compute_q(double x)
{
    if (x < X_BOUND_1)
    {
        return Q_FIRST_FACTOR * sqrt(fabs(x - X_BOUND_1))
               + Q_FIRST_OFFSET;
    }
    else if (x <= X_BOUND_2)
    {
        return Q_SECOND_FACTOR * (x - X_CENTER)
               + Q_SECOND_OFFSET;
    }
    else
    {
        return Q_THIRD_FACTOR * (x - X_BOUND_2)
               * (x - X_BOUND_2) + Q_THIRD_OFFSET;
    }
}

int control(double q)
{
    if (fabs(q - Q_NOMINAL) > Q_DEVIATION_LIMIT)
    {
        return STATE_ALARM;
    }

    return STATE_NORMAL;
}

void statistics(void)
{
}
