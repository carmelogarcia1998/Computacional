/*
Dada la ecuación no lineal:

8x − cos(x) − 2x^2 = 0.

a) Haga una representación gráfica con xmgrace, para averiguar el número de soluciones (raíces) y aplique el método incremental para obtener 
una estimación inicial de las mismas.

b) Resuelva la ecuación utilizando los métodos Newton y secante, con una tolerancia de 10−5.

c) Transforme la ecuación en una de la forma x = g(x), para que la solución converja con un número de iteraciones similar al obtenido con
el método de Newton. Aplique para esto, el método de Punto Fijo.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TOL 1e-5

int n_root = 0;

double* R = NULL; // Inicializar el puntero a NULL 

double f(double x){
    return 8*x - cos(x) - 2*pow(x,2);
}
// Definir las funciones g(x) posibles para el método de punto fijo
double g(double x){
    return (cos(x) + 2*pow(x,2))/8;
}
double g2(double x){
    return - cos(x) / (2 * x - 8);
}

double df(double x){
    return 8 + sin(x) - 4*x;
}

// Definir la tolerancia
double tolerancia(int n) {
    return 0.5 * pow(10, 2 - n);
}

int punto_fijo(double x_ant) {
    double x_i;
    int count = 0;


    while (count < 100) {
        x_i = g(x_ant);
        if (fabs(x_i - x_ant) <= TOL) {
            printf("La raiz es: %lf\n", x_i);
            printf("Numero de pasos: %d\n", count);
            break;
        } else {
            x_ant = x_i;
            count++;
        }
    }

    if (count == 100) {
        printf("Se alcanzó el número máximo de iteraciones sin convergencia.\n");
    }

    return 0;
}


// Definir la función para el método incremental
void incremental_search(double xl, double xu, double dx) {
    int i, ndiv;
    double x, testf, testdf;    
    ndiv = (int)((xu - xl) / dx);
    for (i = 0; i <= ndiv; i++) {
        x = xl + i * dx;
        // Se mejoro la pregunta para el cambio, ya que antes era f(x) * f(x + dx) y fallaba
        testf = f(x + 0.5 * dx) * f(x - 0.5 * dx); // pregunta con diferencias centradas si hay cambio de signo
        testdf = df(x + 0.5 * dx) * df(x - 0.5 * dx); // pregunta con diferencias centradas si hay cambio de signo
        if (testf < 0 || (fabs(f(x)) < TOL && testdf < 0)) {
            n_root++;
            R = realloc(R, n_root * sizeof(double)); // Redimensionar el array dinámicamente
            if (R == NULL) {
                printf("Error al asignar memoria\n");
                exit(1); // Terminar si hay un error de asignación de memoria
            }
            R[n_root - 1] = x; // Almacenar la raíz encontrada
        }
    }
    printf("Raices metodo incremental:\n");
    for (i = 0; i < n_root; i++) {
        printf("R[%d] = %f\n", i, R[i]);
    }
}
// Definir el método de Newton
void newton(double x0){
    double x1;
    int count = 0;
    while (count < 100)
    {
        x1 = x0 - f(x0)/df(x0);
        if (fabs(x1 - x0) < TOL)
        {
            printf("La raiz es: %lf\n", x1);
            printf("Numero de pasos: %d\n", count);
            break;
        }
        x0 = x1;
        count++;
    }
}
// Definir el método de la secante
void secante(double x0, double x1){
    double x2;
    int count = 0;
    while (count < 100)
    {
        x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0)); //Formula del metodo de la secante
        if (fabs(x2 - x1) < TOL)
        {
            printf("La raiz es: %lf\n", x2);
            printf("Numero de pasos: %d\n", count);
            break;
        }
        x0 = x1;
        x1 = x2;
        count++;
    }
    
}

void main(){
    // Parte a
    FILE *data;//creamos un archivo para guardar los datos
    data = fopen("datos.dat","w");//abrimos el archivo en modo escritura
    double x = -2;
    while (x < 6.5)//calculamos los valores de f(x) para x entre -10 y 10
    {
        fprintf(data,"%lf %lf\n",x,f(x));
        x += 0.01;
    }
    fclose(data);//cerramos el archivo
    system("xmgrace datos.dat");//imprime el grafico en pantalla
    incremental_search(-10, 10, 0.1);//buscamos las raices con el metodo incremental
    printf("Raices encontradas:%d \n", n_root);//imprimimos el numero de raices encontradas
    // Parte b
    printf("Metodo de Newton\n");
    for (int i = 0; i < n_root; i++)
    {
        newton(R[i]);
    }
    printf("Metodo de la secante\n");
    for (int i = 0; i < n_root; i++)
    {
        secante(R[i] + 0.5, R[i] - 0.5);
    }
    // Parte c
    printf("Metodo Punto fijo\n");
    for (int i = 0; i < n_root; i++)
    {
        punto_fijo(R[i]);
    }
    // Liberar la memoria al final
    free(R);
    n_root = 0;//reiniciamos el contador de raices
}