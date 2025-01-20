#include <stdio.h>
#include <stdlib.h>

int classement(int *tabscore, int nbjoueur)
{
    if (nbjoueur <= 0)
    {
        fprintf(stderr, "Erreur, le nombre de joueur doit être supérieur à 0\n");
        return -1;
    }
    int scoremax = tabscore[0];
    int indexScoreMax = 0;
    for (int i = 0; i < nbjoueur; i++)
    {
        // Strictement supérieur pour que le premier joueur soit le meilleur
        if (tabscore[i] > scoremax)
        {
            scoremax = tabscore[i];
            indexScoreMax = i;
        }
    }
    return indexScoreMax;
}

int main()
{
    int *tabscore = malloc(5 * sizeof(int));
    tabscore[0] = 100;
    tabscore[1] = 500;
    tabscore[2] = 300;
    tabscore[3] = 200;
    tabscore[4] = 500;

    int nbjoueur = 5;

    int indexScoreMax = classement(tabscore, nbjoueur);
    int scoreMax = tabscore[indexScoreMax];
    printf("Le meilleur score est %d, obtenu par le joueur n°%d\n", scoreMax, indexScoreMax + 1);

    return 0;
}
