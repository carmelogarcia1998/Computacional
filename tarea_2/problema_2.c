/*
Hallar la menor raíz positiva con su error de la ecuación e−x2−cos(x) =0 con una tolerancia de 10−5, utilizando el método de Regula Falsi 
y muestre en pantalla el error cometido en cada iteración.
*/



#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(-x * x) - cos(x);
}

// Definir la tolerancia
double tolerancia(int n) {
    return 0.5 * pow(10, 2 - n);
}

void main() {
    double a, b, x_r, x_r_ant, error;
    int count = 0;
    printf("Ingrese el rango donde buscar las raices [a,b]: ");
    scanf("%lf %lf", &a, &b);
    while (count < 100) {
        x_r = b - (f(b) * (b - a)) / (f(b) - f(a));
        error = fabs((x_r - x_r_ant) / x_r);
        if (fabs(f(x_r)) <= tolerancia(7)) {
            printf("La raiz es: %lf\n", x_r);
            printf("Numero de pasos: %d\n", count);
            break;
        } else if (f(a) * f(x_r) < 0) {
            b = x_r;
        } else {
            a = x_r;
        }
        printf("Error: %lf\n", error);
        x_r_ant = x_r;
        count++;
    }
    }