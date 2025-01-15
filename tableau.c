#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[3][3];
    initialiserTableau(mat);
    afficherTableau(mat);
    return 0;
}

void afficherTableau(int tab[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("|");
        for (j = 0; j < 3; j++)
        {
            printf("%4d |", tab[i][j]);
        }
        printf("\n");
    }
}

void initialiserTableau(int tab[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tab[i][j] = 0;
        }
    }
}
