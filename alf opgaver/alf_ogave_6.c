#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_OF_N 128

double g(double x);
double h(double x);
double trap(double a, double b, double n, double f(double x));

int main()
{

    double a1 = 0,
           b1 = 3.14159,
           a2 = -2,
           b2 = 2,
           n = 2, u;

    /*Her regner vi trapeziod reglen for g(x)*/
    printf("\ntrapeziod rule for g(x) = x^2*sin(x)  (a=0, b= 3.14159)");
    while (n <= MAX_OF_N)
    {
        u = trap(a1, b1, n, g);
        printf("\nT = %lf, when n =%lf", u, n);

        /*hvergang vi har lavet en udregning skal n fordoubles
        indtil kravet for while loop ikke l�nger g�lder*/
        n = n*2;

    }

    /*jeg s�tter n til at v�re 2 da deter dens start v�rdi for hver af udregningerne*/
    n=2;

    /*Her regner vi trapeziod reglen for h(x)*/
    printf("\n\ntrapeziod rule for h(x) = sqrt(4-x^2)   (a=-2, b= 2)");
    while (n<=MAX_OF_N)
    {
        u = trap(a2, b2, n, h);
        printf("\nT = %lf, when n =%lf", u, n);
        n = n*2;
    }


    return 0;
}

/*I denne funktion har vi g(x), det f�r at vi nemmer kan bruge matemtikken i den n�r den skal laves*/
double g(double x)
{

    return pow(x, 2)*sin(x);
}

/*basicly det sammen som f�r bare for h(x)*/
double h(double x)
{

    return sqrt(4-pow(x, 2));
}

/*her regner vi trapziod reglen, n�r vi kalder den skal vi give den 4 parameter,
en a, b og n v�rdi og s� hvilken funktion vi vil lave den for*/
double trap(double a, double b, double n, double f(double x))
{
    double h, T, sum = a, i=1;

    h = (b-a)/n;

    /*her regner vi summation for trapzioden ud
    jeg fandt frem til at man kunne g�re det p� den her m�de her
    https://www.programiz.com/c-programming/examples/sum-natural-numbers*/

    while (i<=n-1)
    {
        sum = sum * h;
        i++;
    }

    T = (h/2)*(f(a)+f(b)+(2 * sum));

    return T;
}
