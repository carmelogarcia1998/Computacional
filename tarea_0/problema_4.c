/*
-----------------------------------------------------------------------------------------------------------------------------------------
Problema 4 

Elaborar un programa que le pida a un usuario que introduzca un número entero positivo, se debe validar el número tal que tenga mínimo
dos dígitos y máximo 5 dígitos. Una vez validado, verificar si el número es Capicúa.
-------------------------------------------------------------------------------------------------------------------------------------------
*/



#include <stdio.h>
/*
*Explicacion de la funcion reverse:

Esta funcion toma un numero entero positivo, y lo invierte. Para ello, se crea una variable mun que se inicializa en 0. Luego, se entra en un bucle
mientras el numero sea mayor a 0. En cada iteracion, se toma el numero num y se le saca el modulo 10, que es la unidad del numero. Luego, se multiplica
mun por 10 que en la primera iteracion es cero y se le suma el modulo 10. Para terminar la primera iteracion se divide el numero num por 10 para que la
unidad este despues de una coma y como esta variable num es entera lo que esta despues de la coma no se toma en cuenta.

*/
int reverse(int num) {
    int mun = 0;
    while (num > 0) {
        mun = mun * 10 + num % 10;
        num /= 10;
    }
    return mun;
}

int main() {
    // Variables
    int num, mun;
    char continuar;

    
    while (1) {
        // pedir al usuario que introduzca un número entero positivo
        printf("Introduzca un número entero positivo: ");
        scanf("%d", &num);
        mun = reverse(num);
            if (num >= 10){
                if (num == mun) { // Verificar si el número es capicúa
                    printf("El número %d es capicúa\n", num);
                } else {
                    printf("El número %d no es capicúa\n", num);
                }
                break;
            }
            else if (num < 0){// Valida si es un numero positivo
                printf("No se permiten numeros negativos\n");
                printf("Desea probar otra vez? (s-n): ");
                scanf(" %c", &continuar);
                if (continuar != 's' && continuar != 'S') {
                     break;
                    }
            }
            else { // Valida si el numero tiene al menos dos digitos
                printf("El número debe tener al menos dos digitos\n");
                printf("Desea probar otra vez? (s-n): ");
                scanf(" %c", &continuar);
                if (continuar != 's' && continuar != 'S') {
                     break;
                    }
            }
    }

    return 0;
}