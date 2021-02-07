#include <stdio.h>
#include <math.h>

int main(void){
    int x, y,
        r, a, b,
        r2, chk;
    printf("indtast radiusen af din cirkle:");
    scanf("%d", &r);
    printf("\n indtast cirkelens centrum også kendt som punkt (a,b) \n skriv det som enkle tal delt med et mellemrum:");
    scanf("%d %d", &a, &b);
    printf("\n indtast x, y værdien af dit punkt \n skriv det som enkle tal delt med et mellemrum:");
    scanf("%d %d", &x, &y);

    r2  = pow(r,2);
    printf("%d", r2);
    chk = pow((x - a),2) + pow((y - b),2);
    printf("\n (%d-%d)^2 + (%d-%d)^2 = %d", x, a, y, b, chk);
    printf("\n %s", chk <= r2 ? "punkte er inde i cirklen" : "punkte er ikke i cirklen");

    return 0;

}
