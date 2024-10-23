#include<stdio.h>
#include<stdlib.h>
#include<math.h>





void main(){
        //ouble x[n], y[n], z[n];
        int n=0;
        //printf("%d\n", RAND_MAX);
        for (int i=0; i < 1e10; i++) {
            int x=rand();
            //printf("%d %d \n", i, x);
            if(x == RAND_MAX) {n+=1; printf("%d\n", n);};
        }
        printf("%d\n", n);
}
