/*
1. Considere un conjunto de \( N \) partículas que reposan en las posiciones \(\vec{r}_n = x_n \hat{x} + y_n \hat{y}\), tal que:

\[
x_n = -2.7 x_{n-1} \ln(x_{n-1}), \quad n = 1, 2, \ldots, N - 1; \quad x_0 = 0.3333
\]

\[
y_n = 0.9 \sin(\pi y_{n-1}), \quad n = 1, 2, \ldots, N - 1; \quad y_0 = 0.7453
\]

La masa de la n-ésima partícula está dada por \( m_n = |x_n y_n|^{1.3} e^{-r_n / \sqrt{2}} \).

Para el caso \( N = 10^8 \), elabore un programa que evalúe para este sistema:

\begin{itemize}
    \item[a)] El área del mínimo rectángulo, cuyos lados son paralelos a los ejes \( x \) e \( y \), que encierran este conjunto de partículas.
    \item[b)] La masa total.
    \item[c)] El centro de masas.
    \item[d)] El momento de inercia alrededor del eje que descansa en el plano \( xy \), es paralelo a la recta \( y = x \) y pasa por el centro de masas.
\end{itemize}

*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Definimos las constantes que vamos a usar.
int N = 1e+8;
float x_0 = 0.3333, y_0 = 0.7453;
double x_n, y_n, m_n, r_n, x_ant, y_ant, m_t, x_cm=0, y_cm=0, r_cm[2], I=0, x_max, x_min, y_max, y_min, A;



void main(){
x_ant = x_0;
y_ant = y_0;
//Le sacamos los calculos necesarios a la primera particula
double r_0 = sqrt(x_0*x_0 + y_0*y_0); //Modulo del vector posicion
m_t = pow(fabs(x_0*y_0), 1.3)*exp(-r_0/sqrt(2)); // Masa de la particula 0
x_cm = x_0*m_t; // Aportacion de la particula 0 al centro de masas
y_cm = y_0*m_t; // Aportacion de la particula 0 al centro de masas
I = m_t*(x_0*x_0 + y_0*y_0); // Aportacion de la particula 0 al momento de inercia
// limpiamos la memoria del arreglo r_cm
for (int i=0; i<1; i++) r_cm[i] = 0;

for (int i=1; i<=N; i++){
    // componente del vector posicion en x
    x_n = -2.7*x_ant*log(x_ant);
    // componente del vector posicion en y
    y_n = 0.9*sin(M_PI *y_ant);
    //Modulo del vector posicion
    r_n = sqrt(x_n*x_n + y_n*y_n);
    // Calcular la masa
    m_n = pow(fabs(x_n*y_n), 1.3)*exp(-r_n/sqrt(2));
    m_t += m_n;

    //Calculo del centro de masas
    x_cm += x_n*m_n;
    y_cm += y_n*m_n;

    //Calcular el momento de inercia para un eje que pasa por el origen
    I += m_n*(x_n*x_n + y_n*y_n);

    //Calcular el area del rectangulo
    if (i == 1){
        x_max = x_n;
        x_min = x_n;
        y_max = y_n;
        y_min = y_n;
    }
    else{
        if (x_n > x_max) x_max = x_n;
        if (x_n < x_min) x_min = x_n;
        if (y_n > y_max) y_max = y_n;
        if (y_n < y_min) y_min = y_n;
    }

    A = (x_max - x_min)*(y_max - y_min);

     
    //Pasar a la siguiente particula
    x_ant = x_n;
    y_ant = y_n;

    }
    
    //Calculo del centro de masas
    r_cm[0] = x_cm/m_t;
    r_cm[1] = y_cm/m_t;

    // Calculo del momento de incercia del centro de masa que pasa por el centro de masa usando el teorema de Steiner.
    double Icm = I - m_t*(r_cm[0]*r_cm[0] + r_cm[1]*r_cm[1]);

    printf("La masa total del sistema es: %lf\n", m_t);
    printf("El centro de masas del sistema es r_cm = (%lf, %lf)\n", r_cm[0], r_cm[1]);
    printf("El momento de inercia del sistema es: %lf\n", Icm);
    printf("El area del rectangulo es: %lf\n", A);
    
    
    }