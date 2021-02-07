#include <stdio.h>
#include <stdlib.h>

int main(void){

int a, b, m, n, k, output;
start:
printf("indtast et posetive hel tal:");
scanf("%d", &a);
printf("\n Indtast et til posetivt hel tal:");
scanf("%d", &b);
printf("\n Indtast et til pesetivt hel tal som er støre end 1:");
scanf("%d", &k);

if ( k <= 1){
    printf("k skal være støre end 1 \n");
    goto start;
}
else if ( a >= b ){
    n = a;
    m = b;
}
else if ( b > a ){
    n = b;
    m = a;
}
    output = 0;
    for (int i = m; i <= n ; i++){
        if (i % k == 0){
            output = output + i;
        }
    }
    printf("%d", output);

    return 0;
}
