#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "grille_de_jeu.h"

/*
int main()
{
    int mat[SIZE][SIZE];
    initialiserTableau(mat);
    afficherTableau(mat);
    return 0;
}
*/

void afficherTableau(int tab[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        printf("|");
        for (j = 0; j < SIZE; j++)
        {
            printf("%4d |", tab[i][j]);
        }
        printf("\n");
    }
}

void initialiserTableau(int tab[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            tab[i][j] = 0;
        }
    }
}
