#include <stdio.h>
#include <math.h>

double f(int n) {
    double h, x, intgr = 0;
    double a = 0;
    double b = 1.6;
    h = (b - a) / n;
    for (x = a; x <= 1.6; x += h)
    {
        double func;
        if (x >= 0 && x <= 0.6)
            func = (1 / (1 + (25 * x * x)));
        else
            func = (x + (2 * x * x * x * x) * sin(x * x));
        intgr += func;
    }
    intgr *= h;
    return intgr;
}

int main() {
    double e;
    printf(" vvedite toshnost -> ");
    scanf_s("%lf", &e);
    int n = 1;
    double intgr1 = f(n);
    double intgr2 = f(n * 2);
    n = 2 * n;
    while ((fabs(intgr2 - intgr1) / 3) >= e) {
        n *= 2;
        intgr1 = intgr2;
        intgr2 = f(n * 2);
    }
    printf("intgr1 = %lf\n", intgr1);
    printf("intgr2 = %lf\n", intgr2);
    printf("n = %i\n", n);
    return 0;
}
