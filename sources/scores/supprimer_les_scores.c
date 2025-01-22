#include <stdio.h>

void resetscore(int *tabscore, int nbjoueur)
{
    int i;
    for (i = 0; i < nbjoueur; i++)
    {
        tabscore[i] = 0;
    }
    printf("les scores ont été rénitialisés.");
}
