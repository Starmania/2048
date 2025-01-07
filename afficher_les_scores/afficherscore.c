#include <stdio.h>
#include <stdlib.h>
    int *tabscore;
    int nbpartie=0;
    tabscore=malloc(sizeof (int)*nbpartie);
void supprimerScore() {
free(tabscore);
    printf("Tout les scores ont été supprimés.\n");
}
#include <stdio.h>

void afficherTableau(int lignes, int colonnes) {
    int i, j;

    // Afficher la première ligne du tableau
    for (j = 0; j < colonnes; j++) {
        printf("+---");
    }
    printf("+\n");

    // Afficher les lignes intermédiaires du tableau
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            printf("|   ");
        }
        printf("|\n");

        // Afficher les lignes de séparation
        for (j = 0; j < colonnes; j++) {
            printf("+---");
        }
        printf("+\n");
    }
}

int main() {
    int lignes = 2; // Nombre de lignes du tableau
    int colonnes = 5; // Nombre de colonnes du tableau

    afficherTableau(lignes, colonnes);

    return 0;
}
