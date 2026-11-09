#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Константы для повышения читаемости кода
#define EPSILON 1e-9 // Порог для сравнения с нулем
#define LOG_BASE_2 0.6931471805599453 // ln(2)
#define COS_HALF 0.8775825618903728 // cos(0.5)

double y_function(double x) {
    if (x <= 0 || fabs(x) < EPSILON) {
        printf("Ошибка! Аргумент должен быть положительным.\n");
        return NAN;
    }

    double numerator = pow(0.8, sqrt(x) + 1) - x;
    double denominator = pow(x, 3) + x + 4;

    return numerator / denominator;
}

double v_function(double x) {
    if (fabs(x) < EPSILON) { 
        printf("Ошибка! Аргумент не может быть равен 0 во втором случае.\n");
        return NAN;
    }

    if (x > 0) {
        return exp(sin(x));
    }
    else if (x >= -2) { 

        return COS_HALF;
    }
    else {
        
        return log(fabs(x)) / LOG_BASE_2 / (pow(sin(x), 3) - 3);
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int choice;
    double a, b, step;

    // Интерфейс А: Выбор функции
    printf("Выберите функцию:\n"
        "[1] Монотонная функция Y(x)\n"
        "[2] Кусочная функция V(x)\n");
    scanf("%d", &choice);

    while (choice != 1 && choice != 2) {
        printf("Неверный выбор. Повторите ввод: ");
        scanf("%d", &choice);
    }

    // Интерфейс Б: Задание шага и интервала табуляции
    printf("\nЗадайте границы интервала и шаг табуляции:\n");
    printf("Левая граница (a): ");
    scanf("%lf", &a);
    printf("Правая граница (b): ");
    scanf("%lf", &b);
    printf("Шаг (h): ");
    scanf("%lf", &step);


    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }

    printf("\nТаблица вычислений\n--------------------\n");
    printf("| %10s | %10s |\n", "X", "Значение");
    printf("--------------------\n");

    for (double x = a; x <= b; x += step) {
        double result;

        switch (choice) {
        case 1:
            result = y_function(x);
            break;
        case 2:
            result = v_function(x);
            break;
        }

        if (!isnan(result)) {
            printf("| %10.4f | %10.4f |\n", x, result);
        }
    }

    printf("--------------------\n");

    return 0;
}