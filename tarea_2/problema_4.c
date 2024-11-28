/*
La corriente eléctrica en un circuito RLC, para determinados valores de la resistencia R, la inductancia L y la capacitancia C, viene dada
por la expresión:

i(t) = 10e−t/2 cos(3t).

Una serie de preguntas sobre el circuito nos obligan a resolver ecuacio-
nes no lineales. Veamos alguna de ellas.

a) ¿Para qué instantes de tiempo la intensidad de la corriente es nula?
b) ¿En qué instantes de tiempo la corriente es de 2 mA?
c) ¿En qué instantes de tiempo la intensidad de la corriente es máxima?
*/

#include<stdio.h>
#include<math.h>

double f(double x){
    double y;

    y = 10*exp(-x/2)*cos(3*x); // coloco la funcion que deseo estudiar
    return y;
}
double f1(double x){
    double y;

    y = 10*exp(-x/2)*cos(3*x)-2e-3; // coloco la funcion que deseo estudiar
    return y;
}

double df(double x){
    double dy;

    dy = -5*exp(-x/2)*cos(3*x) - 15*exp(-x/2)*sin(3*x); // coloco la funcion que deseo estudiar
    return dy;
}

// Definir el tipo de la función
typedef double (*func_ptr)(double);
// Definir la tolerancia
double tolerancia(int n) {
    return 0.5 * pow(10, 2 - n);
}


void regula_fasi(double a, double b, func_ptr f) {
    double x_r, x_r_ant;
    int count = 0;
    while (count < 100) {
        x_r = b - (f(b) * (b - a)) / (f(b) - f(a));
        if (fabs(f(x_r)) <= tolerancia(7)) {
            printf("t= %lf s\n", x_r);
            break;
        } else if (f(a) * f(x_r) < 0) {
            b = x_r;
        } else {
            a = x_r;
        }
        x_r_ant = x_r;
        count++;
    }
}




int main(){
    int a=0, b=0, c=0;
    printf("La intensidad de corriente se anula en los siguientes instantes:\n");
    while (a<14)
    {
        
        regula_fasi(a, a+1,f);
        a++;
        
    }
    printf("La intensidad de corriente es maxima en los siguientes instantes:\n");
    while (b<14)
    {
        
        regula_fasi(b, b+1,df);
        b++;
        
    }
    printf("La intensidad de corriente es de 2 mA en los siguientes instantes:\n");
    while (c<15)
    {
        
        regula_fasi(c, c+1,f1);
        c++;
        
    }
    
    
    
    return 0;
}