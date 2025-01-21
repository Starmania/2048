#include <stdio.h>
#include <stdlib.h>

char tabpseudo[255][4];
int *tabscore[255];
int nbjoueur;
int score;
int scoremax;

void remplirtableau(int nbjoueur, int *tabscore);
int remplirtab(int nbjoueur, int *tabscore, int score, int joueur);
int demanderPseudos(int nbjoueur, char ***tabpseudo);
void classement(int *tabscore, int nbjoueur);

int decision(char choix)
{
    printf("Voulez-vous démarrer le jeu :\n");
    printf("(o)ui\n(a)fficher les scores\n(e)ffacer les scores\n(q)uitter\n");
    printf("Entrez la première lettre de votre choix en minuscule : ");
    scanf(" %c", &choix);

    switch (choix)
    {
    case 'o':
        printf("Démarrage du jeu.\n");
        nbjoueur += 1;
        if (demanderPseudos(nbjoueur, &tabpseudo) != 0)
        {
            printf("Erreur lors de la demande des pseudos.\n");
        }
        int *tabscore = realloc(tabscore, nbjoueur * sizeof(int));
        if (tabscore == NULL)
        {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(1);
        }
        for (int i = 0; i < nbjoueur; i++)
        {
            printf("Combien de points a eu %s : ", tabpseudo[i]);
            scanf("%d", &score);
            remplirtab(nbjoueur, tabscore, score, i);
        }
        classement(tabscore, nbjoueur);
        printf("Démarrage du jeu...\n");
        printf("Le score a battre est %d\n", scoremax);
        break;
    case 'a':
        affichagetab();
        break;
    case 'e':
        resetscore(tabscore, nbjoueur);
        break;
    case 'q':
        classement(tabscore, nbjoueur);
        printf("Jeu fini\n");
        printf("le meilleure score était %d\n", scoremax);
        exit(0);
    default:
        printf("Erreur, choix impossible\n");
    }

    return 0;
}
