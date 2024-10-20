/*
-----------------------------------------------------------------------------------------------------------------------------------------
Problema 8

Se tienen tres variables A, B y C. Escribir un programa para intercambiar sus valores del modo siguiente:
B toma el valor de A,
C toma el valor de B,
A toma el valor de C.
¡No está permitido utilizar variables auxiliares para resolver este problema!, deben utilizar sumas y restas sucesivas. El programa debe mostrar
en pantalla los valores de A, B y C, antes y después del intercambio
-------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>


int main(void){

    int A, B, C;
    printf("Ingrese el valor de A, B y C (Ejm: 2,4,6): ");
    scanf("%d,%d,%d", &A, &B, &C);

    printf("Valores iniciales: A = %d, B = %d, C = %d \n", A, B, C);

    /*
    -----------------------------------------------------------------------------------------------------------------------------------------
    Partimos de que A va a ser igual que la suma de todas las variables incluyendose a ella misma. 
    Como B va a tomar el valor de A, entonces B va a ser igual a A menos B menos C. A partird de este punto B ya tiene el valor de A.

    C va a tomar el valor de B, entonces C va a ser igual a A menos B menos C. Como B tiene el valor de A entonces esa operacion sera igual el valor de B. 
    A partir de este punto C ya tiene el valor de B.

    A va a tomar el valor de C, entonces A va a ser igual a A menos B menos C. 
    Como C tiene el valor de B y B tiene el valor de A entonces esa operacion sera igual al valor de C. 
    A partir de este punto A ya tiene el valor de C.


    De esta forma se intercambian los valores de las variables A, B y C sin utilizar variables auxiliares.
    -------------------------------------------------------------------------------------------------------------------------------------------
    */

    A = A + B + C;

    B = A - B - C; // B toma el valor de A

    C = A - B - C; // C toma el valor de B
    
    A = A - B - C; // A toma el valor de C

    printf("Valores finales: A = %d, B = %d, C = %d\n", A, B, C);
    
    
    
    
    return 0;
    }