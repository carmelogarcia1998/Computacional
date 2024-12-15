#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Definimos las constantes del problema
double R=2.1, C=1.1;


// I analitica
double alpha(){
    return 1/R*C -0.06*M_PI;
}
double I(double tau, double y_0) {
    return (alpha()*cos(2*tau) + 2*sin(2*tau))*exp(-0.06*M_PI*tau)/(pow(alpha(),2) - 4) - (0.06*M_PI*alpha()*sin(2*tau) - 0.06*M_PI*2*cos(2*tau))*exp(-0.06*M_PI*tau)/(pow(alpha(),2) + y_0 - alpha()/(pow(alpha(),2) - 2)) - 2*0.06*M_PI/ (pow(alpha(),2) + 4);
}

// Definición de la función di/dt
double f(double t, double i) {
    double numerator = exp(-0.06 * M_PI * t) * (2 * cos(2 * t ) - 0.06 * M_PI * sin(2 * t))/R;
    double denominator = 2.1;
    return (numerator - (i / R*C)) / denominator;
}

double f2(double t, double i) {
    return (alpha()*cos(2*t) + 2*sin(2*t) - i)/R*C;
}

// Implementación del método de Runge-Kutta de cuarto orden
void rungeKutta(double i0, double t0, double h, int n) {
    double i = i0;
    double t = t0;

    FILE *file = fopen("resultados_runge_kutta_problema4.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int j = 0; j < n; j++) {
        double k1 = h * f(t, i);
        double k2 = h * f(t + h / 2, i + k1 / 2);
        double k3 = h * f(t + h / 2, i + k2 / 2);
        double k4 = h * f(t + h, i + k3);

        i = i + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t = t + h;

        fprintf(file, "%f %f\n", t, i);
    }

    fclose(file);
}


int main() {
    // Condiciones iniciales y parámetros del problema
    double i0 = 1; // Posición inicial adimensionalizada
    double t0 = 0.0;   // Tiempo inicial adimensionalizado
    double h = 0.02;    // Paso de tiempo
    int n = 100;       // Número de pasos
    
    // Llamada a la función de Runge-Kutta
    rungeKutta(i0, t0, h, n);

    
}
