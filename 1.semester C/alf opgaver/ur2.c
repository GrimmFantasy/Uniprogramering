#include <stdio.h>

int main(void)
{
    //opretter de variabler som jeg skal bruge i mit program
    int sek, min, timer, temp;
    //beder bruger om at instaste antalet af sekunder
    printf("Indtast din tid i sekunder:");
    scanf("%d", &sek);
    //Regner at matte matikken ud s� vi har det i timer, minnutter og sekunder frem for bare sekunder
    temp = sek;
    min = sek / 60,
    timer = min / 60;
    sek = sek % 60;
    min = min % 60;

    //printer den indtastede v�rdi og hvad den svare til i timer minnutter ovs
    printf("%d sekunder svare til ", temp);
    //her bruger jeg betingede operator, s� der ikke skrives noget hvis variablerne har en v�rdi p� 0 eller under
    timer > 0 ? printf("%d timer, ", timer): printf("");
    min > 0 ? printf("%d minutter og ", min): printf("");
    sek > 0 ? printf("%d sekunder", sek): printf("");

    return 0;
}
