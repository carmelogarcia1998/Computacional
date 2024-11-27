/*
Utilice el método de bisección para aproximar la raíz quinta de 2 con tres cifras decimales exactas.
*/


#include <stdio.h>
#include <math.h>

// Definir la función f(x)
double f(double x) {
    return pow(x, 5) - 2;
}

// Definir la tolerancia
double tolerancia(int n) {
    return 0.5 * pow(10, 2 - n);
}

int main() {
    double a, b , x_r;
    int count = 0;
    printf("Ingrese el rango donde buscar las raices [a,b]: ");
    scanf("%lf %lf", &a, &b);
    while (count < 100) {
        x_r = (a + b) / 2;
        if (fabs(f(x_r)) <= tolerancia(3)) {
            printf("La raiz es: %lf\n", x_r);
            printf("Numero de pasos: %d\n", count);
            break;
        } else if (f(a) * f(x_r) < 0) {
            b = x_r;
        } else {
            a = x_r;
        }
        count++;
    }

    if (count == 100) {
        printf("Se alcanzó el número máximo de iteraciones sin convergencia.\n");
    }

    return 0;
}