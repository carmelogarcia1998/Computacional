/*
Compara en términos de rapidez de convergencia, los métodos numéricos Bisección y Regula Falsi, para resolver la ecuación 
p(x) = x^10 −1 =0, con una tolerancia de 10−6.
*/


#include <stdio.h>
#include <math.h>

#define TOLERANCIA 1e-6

double f(double x) {
    return pow(x, 10) - 1;
}

void regula_fasi(double a, double b) {
    double x_r, x_r_ant;
    int count = 0;
    while (count < 100) {
        x_r = b - (f(b) * (b - a)) / (f(b) - f(a));
        if (fabs(f(x_r)) <= TOLERANCIA) {
            printf("Metodo regula falsi\n");
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
    
}

void biseccion(double a, double b) {
    double x_r;
    int count = 0;
    while (count < 100) {
        x_r = (a + b) / 2;
        if (fabs(f(x_r)) <= TOLERANCIA) {
            printf("Metodo biseccion\n");
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
        printf("El metodo de biseccion alcanzó el número máximo de iteraciones sin convergencia.\n");
    }
}


void main() {
    double a, b;
    printf("Ingrese el rango donde buscar las raices [a,b]: ");
    scanf("%lf %lf", &a, &b);
    regula_fasi(a, b);
    biseccion(a, b);
}