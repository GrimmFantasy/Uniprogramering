#include <stdio.h>

#define PI 3.14159
#define MAX_I 1000
int main(void){
double x, y = -1.0;
int a = 3, b = 4, i;

i = a % b;
printf("a, %d\n", i);
/*i = (989 − MAX_I)/a;
printf("%d\n", i);*/
i = b % a;
printf("c, %d\n", i);
x = PI * y;
printf("d, %d\n", x);
/*i = a / −b;
printf("%d\n", i);*/
x = a / b;
printf("f, %d\n", x);
x = a % (a / b);
printf("g, %d\n", x);
/*i = b / 0;
printf("%d\n", i);*/
/*i = a % (990 − MAX_I);
printf("%d\n", i);*/
/*i = (MAX_I − 990) / a;
printf("%d\n", i);*/
x = a / y;
printf("k, %d\n", x);
i = PI * a;
printf("l, %d\n", i);
x = PI / y;
printf("m, %d\n", x);
x = b / a;
printf("n, %d\n", x);
/*i = (MAX_I − 990) % a;
printf("%d\n", i);*/
/*i = a % 0;
printf("%d\n", i);*/
/*i = a % (MAX_I − 990);
printf("%d\n", i);*/
x = (double) a / b;
printf("r, %d\n", x);

return 0;
}
