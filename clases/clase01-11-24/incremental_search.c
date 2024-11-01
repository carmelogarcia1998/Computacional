#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>

#define sqr(x) ((x)*(x))
#define sqr3(x) ((x)*(x)*(x))
#define epsilon DBL_EPSILON
int i, n_root=0, ndiv;
double x, dx, x_old, xl, xu, testf, testdf;
//const double epsilon = 1e-6; // Tolerancia para considerar una raíz

double f(double x);
double df(double x); // Derivada de la función

void main(){
    printf("Limite inferior xl=  ");
    scanf("%lf", &xl);
    printf("Limite superior xu=  ");
    scanf("%lf", &xu);
    printf("Incremento diferencial dx=  ");
    scanf("%lf", &dx);

    ndiv = (int) ((xu-xl)/dx);
    //printf("Numero de divisiones: %d\n", ndiv);

   for (i = 0; i <= ndiv; i++) {
        x = xl + i * dx;
        // Se mejoro la pregunta para el cambio, ya que antes era f(x) * f(x + dx) y fallaba
        testf = f(x + 0.5*dx) * f(x - 0.5*dx); // pregunta con diferencias centradas si hay cambio de signo
        testdf = df(x + 0.5*dx) * df(x - 0.5*dx); // pregunta con diferencias centradas si hay cambio de signo

        // printf("x = %lf, f(x) = %lf, f(x+dx) = %lf\n", x, f(x), f(x+dx));

        if (testf < 0 || (fabs(f(x)) < epsilon && testdf < 0)) {
            n_root++;
            printf("Raiz %d = %f\n", n_root, x);
        }
    }

    
}

double f(double x){
    double y;

    y = sqr3(x) - sqr(x); // coloco la funcion que deseo estudiar
    return y;
}


double df(double x){
    double dy;

    dy = 3*sqr(x) - 2*x; // coloco la funcion que deseo estudiar
    return dy;
}