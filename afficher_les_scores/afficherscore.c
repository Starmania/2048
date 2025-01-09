#include <stdio.h>
#include <stdlib.h>
int resetscore(int *tabscore,int nbjoueur) { 
    int i;
    for(i=0;i<nbjoueur;i++){
        tabscore[i]=0;
    }
    printf("les scores ont été rénitialisés.");
    return 0;
}
int remplirtableau (int nbjoueur, int *tabscore) {
    tabscore[nbjoueur]=score
    
    return 0;
}
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
