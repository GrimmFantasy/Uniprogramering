#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{   
    
    int size;
    int totalLenght;
    int i, j, k;

    totalLenght = strlen(argv[1]);

    for (i = 0; i < totalLenght; i++)
    {
        
        if (isdigit(argv[1][i]))
        {
            size = i;
            printf("Warehouse:  ");
            for(j = 0; j < size; j++)
            {
                printf("%c", argv[1][j]);
            }
            printf("\n");
            break;
        }
        
    }

    for(i = size; i < totalLenght; i++)
    {
        if (isalpha(argv[1][i]))
        {
            size = i;
            printf("Product:    ");
            for(k = j; k < size; k++)
            {
                printf("%c", argv[1][k]);
            }
            printf("\n");
            break;
        }
    }

     for(i = size; i < totalLenght; i++)
    {
        if (argv[1][i] == argv[1][totalLenght-1])
        {
            size = i;
            printf("Qualifiers: ");
            for(j = k; j < size; j++)
            {
                printf("%c", argv[1][j]);
            }
            printf("\n");
            break;
        }
    }
    return 0;
}