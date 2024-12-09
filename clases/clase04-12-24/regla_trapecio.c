#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


double f(double x){
    return x*x + cos(x) + exp(-x*x);
 }

int a,b;
long double N;
double xMin, xMax, x, try, x_0, x_N, delta_x, sum=0., I;



void main(){
        printf("Ingrese el rango de la funcion [a,b]: ");
        scanf("%lf %lf", &xMin, &xMax);
        N = 10000;

        // Creamos los numeros que pertencen al rango de la funcion
         delta_x = (xMax - xMin)/N;
         x_N = xMax;
         x_0 = xMin;
        for (int i=1; i<N; i++){
            x = xMin + i*delta_x;
            sum += f(x);
            
        }  
        I = (delta_x/2)*(f(x_0) + f(x_N) + 2.0*sum);
        printf("El valor de la integral es: %lf\n", I);
      
}