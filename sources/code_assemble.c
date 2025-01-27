#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "scores/afficherscore.h"
#include "scores/supprimer_les_scores.h"
#include "scores/meilleur_score.h"
#include "scores/remplir_le_tableau.h"
#include "joueurs/demande_le_pseudo_des_joueurs.h"
#include "grille_de_jeu/grille_de_jeu.h"
#include "coeur.h"

int jeux_decision()
{
    int grid[SIZE][SIZE];
    char move;
    char ancien_coup;
    int gameOver = 0;
    int score = 0;
    int coup_invalide = 0;

    srand(time(NULL));

    initialiserTableau(grid);

    // Ajoute deux cases au démarrage
    score += spawnTile(grid);
    score += spawnTile(grid);

    while (!gameOver)
    {
        afficherTableau(grid);

        printf("Entrez un mouvement (z/q/s/d): ");
        scanf(" %c", &move);
        fflush(stdin);

        switch (move)
        {
        case 'z':
            score += mouvementHaut(grid);
            break;
        case 'q':
            score += mouvementGauche(grid);
            break;
        case 's':
            score += mouvementBas(grid);
            break;
        case 'd':
            score += mouvementDroite(grid);
            break;
        case 'e':
            gameOver = 1;
            continue;
        default:
            printf("Move invalide\n");
            coup_invalide = 1;
            continue;
        }

        if (move != ancien_coup && !coup_invalide)
        {
            score += spawnTile(grid);
            ancien_coup = move;
        }

        if (!mouvementPossible(grid) || gameOver)
        {
            gameOver = 1;
            afficherTableau(grid);
            printf("Game Over! Score: %d\n", score);
        }
        coup_invalide = 0;
    }

    return score;
}

int decision(int *nbjoueur, int **tabscore, char ***tabpseudo)
{
    char choix;

    printf("Voulez-vous démarrer le jeu :\n");
    printf("(o)ui\n(a)fficher les scores\n(e)ffacer les scores\n(q)uitter\n");
    printf("Entrez la première lettre de votre choix en minuscule : ");
    scanf(" %c", &choix);

    switch (choix)
    {
    case 'o':
        printf("Démarrage du jeu.\n");

        if (demanderPseudos(nbjoueur, tabpseudo) != 0)
        {
            printf("Erreur lors de la demande des pseudos.\n");
            exit(1);
        }

        int *score_nouveau = realloc(*tabscore, *nbjoueur * sizeof(int *));
        if (!score_nouveau)
        {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(1);
        }
        *tabscore = score_nouveau;
        (*tabscore)[*nbjoueur - 1] = 0;

        int scoremax = *tabscore[classement(*tabscore, *nbjoueur)];

        printf("Démarrage du jeu...\n");
        printf("Le score a battre est %d\n", scoremax);
        int score = jeux_decision();
        (*tabscore)[*nbjoueur - 1] = score;
        break;
    case 'a':
        affichagetab(*tabscore, *tabpseudo, *nbjoueur);
        break;
    case 'e':
        resetscore(*tabscore, nbjoueur);
        enleverPseudos(tabpseudo, nbjoueur);
        nbjoueur = 0;
        break;
    case 'q':
        scoremax = 0;
        if (*nbjoueur > 1)
            scoremax = *tabscore[classement(*tabscore, *nbjoueur)];
        classement(*tabscore, *nbjoueur);
        printf("Jeu fini\n");
        printf("le meilleure score était %d\n", scoremax);
        return 1;
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

    while (!decision(&nbjoueur, &tabscore, &tabpseudo))
    {
    }

    resetscore(&tabscore, nbjoueur);
    nbjoueur = 0;

    return 0;
}
