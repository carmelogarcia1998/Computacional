#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int c=0, r, b, h;
double xMin, xMax, yMin, yMax, try, tryx, x, y, Arec, Asen;

long double N;

void main(){

        // Declarar una variable para almacenar el tiempo de inicio y fin
        clock_t start, end; double cpu_time_used; 
        // Obtener el tiempo de inicio 
        start = clock();

        srand((long)time((__time_t *)(NULL)));

        xMin=0, xMax=M_PI, yMin=0, yMax=1;
        N = 1e9;


        for (int i=0; i<N; i++){

            tryx = rand()/((double)RAND_MAX);
            x = xMin + (xMax - xMin)*tryx;

            try = rand()/((double)RAND_MAX);
            y = yMin + (yMax - yMin)*try;

            //rn = sqrt(x*x + y*y);
            
            if (y <= sin(x)) c++;
        }  

        Asen = (double)(c/N) * M_PI;
        printf("El valor la integral del seno en [0,pi] es: %lf\n", Asen);

         // Obtener el tiempo de fin 
         end = clock();
         // Calcular el tiempo de CPU usado
         cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
         printf("El tiempo de ejecución es: %f segundos\n", cpu_time_used);
}