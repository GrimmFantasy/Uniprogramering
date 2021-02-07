#include <stdio.h>

int main (void){
int n, m, side1, side2, hypo, b;

l6:
printf("Indtast to posetive variabler, dele dem op med et mellemrum:");
scanf(" %d", &n, &m);

if (m < n)
    {
    printf("Det første tal skal være mindre end det andet du indtsater\n");
    goto l6;
    }
else
    {
side1 = (m^2)-(n^2);
side2 = 2*m*n;
hypo  = (m^2)+(n^2);
printf("%d^2 - %d^2 = %d\n  %d\n %d\n", m, n, side1, side2, hypo);


    }


return 0;

}
