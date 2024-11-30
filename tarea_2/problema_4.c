/*
La corriente eléctrica en un circuito RLC, para determinados valores de la resistencia R, la inductancia L y la capacitancia C, viene dada
por la expresión:

i(t) = 10e^{-t/2} \cos(3t).

Una serie de preguntas sobre el circuito nos obligan a resolver ecuaciones no lineales. Veamos alguna de ellas.

a) ¿Para qué instantes de tiempo la intensidad de la corriente es nula?
b) ¿En qué instantes de tiempo la corriente es de 2 mA?
c) ¿En qué instantes de tiempo la intensidad de la corriente es máxima?
*/

#include <stdio.h>
#include <math.h>

double f(double x) {
    return 10 * exp(-x / 2) * cos(3 * x); // Función que deseamos estudiar
}

double f1(double x) {
    return 10 * exp(-x / 2) * cos(3 * x) - 2e-3; // Función para 2 mA
}

double df(double x) {
    return -5 * exp(-x / 2) * cos(3 * x) - 15 * exp(-x / 2) * sin(3 * x); // Derivada de la función
}

// Definir el tipo de la función
typedef double (*func_ptr)(double);

// Definir la tolerancia
double tolerancia(int n) {
    return 0.5 * pow(10, 2 - n);
}

void regula_falsi(double a, double b, func_ptr f) {
    double x_r, x_r_ant;
    int count = 0;
    while (count < 100) {
        x_r = b - (f(b) * (b - a)) / (f(b) - f(a));
        if (fabs(f(x_r)) <= tolerancia(7)) {
            printf("t= %lf s\n", x_r);
            break;
        } else if (f(a) * f(x_r) < 0) {
            b = x_r;
        } else {
            a = x_r;
        }
        x_r_ant = x_r;
        count++;
    }
}

// Función para encontrar los puntos críticos usando el método de Regula Falsi
void encontrar_maximos(double a, double b, double paso) {
    double x, x_prev, df_val;
    int maximos_encontrados = 0;

    for (x = a; x <= b; x += paso) {
        df_val = df(x); // Verificar si la derivada cambia de signo
        if (x != a) {
            if (df(x_prev) > 0 && df_val < 0) {
                // Usar regula_falsi para encontrar el máximo local
                regula_falsi(x_prev, x, df);
                maximos_encontrados++;
            }
        }
        x_prev = x;
    }

    if (maximos_encontrados == 0) {
        printf("No se encontraron máximos locales en el intervalo [%lf, %lf].\n", a, b);
    }
}

int main() {
    int a = 0, b = 0, c = 0;
    double paso = 0.1; // Tamaño del paso para encontrar máximos

    printf("La intensidad de corriente se anula en los siguientes instantes:\n");
    while (a < 14) {
        regula_falsi(a, a + 1, f);
        a++;
    }

    printf("La intensidad de corriente es máxima en los siguientes instantes:\n");
    encontrar_maximos(0, 14, paso);

    printf("La intensidad de corriente es de 2 mA en los siguientes instantes:\n");
    while (c < 15) {
        regula_falsi(c, c + 1, f1);
        c++;
    }

    return 0;
}
