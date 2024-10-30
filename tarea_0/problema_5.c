/*
Una manera de generar números aleatorios uniformemente distribuidos en el intervalo [0, 1), es a través del Método congruencial lineal. Dado
un valor inicial (semilla) entero, I0 , una secuencia de enteros; I, puede generarse utilizando la siguiente recurrencia:

\begin{equation}

I_n = (a I_{n−1} + c) mod M

\end{equation}

donde a, c y M , son constantes enteras. La distribución de números reales se calcula hallando el número aleatorio rn = In /M . Implemente
un programa, que genere números aleatorios rn , utilizando este método. Haga un histograma y grafíquelo para verificar que la distribución de los
números generados es uniforme. Utilice los valores a = 75 , c = 0, M = 231 − 1 e I0 = 1.


*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Instanciamos el archivo de salida que vamos a usar para guardar los datos que se van a graficar
FILE *fp;


// Definimos las constantes que vamos a usar para el método congruencial lineal, las constantes son las que pide el problema que sean usadas
int a=75, c=0, M=231-1, I_0=1, ndiv, k;
double r_n, r_n10; // r_n10 es r_n multiplicado por 10

void main() {

// Definimos la semilla inicial y el número de divisiones que vamos a hacer en el histograma
int I_ant = I_0, N;
// Pedimos al usuario que ingrese el número de números aleatorios a generar y el número de divisiones
printf("Indique el nuemro de a generar N: ");
scanf("%d", &N);
printf("Indique el numero de divisiones: ");
scanf("%d", &ndiv);


// Definimos un arreglo de tamaño ndiv para guardar la frecuencia de cada intervalo
int f[ndiv];
for (int i=0; i<ndiv; i++) f[i] = 0;


// Abrimos el archivo de salida
fp = fopen("histograma.dat", "w");

// Generamos los números aleatorios y llenamos el histograma. Recordemos que los numeros aleatorios van del [0,1)
for (int i=0; i<=N; i++){
    
    int I_n = (a*I_ant + c) % M;
    r_n = (double)I_n/M;
    I_ant = I_n;
    // Multiplicamos por 10 para que los números estén en el intervalo [0,10) y asi poder asignarlos a un intervalo del histograma 
    r_n10 = r_n*10;

    // Asignamos el número aleatorio a un intervalo del histograma
    k = (int) (ndiv*(r_n10)/(N));
    // Aumentamos la frecuencia del intervalo k
    f[k] += 1;
    // Guardamos los datos en el archivo de salida
    fprintf(fp, "%lf %lf\n", r_n,(double)f[k]/N);
    
    }

    // Cerramos el archivo de salida
    fclose(fp);






    }