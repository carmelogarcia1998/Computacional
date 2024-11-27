#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definir la función iterativa g(x)
double g(double x) {
    return cos(x)/(8-2*x);  // Ejemplo de una función que cumple g(x) = x
}

// Función f(x) para verificar el resultado (opcional)
double f(double x){
    return pow(x, 5) - 3;
}

// Definir la tolerancia
double tolerancia(int n) {
    return 0.5 * pow(10, 2 - n);
}

int main() {
    double x_ant, x_i;
    int count = 0;

    printf("Indique el punto de inicio: ");
    scanf("%lf", &x_ant);

    while (count < 100) {
        x_i = g(x_ant);
        if (fabs(x_i - x_ant) <= tolerancia(17)) {
            printf("La raiz es: %lf\n", x_i);
            printf("Numero de pasos: %d\n", count);
            break;
        } else {
            x_ant = x_i;
            count++;
        }
    }

    if (count == 100) {
        printf("Se alcanzó el número máximo de iteraciones sin convergencia.\n");
    }

    return 0;
}
