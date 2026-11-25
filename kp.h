#define X_MAX 50.0
#define X_BOUND_1 20.0
#define X_BOUND_2 32.0
#define X_CENTER 26.0
#define Q_FIRST_FACTOR 6.0
#define Q_FIRST_OFFSET 5.0
#define Q_SECOND_FACTOR 2.0
#define Q_SECOND_OFFSET 50.0
#define Q_THIRD_FACTOR 0.25
#define Q_THIRD_OFFSET 55.0
#define Q_NOMINAL 50.0
#define Q_DEVIATION_LIMIT 10.0
#define STATE_NORMAL 0
#define STATE_ALARM 1

int read_x(FILE* f, double* x);
double compute_q(double x);
int control(double q);
void statistics(void);

#endif
