/*
### 2. Una partícula de masa \( m \) que se desplaza por un fluido está sujeta a una fuerza viscosa de magnitud \( F_v \), que a su vez, es función de la rapidez \( v \). La relación entre la magnitud de la fuerza viscosa \( F_v \), la rapidez \( v \) y el tiempo \( t \), viene dada por la ecuación:



\[ t = \int_{v(t_0)}^{v(t)} \frac{m}{F_v(u)} \, du. \]



Supongamos que \( F_v(v) = -v \sqrt{v} \) para determinado fluido, donde \( F_v \) se reporta en N y \( v \) se reporta en m/s. Si \( m = 10 \, \text{kg} \) y si \( v(0) = 10 \, \text{m/s} \), aproxime el tiempo que la partícula tarda en reducir su velocidad a \( v = 5 \, \text{m/s} \), utilizando para ello:

a) El método de Simpson 1/3 con \( 10n \), \( n = 1, 2, \ldots \) subintervalos o paneles, hasta que la diferencia entre dos aproximaciones consecutivas sea menor que \( 10^{-6} \). ¿Cuántos subintervalos son necesarios para alcanzar esa estimación del error?

b) El método de Montecarlo con \( 2^k \) puntos, donde \( k = 10, 11, \ldots \) Represente los resultados obtenidos en una gráfica de ejes \( (k, t) \).

c) Compara los resultados obtenidos en los apartados anteriores con la solución exacta.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>