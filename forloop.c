#include <stdio.h>

int main(void)
{

    int a, b, s, d;
start:
    /*her starter vi med at bede brugeren om at instate 2 tal, og så smider dem ind i et par variabler*/
    printf("indtast 2 posetivt hel tal og del dem med et mellemrum:");
    scanf("%d %d", &a, &b);

    if (a == 0 || b == 0) /*her tjekker vi at bruger ikke har indtastede et 0, og hvis de har starter vi forfra*/
    {
        printf("\n 0 er ikke et posetivt hel tal \n");
        goto start;
    }
    /*her ser vi om a er støre en b eller omvent, og sætter den mindste som s hvilket er variablen til mindste værdi*/
    else if (a >= b)
    {
        s = b;
    }
    else if(a < b)
    {
        s = a;
    }

    /*her har vi en for løkke som tager det mindste og tæller ned af for at finde den største fælles divisor af de to tal*/
    for (int i = s; i > 0; i--)
    {
        if (a%i == 0 && b%i == 0)
        {
            d = i;
            break;
        }
    }
    /* og her printer vi vores svar*/
    printf("\n den fælles divisor af to tal er %d", d);

    return 0;
}
