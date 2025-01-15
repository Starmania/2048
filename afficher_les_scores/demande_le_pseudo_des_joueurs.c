int demanderPseudos(int nbjoueur, char ***tabpseudo);

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
    strcpy((*tabpseudo)[nbjoueur-1], pseudo);//copie le pseudo du joueur dans un tableau
    return 0;
}
