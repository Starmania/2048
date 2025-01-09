#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *tabscore;
    int nbjoueur;
    int i;

    printf("Combien de joueurs êtes-vous : ");
    scanf("%d", &nbjoueur);

    tabscore = (int *)calloc(nbjoueur, sizeof(int));
    if (tabscore == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }        
    printf("| ");
    for(int i = 0; i < nbjoueur; i++){
        printf("   joueur %d   | ", i+1);}
    printf("\n| ");
    
    for(int i = 0; i < nbjoueur; i++)
        printf("%10d    | ", tabscore[i]);
    
    free(tabscore);

    return 0;
}
