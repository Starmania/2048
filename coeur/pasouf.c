#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ajouterNom(char ***noms, int *taille, char *nom)
{
    char **noms_nouveau = realloc(*noms, (*taille + 1) * sizeof(char *));
    if (!noms_nouveau)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *noms = noms_nouveau;
    (*noms)[*taille] = nom;
    (*taille)++;
    return 0;
}

int enleverTousLesNoms(char ***noms, int *taille)
{
    for (int i = 0; i < *taille; i++)
    {
        free((*noms)[i]);
    }
    free(*noms);
    *noms = NULL;
    *taille = 0;
    return 0;
}

// Testé avec gcc -O0 + valgrind.
// Pas de fuite de mémoire :)
int tester(char ***noms, int *taille)
{
    for (size_t i = 0; i < 8; i++)
    {
        ajouterNom(noms, taille, strdup("John Doe"));
        ajouterNom(noms, taille, strdup("Doe John"));
    }

    printf("Taille: %d\n", *taille);

    // Enlève tous les noms
    enleverTousLesNoms(noms, taille);

    printf("Taille: %d\n", *taille);
}

int main()
{
    // Ajoute des noms à la liste
    char **noms = NULL;
    int taille = 0;
    tester(&noms, &taille);
    tester(&noms, &taille);
    printf("Taille en dehors 1: %d\n", taille);
    tester(&noms, &taille);
    printf("Taille en dehors 1: %d\n", taille);

    return 0;
}
