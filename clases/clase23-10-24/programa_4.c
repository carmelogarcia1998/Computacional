#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int i, k, ndiv, N;
double rMin, rMax, try;

FILE *fp;

void main(){
        double old;
        srand((long)time((__time_t *)(NULL)));

        printf("Indique el intervalo de numeros a generar [rMin, rMax]: ");
        scanf("%lf %lf", &rMin, &rMax);
        printf("Indique el nuemro de a generar N: ");
        scanf("%d", &N);
        printf("Indique el numero de divisiones: ");
        scanf("%d", &ndiv);

        int f[ndiv];
        for (int i=0; i<ndiv; i++) f[i] = 0;

        for (int i=0; i<N; i++){
            try = rand()/((double)RAND_MAX);
            try = rMin + (rMax - rMin)*try;
            k = (int) (ndiv*(try - rMin)/(rMax - rMin));
            f[k] += 1;
            //printf("Numero, indices, aparicion, probabilidad: %lf, %d, %d, %lf\n", try, k, f[k], (double)f[k]/(i+1));
        }  
        fp = fopen("histograma.dat", "w");

        for (k = 0; k < ndiv; k++)
        {
            try = k*(rMax - rMin)/ndiv + rMin;
            fprintf(fp, "%lf %lf\n", try, (double)f[k]/N);
        }
        





        fclose(fp);
}
