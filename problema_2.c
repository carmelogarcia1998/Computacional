/*
-----------------------------------------------------------------------------------------------------------------------------------------
Problema 2: 

Elabore un programa que le pida al usuario tres números enteros positivos, determinar si la suma de cualquier par de ellos es igual al tercer
número. Si se cumple esta condición, escribir en pantalla los números que se sumaron, el valor de su suma y el valor del número restante con
el que se comparó. Si la condición no se cumple, preguntarle al usuario si desea continuar, y pedirle nuevamente tres números 
-------------------------------------------------------------------------------------------------------------------------------------------
*/


#include <stdio.h>


int main(void) {
    // Declaramos las variables que vamos a usar
    int num1, num2, num3;
    char continuar;
    // Se crea un bucle infinito 
    while (1) {
    printf("Ingrese tres numeros enteros positivos separados por coma: "); // Se pide que ingrese los numeros y el formato que debe colocar los numeros
    scanf("%d, %d, %d", &num1, &num2, &num3); 
    if (num1 + num2 == num3) {
        printf("La suma de los dos primeros numeros es igual al tercer numero\n");
        printf("%d + %d = %d\n", num1, num2, num3);
        break;
    }
    else {
        printf("La suma de los dos primeros numeros no es igual al tercer numero\n");
        printf("Desea probar otra vez? (s-n): ");
        scanf(" %c", &continuar);
        if (continuar != 's' && continuar != 'S') {
            break;
    }
    }
    
    }
    return 0;
}
