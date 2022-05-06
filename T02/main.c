#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double calcula(double x, double u, double o)
{
    return(1/(sqrt(2*M_PI*pow(o,2)))*pow(M_E, (-1/2)*pow((x-u)/o, 2)));
}

int main(void)
{
    double x;
    double u;
    double o;

    printf("Insira o valor de x: ");
    scanf("%lf",&x);
    printf("\nInsira o valor de u: ");
    scanf("%lf",&u);
    printf("\nInsira o valor de o: ");
    scanf("%lf",&o);

    printf("\nResultado: %.3lf",calcula(x,u,o));
    
}