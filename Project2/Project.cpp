#include <stdio.h>
#include <math.h>
#include <locale.h>

double f(double x) {
    return x * x;
}

// ����� ����� ���������������
double left_rectangles(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i < n; i++) {
        double x_left = a + i * h;
        integral += f(x_left) * h;
    }

    return integral;
}

// ����� ������ ���������������
double right_rectangles(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 1; i <= n; i++) {
        double x_right = a + i * h;
        integral += f(x_right) * h;
    }

    return integral;
}

// ����� ������� ���������������
double middle_rectangles(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i < n; i++) {
        double x_middle = a + (i + 0.5) * h;
        integral += f(x_middle) * h;
    }

    return integral;
}

// ����� ��������
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i < n; i++) {
        double x_left = a + i * h;
        double x_right = a + (i + 1) * h;
        integral += (f(x_left) + f(x_right)) / 2 * h;
    }

    return integral;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a = 0.0;
    double b = 1.0;
    int n = 100000;

    double integral_left = left_rectangles(a, b, n);
    double integral_right = right_rectangles(a, b, n);
    double integral_middle = middle_rectangles(a, b, n);
    double integral_trapezoidal = trapezoidal(a, b, n);

    printf("����� ����� ���������������: %.14f\n", integral_left);
    printf("����� ������ ���������������: %.14f\n", integral_right);
    printf("����� ������� ���������������: %.14f\n", integral_middle);
    printf("����� ��������: %.14f\n", integral_trapezoidal);

    return 0;
}