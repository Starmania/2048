#include <stdio.h>
#include <stdlib.h>
    int *tabscore;
    int nbpartie=0;
    tabscore=malloc(sizeof (int)*nbpartie);
void supprimerScore() {
free(tabscore);
    printf("Tout les scores ont été supprimés.\n");
}
