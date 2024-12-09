
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
    return ((250*x) / (6 + x))*(exp(-x/10));
 }

long N_(double xMin, double xMax){
    double delta_x = 1;
    long N = 1;
    while (delta_x > 1e-8){
        delta_x = (xMax - xMin)/N;
        N++;
    }
    return N-1;
}



double trapecio(double xMin, double xMax, long N){
        double  x, x_0, x_N, delta_x, sum=0., I;
        // Creamos los numeros que pertencen al rango de la funcion
        
         delta_x = (xMax - xMin)/N;
         x_N = xMax;
         x_0 = xMin;
        for (long i=1; i<N; i++){
            x = xMin + i*delta_x;
            sum += f(x);
            
        }  
        I = (delta_x/2)*(f(x_0) + f(x_N) + 2.0*sum);
        return I;
      
}

double simpson(double xMin, double xMax, long N){
        double  x, x_0, x_N, delta_x, sump=0., sumi=0., I;
        // Creamos los numeros que pertencen al rango de la funcion
        
         delta_x = (xMax - xMin)/N;
         x_N = xMax;
         x_0 = xMin;
        for (long i=1; i<N; i++){
            x = xMin + i*delta_x;
            if (i%2 == 0)
                sump += f(x);
            else 
                sumi += f(x);   
        }  
        I = (delta_x/3)*(f(x_0) + f(x_N) + 4.0*sumi + 2.0*sump);
        return I;
}

void main(){
        double xMin, xMax;
        printf("Ingrese el rango de la funcion [a,b]: ");
        scanf("%lf %lf", &xMin, &xMax);
        long N = N_(xMin, xMax);
        printf("El valor de N es: %ld\n", N);
        printf("El valor de la integral por trapecio es: %lf\n", trapecio(xMin, xMax, N));
        printf("El valor de la integral por simpson es: %lf\n", simpson(xMin, xMax, N));
      
}