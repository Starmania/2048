#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afficherscore.h"
#include "demande_le_pseudo_des_joueurs.h"
#include "supprimer_les_scores.h"
#include "meilleur_score.h"
#include "remplir_le_tableau.h"
#include "grille_de_jeu.h"
#include "coeur.h"

int decision(char choix, int *nbjoueur, int **tabscore, char ***tabpseudo)
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
        if (demanderPseudos(nbjoueur, tabpseudo) != 0)
        {
            printf("Erreur lors de la demande des pseudos.\n");
            exit(1);
        }
        tabscore = realloc(tabscore, *nbjoueur * sizeof(int));
        if (tabscore == NULL)
        {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(1);
        }
        int scoremax = 0;
        if (*nbjoueur > 1)
            scoremax = *tabscore[classement(*tabscore, *nbjoueur)];

        printf("Démarrage du jeu...\n");
        printf("Le score a battre est %d\n", scoremax);
        break;
    case 'a':
        affichagetab(*tabscore, *nbjoueur);
        break;
    case 'e':
        resetscore(*tabscore, *nbjoueur); // TODO: ""
        break;
    case 'q':
        scoremax = 0;
        if (*nbjoueur > 1)
            scoremax = *tabscore[classement(*tabscore, *nbjoueur)];
        classement(*tabscore, *nbjoueur);
        printf("Jeu fini\n");
        printf("le meilleure score était %d\n", scoremax);
        exit(0);
    default:
        printf("Erreur, choix impossible\n");
    }

    return 0;
}

int main(void)
{
    // 1. Initialiser les variables

    // [-] Démarrage de la boucle principale

    // 2. Afficher le menu

    // 3. Lire le choix de l'utilisateur

    // 3.1. Si l'utilisateur veut démarrer le jeu
    // 3.1.1. Demander le pseudo du joueur
    // 3.1.2. Initialiser le score du joueur à 0
    // 3.1.3. Lancer le jeu
    // 3.1.4. Demander le nom du joueur
    // 3.1.5. Mettre à jour le score du joueur
    // 3.1.6. Revenir à l'étape 2

    // 3.2 Si l'utilisateur veut afficher les scores
    // 3.2.1. Afficher les scores
    // 3.2.2. Revenir à l'étape 2

    // 3.3. Si l'utilisateur veut réinitialiser les scores
    // 3.3.1. Réinitialiser les scores
    // 3.3.2. Revenir à l'étape 2

    // 3.4. Si l'utilisateur veut quitter
    // 3.4.1. Quitter le programme

    // 3.5. Si le choix n'est pas valide
    // 3.5.1. Afficher un message d'erreur
    // 3.5.2. Revenir à l'étape 2

    int nbjoueur = 0;
    int *tabscore = NULL;
    char **tabpseudo = NULL;
    int score;
    int scoremax;

    char choix;

    while (1)
    {
        decision(choix, &nbjoueur, &tabscore, &tabpseudo);
    }

    // Libérer la mémoire allouée
    free(tabscore);
    for (int i = 0; i < nbjoueur; i++)
    {
        free(tabpseudo[i]);
    }
    free(tabpseudo);

    return 0;
}
