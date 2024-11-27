#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double f(double x){
    return pow(x, 5) - 2;
 }

double a, b, x_r;
int count = 0;

double tolerancia(int n){
    return 0.5*pow(10, 2-n);
}

void main(){

    printf("Ingrese el rango donde buscar las raices [a,b]: ");
    scanf("%lf %lf", &a, &b);


    while (fabs(a-b)*100 > tolerancia(7))
    {
        if (f(a)*f(b) < 0)
        {
            count++;
            x_r = (a+b)/2;
            if (f(a)*f(x_r) < 0)
            {
                b = x_r;
                if (fabs(a-b) * 100 < tolerancia(3))
                {
                    printf("numero de pasos: %d \n", count);
                    printf("La raiz es: %lf\n", x_r);
                    break;
                }
            }
            else
            {
                a = x_r;
                if (fabs(a-b) * 100 < tolerancia(3))
                {
                    printf("numero de pasos: %d \n", count);
                    printf("La raiz es: %lf\n", x_r);
                    break;
                }
            }
        }
        else if (f(a)*f(b) == 0)
        {
            if (f(a) == 0)
            {
                printf("numero de pasos: %d \n", count);
                printf("La raiz es: %lf\n", a);
            }
            else
            {
                printf("numero de pasos: %d \n", count);
                printf("La raiz es: %lf\n", b);
            }
            break;
        }
        else if (f(a)*f(b) > 0)
        {
            printf("No hay raices en el intervalo [%lf, %lf]\n", a, b);
            printf("Ingrese un nuevo rango donde buscar las raices [a,b]: ");
            scanf("%lf %lf", &a, &b);

        }
    }
    






}