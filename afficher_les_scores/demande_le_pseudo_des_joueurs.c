#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int demanderPseudos(int nbjoueur, char **tabpseudo)
{
    if (nbjoueur <= 0)
    {
        fprintf(stderr, "Erreur, le nombre de joueur doit être supérieur à 0\n");
        return 1;
    }

    char pseudo[4];
    int size = nbjoueur;
    char **tabpseudo_nouveau = realloc(tabpseudo, nbjoueur * sizeof(char *));
    if (!tabpseudo_nouveau)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }
    tabpseudo = tabpseudo_nouveau;

    printf("Joueur %d, donnez votre pseudo de 3 lettres : ", nbjoueur);
    scanf("%3s", pseudo);
    fflush(stdin); // Vide les caractères restants si le pseudo est plus long que 3 caractères

    tabpseudo[nbjoueur - 1] = malloc(4 * sizeof(char));
    if (!tabpseudo[nbjoueur - 1])
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        for (int k = 0; k < nbjoueur - 1; k++)
        {
            free(tabpseudo[k]);
        }
        free(tabpseudo);
        return 1;
    }
    strcpy(tabpseudo[nbjoueur - 1], pseudo); // copie le pseudo du joueur dans un tableau
    return 0;
}

int main()
{
    int nbjoueur = 2;
    char **tabpseudo = malloc(nbjoueur * sizeof(char *));
    if (!tabpseudo)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }
    tabpseudo[0] = "PIX";
    tabpseudo[1] = "JUL";

    if (demanderPseudos(nbjoueur + 1, tabpseudo) != 0)
    {
        fprintf(stderr, "Erreur lors de la demande des pseudos.\n");
        return 1;
    }

    for (int i = 0; i < nbjoueur + 1; i++)
    {
        printf("Joueur %d : %s\n", i + 1, tabpseudo[i]);
    }

    return 0;
}
