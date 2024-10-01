#include <stdio.h>

int main() {
    float num1, num2, resultado;

    // Pedir los dos números al usuario
    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);
    
    // Multiplicar los números
    resultado = num1 * num2;

    // Mostrar el resultado
    printf("El resultado de la multiplicación es: %.2f\n", resultado);
    
    // Indicar que se compiló correctamente
    printf("Compilación exitosa.\n");

    return 0;
}
