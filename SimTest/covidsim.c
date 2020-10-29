#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int x, y, t, a, b, i, srtx, srty, num1, num2, num3, num4, infct = 1, s, d;

    time_t tid;
    srand((unsigned) time(&tid));

    printf("indtast din maks værdier af simulationen, eks 5 7:");
    scanf(" %d %d", &y, &x);

    int array[y][x];

    printf("\nIndtast hvor mange iteration den skal løbe igennem: ");
    scanf(" %d", &t);

    for (i = 0; i < y; i++)
    {
        for (s = 0; s < x; s++){
            array[i][s] = 0;
        }

    }


    printf("\nindtast start punktet, dette skal være indenfor 0 - %d og 0 - %d:", x, y);
    scanf(" %d %d", &srtx, &srty);


    array[srtx][srty] = 1;

    for (i = 0; i < t; i++)
    {
        for (a = 0; a < y; a++)
        {
            for (b = 0; b < x; b++){

                    if (array[a][b]==1){

                    num1 = rand() % 100;
                    num2 = rand() % 100;
                    num3 = rand() % 100;
                    num4 = rand() % 100;

                    if (num1 <= 20)
                    {
                        array[a-1][b] = 2;
                    }
                    if (num2 <= 20)
                    {
                        array[a+1][b] = 2;
                    }
                    if (num3 <= 20)
                    {
                        array[a][b+1] = 2;
                    }
                    if (num4 <= 20)
                    {
                        array[a][b-1] = 2;
                    }
                    }
                }
            }



        for (s = 0; s < y; s++)
        {
            for(d =0; d < x; d++){
                if (array[d][s] == 2)
                {
                    array[d][s] = 1;
                    infct++;
                }
            }

        }

        printf("\nDer er %d som har fået corona efter %d iterationer\n", infct, i+1);
    }

        return 0;
    }
