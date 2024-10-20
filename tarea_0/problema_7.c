/*
-----------------------------------------------------------------------------------------------------------------------------------------
Problema 7

El antiguo método de dividir y promediar, para obtener el valor aproximado de la raíz cuadrada de cualquier número positivo a, se formula
a través de la siguiente recurrencia:

r_n = r_(n-1)/2 + a/(2*r_(n-1))

Implemente un programa bien estructurado y claro en Lenguaje C, basado en este método, para hallar la raíz de un número positivo a.
Imprima en un archivo el valor estimado para la raíz y el error porcentual cometido en cada iteración, para esto, use el valor obtenido en
cada iteración y el valor arrojado por la función en Lenguaje C, sqrt(), que le proporciona la raíz cuadrada de un número positivo

Ayuda: Debe iterar la ecuación 1, hasta que la raíz obtenida rn, satisfaga el error porcentual deseado, el cual se le pedirá al usuario. 
Comience las iteraciones tomando r0 = a/2.

-------------------------------------------------------------------------------------------------------------------------------------------
*/


#include  <stdio.h>
#include <math.h>

int main(void) {
	//Declaracion Variables
	int a, n;
	float r_n, r_ant, porcentaje_error, error;
	// Colección de datos
	printf("Indique el numero que desea obtener la raiz: ");
	scanf("%d", &a);
	printf("Indique el error porcentual deseado: ");
	scanf("%f", &porcentaje_error);
	// Le indicamos que r_0 = a/2
	r_ant = a / 2.0;
	// 
	for (int i = 1; i <= n; i++) {
		//Calculamos la raiz cuadrada con la recurrencia dada y al final de cada iteracion cambiamos el valor de r_anterior por el de r_n.
		//asi con cada iteracion r_n se va hacercando a la raiz cuadrada de a.
		r_n = r_ant / 2.0 + a / (2*r_ant);
		r_ant = r_n;
		//Calculamos el error porcentual con respecto al valor de la raiz cuadrada dada por la funcion sqrt().
		error =  fabs((r_n - sqrt(a)) / sqrt(a)) * 100;
		//Cuando el % de error sea igual o menor al error esperado el bucle se detiene.
		if (error <= porcentaje_error) {
			break;
		}
	}
	// Al detenerese el bulce se imprime el valor de la raiz cuadrada y el error porcentual obtenido bajo el metodo de recurrencia.
	printf("la raiz de %d es %f \n", a, r_n);
	printf("El error es %f %%\n", error);


	return 0;
}
