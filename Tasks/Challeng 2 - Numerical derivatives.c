#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double F(double x) {
    return sin(x);
}

double numericalDerivative(double (*F)(double), double x, double h) {
    return (F(x + h) - F(x - h)) / (2 * h);
}

void testNumericalDerivative(void) {
    double x = M_PI / 4;
    double h = 1e-5;

    double computedDerivative = numericalDerivative(F, x, h);

    double actualDerivative = cos(x);

    printf("F(x) = sin(x) at x = pi/4\n");
    printf("Numerical derivative: %.10f\n", computedDerivative);
    printf("Analytical derivative: %.10f\n", actualDerivative);
    printf("Error: %.10e\n", fabs(computedDerivative - actualDerivative));
}

int main(void) {
    testNumericalDerivative();
    return EXIT_SUCCESS;
}
