#include <stdio.h>

void affichagetab(int *tabscore, *tabpseudo, *nbjoueur)
{
    int i;
    printf("| ");
    for (i = 0; i < nbjoueur; i++)
    {
        printf("      %3s      | ", tabpseudo[i]);
    }
    printf("\n| ");

    for (i = 0; i < nbjoueur; i++)
    {
        printf("%10d    | ", tabscore[i]);
    }
    printf("\n");
}
