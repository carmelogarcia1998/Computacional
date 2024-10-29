/*
-----------------------------------------------------------------------------------------------------------------------------------------
Problema 1: 

La función coseno puede evaluarse por medio de la serie de Taylor:

\begin{equation}
\cos(x) = \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n)!}x^{2n}
\end{equation}

Escriba un programa para implementar esta expresión de modo que calcule e imprima los valores de cos(x), conforme se agregue cada término
de la serie hasta el orden n que se le pida al usuario. Para cada uno de los valores calculados, muestre el error porcentual respecto al 
valor verdadero de cos(x).
-------------------------------------------------------------------------------------------------------------------------------------------
*/


/*
-----------------------------------------------------------------------------------------------------------------------------------------
Este problema tiene un problema para n>16 ya que el factorial con n tan grande desborda el tipo de dato long long, por lo que se debe tener en cuenta.
-------------------------------------------------------------------------------------------------------------------------------------------
*/



#include <stdio.h>
#include <math.h>


// Creando las funciones que vamos a usar en el calculo del coseno por serie de Taylor. 
float potencia(float x, int n) {
    float pot = 1;
    for (int i = 0; i < n; i++) {
        pot *= x;
    }
    return pot;
}
// El factorial da un error cuando el n es muy grande, por eso se usa long long. Aunque el problema persiste para n>16.
long long factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) { // se calcula el facorial de n multimlicando los numeros desde 1 hasta n.
        fact *= i;
    }
    return fact;
}
//solo use math.h para la funcion coseno asi que use un pi aproximado. Pasando los grados a radianes.
float radianes(float x) {
    return x*3.14159265359/180;
}


int main(void) {
    // instanciando las variables que vamos a usar
    int n;
    float x, cos_aprox = 0, error;

    // Le pedimos al usuario que ingrese los valores de x y n
    printf("Introduzca el valor de x: ");
    scanf("%f", &x);

    printf("Introduzca el valor de n: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        // Instanciamos las variables locales que vamos a usar en el calculo del coseno y calculamos el coseno aproximado.
        float rad = radianes(x) , pot = potencia(rad, 2*i);
        int pm = potencia(-1, i);
        int fact = factorial(2*i);
        cos_aprox += (pm*pot)/fact;
        
    }
    // Imprimimos el coseno aproximado y el error porcentual.
    printf("el cos(%.2lf) = %.3lf\n", x, cos_aprox);
    error = fabs(cos(radianes(x)) - cos_aprox)/cos(radianes(x))*100;
    printf("El error porcentual es: %f %%\n", error);
    return 0;
}