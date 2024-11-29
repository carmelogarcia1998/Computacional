/*
Cierto diodo se comporta como un condensador cuya capacidad C depende de la tensión V entre sus extremos, según la expresión:

C(V ) = C0 (1 + |V|/φ)^γ
,

donde C0 = 81 × 10−12 F, es la capacidad nominal del diodo, φ = 0,6V y γ = 0,44, son parámetros característicos del mismo.
a) Halle la carga Q del diodo, cuando la tensión entre sus extremos es de 1 V.
b) Represente gráficamente en xmgrace la carga Q en función de V para valores de la tensión entre 0 y 5 V.

Para analizar el comportamiento del diodo, se necesita conocer la tensión V en función de la carga Q, lo que lleva a la ecuación:

V =Q/C=Q/c0 (1 + |V|/φ)^γ,
C0V - Q(1 + |V |/φ)^γ = 0,

donde V es la incógnita.
c) Para un valor Q = 10−10 C, determina con precisión de millonésimas
el valor de V correspondiente, utilizando el método de Newton.
d) Resuelva el problema por el método de Punto Fijo.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TOL 1e-8

double C0 = 81e-12;
double phi = 0.6;
double gamma_val = 0.44;
double Q = 1e-10;

double C(double V){
    return C0/pow((1 + fabs(V)/phi),gamma_val);
}

double f(double V){
    return V*C0 -Q*pow((1 + fabs(V)/phi),gamma_val);
}
double df(double V){
    return C0 -Q*gamma_val*pow((1 + fabs(V)/phi),gamma_val-1)/phi;
}

double g(double V){
    return Q/C(V);
}

void newton(double x0){
    double x1;
    int count = 0;
    while (count < 100)
    {
        x1 = x0 - f(x0)/df(x0);
        if (fabs(x1 - x0) < TOL)
        {
            printf("La raiz es: %lf\n", x1);
            printf("Numero de pasos: %d\n", count);
            break;
        }
        x0 = x1;
        count++;
    }
}

int punto_fijo(double x_ant) {
    double x_i;
    int count = 0;
    while (count < 100) {
        x_i = g(x_ant);
        if (fabs(x_i - x_ant) <= TOL) {
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


void main(){
    printf("Parte a:\n");
    double Q_0 = C(1); 
    printf("La carga del diodo es: %e\n", Q_0);
    // Parte b
    printf("Parte b:\n");
    FILE *data;
    data = fopen("datos.dat","w");
    double x = 0;
    while (x <= 5)
    {
        double q = x*C(x);
        fprintf(data,"%lf %e\n",x,q);
        x += 0.01;
    }
    fclose(data);
    system("xmgrace datos.dat");
    printf("Grafico generado\n");
    //Parte c
    printf("Parte C\n");
    newton(2);
    //Parte d
    printf("Parte D\n");
    punto_fijo(3);
}
    