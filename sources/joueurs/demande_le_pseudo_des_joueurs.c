#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demande_le_pseudo_des_joueurs.h"

void enleverPseudos(char ***tabpseudo, int nbjoueur)
{
    for (int i = 0; i < nbjoueur; i++)
    {
        free((*tabpseudo)[i]);
    }
    free(*tabpseudo);
    *tabpseudo = NULL;
}

int ajouterPseudo(char ***tabpseudo, int *nbjoueur, char *nom)
{
    char **noms_nouveau = realloc(*tabpseudo, (*nbjoueur + 1) * sizeof(char *));
    if (!noms_nouveau)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(1);
    }
    *tabpseudo = noms_nouveau;
    (*tabpseudo)[*nbjoueur] = nom;
    (*nbjoueur)++;
    return 0;
}

// Pourquoi passer un pointeur sur nbjoueur et un triple pointeur sur tabpseudo ?
// Cela permet de modifier les valeurs de nbjoueur et tabpseudo dans la fonction
// Et tabpseudo est un double pointeur car c'est un tableau de pointeurs
// Car on ne connait pas à l'avance le nombre de joueurs
// On ne peut pas allouer un tableau de taille fixe
int demanderPseudos(int *nbjoueur, char ***tabpseudo)
{
    if (nbjoueur <= 0)
    {
        fprintf(stderr, "[DEPR] Le nombre de joueurs doit être supérieur à 0\n");
        enleverPseudos(tabpseudo, *nbjoueur);
        *nbjoueur = 0;
        return 0;
    }

    char *pseudo = malloc(4 * sizeof(char));
    printf("Joueur %d, donnez votre pseudo de 3 lettres : ", *nbjoueur + 1);
    scanf("%3s", pseudo);
    fflush(stdin); // Vide les caractères restants si le pseudo est plus long que 3 caractères

    if (ajouterPseudo(tabpseudo, nbjoueur, pseudo))
    {
        printf("[demanderPseudos] Erreur lors de l'ajout du pseudo\n");
        exit(1);
    }
    return 0;
}

/*
int main()
{
    int nbjoueur = 2;
    char **tabpseudo = malloc(nbjoueur * sizeof(char *));
    if (!tabpseudo)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }
    // Pouquoi strdup ?
    // strdup alloue de la mémoire pour une chaîne de caractères et copie la chaîne passée en argument
    // Cela permet de ne pas avoir à faire malloc
    tabpseudo[0] = strdup("PIX");
    tabpseudo[1] = strdup("JUL");

    if (demanderPseudos(&nbjoueur, &tabpseudo) != 0)
    {
        fprintf(stderr, "Erreur lors de la demande des pseudos.\n");
        return 1;
    }

    for (int i = 0; i < nbjoueur; i++)
    {
        printf("Joueur %d : %s\n", i + 1, tabpseudo[i]);
    }

    enleverPseudos(&tabpseudo, nbjoueur);
    nbjoueur = 0;

    return 0;
}
*/
