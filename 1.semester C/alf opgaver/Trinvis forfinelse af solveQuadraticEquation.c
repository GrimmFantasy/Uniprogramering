#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Her opretter vi de forskellige funktioner som vi kommer til at bruge*/
double diskriminanten(double, double, double);
double matRod1(double, double, double);
double matRod2(double, double, double);
void SolveQuadraticEquation(double, double, double);

int main(void)
{
    double a, b, c;
    /*her opretter vi et punkt som vi kan gå tilbage til hvis vi har brug for det*/
start:
    /* her bedes vores bruger indtaste de forskellige værdier af deres andengradslinje*/
    printf("indtast din a værdi: ");
    scanf("%lf", &a);
    printf("\nindtast din b værdi: ");
    scanf("%lf", &b);
    printf("\nindtast din c værdi: ");
    scanf("%lf", &c);

    /*Eftersom a ikke må være 0 i en andengradslining, tjekker vi det her før vi går vidre */
    if (a == 0)
    {
        /* hvis a er 0, gives der en bedsked at det må den ikke være,
        og her efter bruger vi goto til at komme tilbage til den linje hvor vi havde skrevet start på
        */
        printf("\na må ikke være 0");
        goto start;
    }
    else
    {
        /*hvis alt så stemmer overens så går vi ned til vores funktion som regner alt matematiken ud*/
        SolveQuadraticEquation(a,b,c);
    }


    return 0;
}
void SolveQuadraticEquation(double a, double b, double c)
{

    double d, root1, root2;
    /* her finder vi førest ud af hvad om dikriminanten er*/
    d = diskriminanten(a, b, c);
    printf("\ndiskriminanten er %lf\n", d);
    /*hvis den er under 0 ved vi at der ikke er nogen rodder til den,
    og dette vil så blive sagt til brugen*/
    if (d < 0)
    {
        printf("Intet at finde her, din rod er i et andet slot\n");
    }
    /*hvis den er lig 0 så ved vi der kun er en rod*/
    else if (d == 0)
    {
        /*her kalder man så funktion til at regner roden ud og så printer vi svaret til  brugen*/
        root1 = matRod1(a,b, d);
        printf("Der er en rod som er %f\n", root1);
    }
    /*ellers ved vi der er to løsninger*/
    else
    {
         /*her kalder man så funktion til at regner roderne ud og så printer vi svaret til  brugen*/
        root1 = matRod1(a,b, d);
        root2 = matRod2(a,b, d);
        printf("Der er to rod som er %f og %f\n", root1, root2);
    }


}
double diskriminanten(double a, double b, double c){
    return ((b)*(b)) - 4 *(a)*(c);
}
double matRod1(double a, double b, double d){
    return(-(b) + sqrt(d)) / 2*(a);
}
double matRod2(double a, double b, double d){
    return(-(b) - sqrt(d)) / 2*(a);
}
