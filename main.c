#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <locale.h>
#include "kp.h"

int main(void)
{
    double x;
    double q;
    int state;
    setlocale(LC_ALL, "");
    printf("Курсовой проект. Вариант 8.\n");
    printf("Мониторинг температуры охлаждающей жидкости реактора.\n");
    printf("Программа преобразует температуру X в показатель Q\n");
    printf("и контролирует состояние технологического процесса.\n\n");
    printf("Введите температуру X (10..50 °C): ");

    if (!read_x(&x))
    {
        printf("Ошибка: необходимо ввести число.\n");
        return 1;
    }

    if (x < X_MIN || x > X_MAX)
    {
        printf("Ошибка: температура выходит за допустимые пределы.\n");
        return 1;
    }
    q = compute_q(x);
    state = control(q);
    printf("\nX = %.2f °C\n", x);
    printf("Q(X) = %.2f\n", q);
    if (state == STATE_ALARM)
    {
        printf("Состояние: ТРЕВОГА\n");
    }
    else
    {
        printf("Состояние: НОРМА\n");
    }
    statistics();
    return 0;
}
