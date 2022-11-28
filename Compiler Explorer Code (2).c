#include <stdio.h>
#include <math.h>

double Sh(double x) {
    return (exp(x) - exp(-x)) / 2;
}

int Factorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    return num * Factorial(num - 1);
}

double PowerSeries(int x) {
    double res = 1;
    int n = 1;
    while ((1 - res / Sh(x) / 2) > 0.001) {
        res += pow(x, n) / Factorial(n);
        res -= pow(-x, n) / Factorial(n);
        ++n;
    }
    return res / 2;
}

int main() {
    int number;
    scanf("%d", &number);
    printf("%f", PowerSeries(number));
    return 0;
}
