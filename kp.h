#ifndef KP_H
#define KP_H

// Допустимый диапазон температуры
#define X_MIN 10.0
#define X_MAX 50.0

// Границы кусочной функции
#define X_BOUND_1 20.0
#define X_BOUND_2 32.0
#define X_CENTER 26.0

// Коэффициенты первой ветви
#define Q_FIRST_FACTOR 6.0
#define Q_FIRST_OFFSET 5.0

// Коэффициенты второй ветви
#define Q_SECOND_FACTOR 2.0
#define Q_SECOND_OFFSET 50.0

// Коэффициенты третьей ветви
#define Q_THIRD_FACTOR 0.25
#define Q_THIRD_OFFSET 55.0

// Параметры оперативного контроля
#define Q_NOMINAL 50.0
#define Q_DEVIATION_LIMIT 10.0

// Состояния технологического процесса
#define STATE_NORMAL 0
#define STATE_ALARM 1

// Прототипы функций
int read_x(double *x);
double compute_q(double x);
int control(double q);
void statistics(void);

#endif
