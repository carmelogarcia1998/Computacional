#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// Definimos las constantes del problema
double etha = 0.391, rho=11.35, R=0.02, k=5000, L=0.10;
//Definimos las conversiones de las variables adimensionales a las variables fisicas
double y(double y){
    return y*L;
}
double ya(double y){
    return y/L;
}

double v(double va){
    return va*L;
}
double t(double tao){
    return tao* pow((4*M_PI*rho*R*R*R)/(3*k), 0.5);
}

double alpha(){
    return 0.5*pow(3, 1.5) * etha / pow(M_PI*rho*R*k, 0.5);
}
//funciones parte de la ecuacion diferencial del sistema, adaptadas para ser usadas con el metodo de velocity verlet
double f1(double tau, double z1, double z2) {
    return z2;
}

double f2(double tau, double z1, double z2, double alpha) {
    return -2 * alpha * z2 - z1;
}
double aceleration(double z1, double z2, double alpha) {
    return -2 * alpha * z2 - z1;
}

//solucion analitica

double r1(double alpha){
    return -alpha + pow(-pow(alpha,2) + 4, 0.5);
}

double r2(double alpha){
    return -alpha/2 - pow(pow(alpha,2)/4 + 1, 0.5);
}

long double y_analitica(double tau, double r1, double y_0){
    return y_0*exp(-alpha()*tau)*cos(tau*r1/2);
}

// funcion energia y trabajo

double masa(){
    return 1.33333*M_PI*R*R*R*rho;
}

double energia_total(double y, double v){
    return 0.5*masa()*pow(v,2) + 0.5*k*pow(y,2);
}
double trabajo(double y, double y_ant){
    return - 0.5*k*(pow(y,2));
}

// Implementación del método de Velocity Verlet
void velocityVerlet(double y1_0, double y2_0, double tau0, double h, int n, double alpha) {
    double y1 = y1_0;
    double y2 = y2_0;
    double tau = tau0;

    FILE *file = fopen("resultados_velocity_verlet_agua.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    double y1_ant=0;

    for (int i = 0; i < n; i++) {
        // Guardar los resultados actuales
        fprintf(file, "%f %f %f %f %e\n", t(tau), y(y1), v(y2), energia_total(y1, y2), trabajo(y1, y1_ant));

        // Calcular la aceleración actual
        double a_current = aceleration(y1, y2, alpha);

        // Actualizar la posición
        y1 = y1 + y2 * h + 0.5 * a_current * h * h;

        // Calcular la nueva aceleración
        double a_new = aceleration(y1, y2, alpha);

        // Actualizar la velocidad
        y2 = y2 + 0.5 * (a_current + a_new) * h;

        // Actualizar el tiempo
        tau = tau + h;

        // guardar informacion para el trabajo
        y1_ant = y1;
        
    }
    printf("%f\n", masa());
    fclose(file);
}

// Implementación del método de Runge-Kutta de cuarto orden
void rungeKutta(double y1_0, double y2_0, double tau0, double h, int n, double alpha) {
    double y1 = y1_0;
    double y2 = y2_0;
    double tau = tau0;

    FILE *file = fopen("resultados_rungekutta_ad.txt", "w");
    FILE *file2 = fopen("resultados_rungekutta.txt", "w");
    if (file == NULL || file2 == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        double k1_1 = h * f1(tau, y1, y2);
        double k1_2 = h * f2(tau, y1, y2, alpha);

        double k2_1 = h * f1(tau + h / 2, y1 + k1_1 / 2, y2 + k1_2 / 2);
        double k2_2 = h * f2(tau + h / 2, y1 + k1_1 / 2, y2 + k1_2 / 2, alpha);

        double k3_1 = h * f1(tau + h / 2, y1 + k2_1 / 2, y2 + k2_2 / 2);
        double k3_2 = h * f2(tau + h / 2, y1 + k2_1 / 2, y2 + k2_2 / 2, alpha);

        double k4_1 = h * f1(tau + h, y1 + k3_1, y2 + k3_2);
        double k4_2 = h * f2(tau + h, y1 + k3_1, y2 + k3_2, alpha);

        y1 = y1 + (k1_1 + 2 * k2_1 + 2 * k3_1 + k4_1) / 6;
        y2 = y2 + (k1_2 + 2 * k2_2 + 2 * k3_2 + k4_2) / 6;
        tau = tau + h;

        fprintf(file, "%f %f %f\n", tau, y1, y2);
        fprintf(file2, "%f %f %f\n", t(tau), y(y1), v(y2));
    }

    fclose(file);
    fclose(file2);
}

int main() {
    // Condiciones iniciales y parámetros del problema
    double y1_0 = ya(0.03); // Posición inicial adimensionalizada
    double y2_0 = 0.0; // Velocidad inicial adimensionalizada
    double tau0 = 0.0;   // Tiempo inicial adimensionalizado
    double h = 0.01;    // Paso de tiempo
    int n = 2000;       // Número de pasos
    
    // Llamada a la función de Runge-Kutta
    velocityVerlet(y1_0, y2_0, tau0, h, n, alpha());
    rungeKutta(y1_0, y2_0, tau0, h, n, alpha());
    //solucion analitica:
    FILE *file = fopen("resultados_analiticos.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%f %f\n", t(tau0 + i*h), y(y_analitica(tau0 + i*h, r1(alpha()), y1_0)));
    }
    fclose(file);
    printf("%f\n", alpha());
 
}
