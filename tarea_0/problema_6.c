/*
Problema 6:

Dados dos números enteros M (dividendo) y N (divisor), realizar un programa que calcule el cociente entero de ellos y el resto de la división.

* Ayuda: Sean los números M y N ambos enteros, un método para obtener el cociente y el resto de la división, es a través de restas
sucesivas; el método se basa en restar sucesivamente el divisor del dividendo, hasta obtener un resultado menor que el divisor,
éste resultado será el resto de la división y el número de restas efectuadas para obtenerlo será el cociente.

*/

#include <stdio.h>

int main(void){
    // Variables
    int M , N, cociente = 0, resto, M_aux;

    // Coleccción de datos
    printf("Introduzca el valor de M: ");
    scanf("%d", &M);
    printf("Introduzca el valor de N: ");
    scanf("%d", &N);


    // Calculo del cociente y el resto

    M_aux = M; // Le asignamos el valor de M a M_aux para nno modificar el valor de M cuando se hagan las restas.


    while (M_aux >= N){ 
        M_aux -= N; // Le restamos el divisor al dividendo hasta que el mismo sea igual o menor al divisor.
        cociente++; // Contamos las veces que se resta el divisor al dividendo.
    }
    resto =  M - cociente * N; // Calculamos el resto de la division restandole al dividendo el divisor tantas veces como el cosiente.


    // Imprimir el cociente y el resto
    printf("El cociente de la division es: %d\n", cociente);
    printf("El resto de la division es: %d\n", resto);

    return 0;
}