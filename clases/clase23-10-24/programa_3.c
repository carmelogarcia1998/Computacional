#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int i, j, k, n=0, N=20, try;
double rnd[20][2];



void main(){
        //srand((long)time((__time_t *)(NULL)));
        int n=0;
        try=2;
        for (int j=0; j<try; j++){
            srand(j+1);
            for (int i=0; i < N; i++) {
                rnd[i][j]= rand()/((double)RAND_MAX);
            }
        }
        
        for (int j=0; j<try; j++){
            printf("Secuencia %d\n", j);
            for (int i=0; i < N; i++) {
                printf("%lf \n", rnd[i][j]);
            }
            
        }
}
