#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nbjoueur = 0;
int *tabscore = NULL;
char **tabpseudo = NULL;
int score;
int scoremax;
    
// Prototypes des fonctions
int resetscore(int *tabscore, int nbjoueur);
int remplirtab(int nbjoueur, int *tabscore, int score, int joueur);
int decision(char choix);
int affichagetab();
int demanderPseudos(int nbjoueur, char ***tabpseudo);
void classement(int *tabscore, int nbjoueur);

int resetscore(int *tabscore, int nbjoueur) {
    for (int i = 0; i < nbjoueur; i++) {
        tabscore[i] = 0;
    }
    printf("Les scores ont été réinitialisés.\n");
    return 0;
}

int remplirtab(int nbjoueur, int *tabscore, int score, int joueur) {
    tabscore[joueur] = score;
    return 0;
}

int decision(char choix) {
    printf("Voulez-vous démarrer le jeu :\n");
    printf("(o)ui\n(a)fficher les scores\n(e)ffacer les scores\n(q)uitter\n");
    printf("Entrez la première lettre de votre choix en minuscule : ");
    scanf(" %c", &choix);

    switch (choix) {
        case 'o':
            printf("Démarrage du jeu.\n");
            nbjoueur += 1;
            if (demanderPseudos(nbjoueur, &tabpseudo) != 0) {
                printf("Erreur lors de la demande des pseudos.\n");
            }
            tabscore = realloc(tabscore, nbjoueur * sizeof(int));
            if (tabscore == NULL) {
                fprintf(stderr, "Erreur d'allocation mémoire\n");
                return 1;
            }
            for (int i = 0; i < nbjoueur; i++) {
                printf("Combien de points a eu %s : ", tabpseudo[i]);
                scanf("%d", &score);
                remplirtab(nbjoueur, tabscore, score, i);
            }
                    classement(tabscore, nbjoueur);
                        printf("Démarrage du jeu...\n");
                        printf("Le score a battre est %d\n",scoremax);
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
            printf("le meilleure score était %d\n",scoremax);
            exit(0);
        default:
            printf("Erreur, choix impossible\n");
    }

    return 0;
}

int affichagetab() {
    printf("| ");
    for (int i = 0; i < nbjoueur; i++) {
        printf("      %3s      | ", tabpseudo[i]);
    }
    printf("\n| ");

    for (int i = 0; i < nbjoueur; i++) {
        printf("%10d     | ", tabscore[i]);
    }
    printf("\n");

    return 0;
}

int demanderPseudos(int nbjoueur, char ***tabpseudo) {
    char pseudo[4];
    *tabpseudo = realloc(*tabpseudo, nbjoueur * sizeof(char*));
    if (*tabpseudo == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    printf("Joueur %d, donnez votre pseudo de 3 lettres : ", nbjoueur);
    scanf("%3s", pseudo);
    (*tabpseudo)[nbjoueur-1] = malloc(4 * sizeof(char));
    if ((*tabpseudo)[nbjoueur-1] == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        for (int k = 0; k < nbjoueur-1; k++) {
            free((*tabpseudo)[k]);
        }
        free(*tabpseudo);
        return 1;
    }
    strcpy((*tabpseudo)[nbjoueur-1], pseudo);
    return 0;
}
void classement(int *tabscore,int nbjoueur){
    for(int i=0;i<nbjoueur;i++){
        if (tabscore[i]>scoremax){
            scoremax=tabscore[i];
        }
    }
}
int main(void) {
    char choix;

    while (1) {
        decision(choix);
    }

    // Libérer la mémoire allouée
    free(tabscore);
    for (int i = 0; i < nbjoueur; i++) {
        free(tabpseudo[i]);
    }
    free(tabpseudo);

    return 0;
}
