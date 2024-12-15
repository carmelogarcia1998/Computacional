/*
### 2. Una partícula de masa \( m \) que se desplaza por un fluido está sujeta a una fuerza viscosa de magnitud \( F_v \), que a su vez, es función de la rapidez \( v \). La relación entre la magnitud de la fuerza viscosa \( F_v \), la rapidez \( v \) y el tiempo \( t \), viene dada por la ecuación:



\[ t = \int_{v(t_0)}^{v(t)} \frac{m}{F_v(u)} \, du. \]



Supongamos que \( F_v(v) = -v \sqrt{v} \) para determinado fluido, donde \( F_v \) se reporta en N y \( v \) se reporta en m/s. Si \( m = 10 \, \text{kg} \) y si \( v(0) = 10 \, \text{m/s} \), aproxime el tiempo que la partícula tarda en reducir su velocidad a \( v = 5 \, \text{m/s} \), utilizando para ello:

a) El método de Simpson 1/3 con \( 10n \), \( n = 1, 2, \ldots \) subintervalos o paneles, hasta que la diferencia entre dos aproximaciones consecutivas sea menor que \( 10^{-6} \). ¿Cuántos subintervalos son necesarios para alcanzar esa estimación del error?

b) El método de Montecarlo con \( 2^k \) puntos, donde \( k = 10, 11, \ldots \) Represente los resultados obtenidos en una gráfica de ejes \( (k, t) \).

c) Compara los resultados obtenidos en los apartados anteriores con la solución exacta.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Definimos la funcion f(v) = 10/(v*sqrt(v))
double f(double v){
    return 10.0/(v*sqrt(v));
}
// Definimos la funcion N_(a,b) que nos da el numero de subintervalos necesarios para alcanzar una estimacion del error menor a 1e-6
long N_(double xMin, double xMax){
    double delta_x = 1;
    long N = 1;
    while (delta_x > 1e-6){
        delta_x = fabs(xMax - xMin)/N;
        N++;
    }
    return N-1;
}
// Definimos la funcion que ejecuta el metodo Simpson 1/3 que nos da la integral de la funcion f(v) en el intervalo [a,b] con N subintervalos
double simpson1_3(double xMin, double xMax, long N){
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

double montecarlo(double xMin, double xMax,double yMin, double yMax, long N){
        int c=0;
        double  x, y, try, tryx, A;

        for (int i=0; i<N; i++){

            tryx = rand()/((double)RAND_MAX);
            x = xMin + (xMax - xMin)*tryx;

            try = rand()/((double)RAND_MAX);
            y = yMin + (yMax - yMin)*try;

            
            if (y <= f(x)) c++;
        
        }  

        A = (double)c / N * (xMax - xMin) * (yMax - yMin);
        return A;

}
// definimos una funcion de error porcentual
double error(double I_exacto, double I_aprox){
    return fabs(fabs(I_exacto - I_aprox)/I_exacto)*100;
}
void main(){
        double xi=10, xf=5;
        //parte a
        long N = N_(xi, xf);
        printf("El valor de N es: %ld\n", N);
        printf("El valor de la integral por simpson 1/3 es: %lf s\n", simpson1_3(xi, xf, N));
        printf("El valor de la integral por montecarlo es: %lf s\n", montecarlo(xi, xf, 0, 2, N));
        //parte b
        FILE *data;
        data = fopen("datosmontecarlo.dat","w");
        for (int k=10; k<20; k++){
            int Z = pow(2,k);
            fprintf(data,"%d %lf\n",k,montecarlo(xi, xf, 0, 2, Z));
        }
        fclose(data);
        system("xmgrace datosmontecarlo.dat");

        //parte c
        double I_exacto=-2.61971659;
        printf("El valor exacto de la integral es: %lf s\n", I_exacto);
        printf("El error de la integral por simpson 1/3 es: %e %%\n", error(I_exacto, simpson1_3(xi, xf, N)));
        printf("El error de la integral por montecarlo es: %e %%\n", error(I_exacto, montecarlo(xi, xf, 0, 2, N)));
}


    
