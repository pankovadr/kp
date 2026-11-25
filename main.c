#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "kp.h"

int main(void) {
    setlocale(LC_ALL, "RUS");
    double x;
    double q;
    int state;
    char filename[100];

    setlocale(LC_ALL, "");

    printf("Введите имя файла с данными: ");
    scanf("%99s", filename);

    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return 1;
    }

    printf("\n%-10s | %-10s | %-10s\n", "X, °C", "Q(X)", "Состояние");
    printf("------------------------------------------\n");

    int count = 0;
    while (read_x(f, &x)) {
        count++;

        if (x < X_MIN || x > X_MAX) {
            printf("%-10.2f | %-10s | ОШИБКА (вне диапазона)\n", x, "-");
            continue;
        }

        q = compute_q(x);
        state = control(q);

        printf("%-10.2f | %-10.2f | %s\n",
            x, q, (state == STATE_ALARM) ? "ТРЕВОГА" : "НОРМА");
    }

    if (count == 0) {
        printf("Файл пуст или содержит некорректные данные.\n");
    }

    fclose(f);
    printf("\nОбработка завершена. Всего записей: %d\n", count);
    return 0;
}
