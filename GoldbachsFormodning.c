#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "Lib/isPrime.h"

int main ()
{

    int i, f, evennr, g, y = 1;
    int Primtal[200000];
    Primtal[0] = 0;

    for (i=1; i<=200000; i+=2)
    {
        if (is_prime(i))
        {
            Primtal[y] = i;
            y++;
        }
    }
    printf("%d \n", Primtal[10]);
    y = 1;
    for (evennr = 6; evennr <= 200000; evennr+=2)
    {
        while(Primtal[y] < evennr)
        {
            g = evennr - Primtal[y];
            if (is_prime(g))
            {
                printf("%d is works cause %d and %d is a uneven primes\n", evennr, Primtal[y], g);
            }
            y++;
        }
        y=1;

    }

    return 0;
}

