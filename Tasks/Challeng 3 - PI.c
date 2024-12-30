#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double arctan(double x, int terms) {
    double sum = 0.0;
    double term = x;
    int sign = 1;

    for (int i = 1; i <= terms; i += 2) {
        sum += sign * term;
        term *= x * x;
        sign = -sign;
        term /= (i + 2);
    }
	
    return sum;
}

double computePi(int terms) {
    double arctan_1_5 = arctan(1.0 / 5.0, terms);
    double arctan_1_239 = arctan(1.0 / 239.0, terms);
    return 16.0 * arctan_1_5 - 4.0 * arctan_1_239;
}

void printPi(int N) {
    int terms = N * 100;
    double pi = computePi(terms);
    printf("Pi to %d decimal places: %.15f\n", N, pi);
}

int main(void) {
    int N;
    printf("Enter the number of decimal places of Pi to compute: ");
    scanf("%d", &N);
    printPi(N);
    return EXIT_SUCCESS;
}
