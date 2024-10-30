/*
-----------------------------------------------------------------------------------------------------------------------------------------
Problema 3: 

Dada una secuencia de N números aleatorios enteros y positivos entre Nmin y Nmax , realice un programa para determinar cuántos de ellos
son números primos, cuántos son compuestos y cuántas veces están repetidos en cada caso. Los resultados deben imprimirse en pantalla.
-------------------------------------------------------------------------------------------------------------------------------------------
*/



#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

// Definimos las variables globales y las variables contadoras de primos y compuestos
int N_max, N_min, N, primo=0, comp=0;

// Construimos una funcion que detenermina si un número es primo o no. 

/*
Esta funcion determina si un numero es primo o no usando el método de fuerza bruta.
*/
int es_primo(int n) {
    if (n <= 1) {
        return 0; // False
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0; // False
        }
    }
    return 1; // True
}


// Funcion principal
int main(){
    // Semilla para el generador de números aleatorios
    srand((long)time((__time_t *)(NULL)));
    // Pedimos al usuario que ingrese los valores de N_min, N_max y N
    printf("Indique el intervalo de numeros a generar [N_min, N_max]: ");
    scanf("%d %d", &N_min, &N_max);
    printf("Indique la cantida de numeros a generar: ");
    scanf("%d", &N);
    
    // Generamos los números aleatorios y determinamos si son primos o compuestos
    for (int i=0; i<N; i++){
        // Generamos un número aleatorio entre (0,1]
        double rnd = rand()/((double)RAND_MAX);
        //Lo convertimos al intervalo [N_min, N_max]
        rnd = N_min + (N_max - N_min)*rnd;
        // lo redondeamos porque necesitamos un entero para determinar si es primo o no
        rnd = round(rnd);
        //ponemos un if para determinar si es primo o compuesto
        if (es_primo(rnd)) {
            printf("es primo %d\n", (int)rnd);
            primo += 1;
        } else if (es_primo(rnd) == 0) {
            printf("es compuesto %d\n", (int)rnd);
            comp += 1;
        }
        
        
    }
    // Imprimimos cuantos primos y compuestos se han generado en nuestro intervalo
    printf("Primos: %d, compuestos: %d\n", primo, comp);




    
}