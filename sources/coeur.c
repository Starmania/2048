#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "grille_de_jeu.h"

/*
int main()
{
    int grid[SIZE][SIZE];
    char move;
    int gameOver = 0;
    int score = 0;

    srand(time(NULL));

    initialiserTableau(grid);

    grid[2][1] = 1111;
    grid[2][2] = 2222;
    grid[3][1] = 3333;
    grid[3][2] = 4444;

    // Ajoute deux cases au démarrage
    // score += spawnTile(grid);
    // score += spawnTile(grid);

    while (!gameOver)
    {
        afficherTableau(grid);

        printf("Enter move (z/q/s/d): ");
        scanf(" %c", &move);
        // printf("Appuyer sur entré pour continuer...");
        // scanf("%c");

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
        // case 't':
        //     transposeGrid(grid);
        //     break;
        // case 'r':
        //     for (size_t i = 0; i < SIZE; i++)
        //     {
        //         reverseRow(grid[i]);
        //     }
        //     break;
        default:
            printf("Move invalide\n");
            continue;
        }

        // score += spawnTile(grid);

        if (0 && !mouvementPossible(grid))
        {
            gameOver = 1;
            printf("Game Over! Score: %d\n", score);
        }
    }

    return 0;
}
*/

// Retourne un nombre aléatoire entre 2 et 4
// Il y a 9 chances sur 10 que le nombre soit 2
int getRandomCaseNumber()
{
    if (rand() % 10)
    { // 9 chances sur 10 que la case soit 2, sinon 4
        return 2;
    }
    else
    {
        return 4;
    }
}

// Faire apparaître une case de manière aléatoire
int spawnTile(int grid[SIZE][SIZE])
{
    int empty[SIZE * SIZE][2];
    int count = 0;

    // Liste les cases vides, et les stocke dans empty
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 0)
            {
                empty[count][0] = i;
                empty[count][1] = j;
                count++;
            }
        }
    }

    if (count > 0)
    {
        int r = rand() % count;
        int x = empty[r][0];
        int y = empty[r][1];
        grid[x][y] = getRandomCaseNumber();
        return grid[x][y];
    }
    return 0;
}

// Retourne le premier index à partir de `indexDeDebut` avec une valeur différente de 0
// Si pas d'autre objet, retourne -1
int getNextNonZero(int row[SIZE], int indexDeDebut)
{
    int i = indexDeDebut;
    int found = 0;
    for (; i < SIZE; i++)
        if (row[i] != 0)
        {
            found = 1;
            break;
        }
    if (!found)
        return -1;
    return i;
}

// La fonction la plus importante
// Elle fait glisser les objets vers la gauche
// Elle fusionne les objets identiques
// Elle retourne le score des fusions
int slideRowLeft(int row[SIZE])
{
    int score = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        // Trouve le prochain objet non nul
        int movedObject = getNextNonZero(row, i);
        if (movedObject == -1)
            break;

        // Trouve le prochain objet non nul après movedObject
        int addedObject = getNextNonZero(row, movedObject + 1);
        // Si les objets sont identiques, fusionne-les
        if (addedObject != -1 && row[movedObject] == row[addedObject])
        {
            // Fusion de row[movedObject] et row[addedObject]
            row[movedObject] *= 2;
            row[addedObject] = 0;
            score += row[movedObject];
        }
        // Déplace l'objet vers la gauche
        if (i != movedObject)
        {
            row[i] = row[movedObject];
            row[movedObject] = 0;
        }
    }
    return score;
}

void reverseRow(int row[SIZE])
{
    for (size_t i = 0; i < SIZE / 2; i++)
    {
        int temp = row[i];
        row[i] = row[SIZE - i - 1];
        row[SIZE - i - 1] = temp;
    }
}

// Transforme une grille [x][y] en [y][x]
void transposeGrid(int grid[SIZE][SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = i + 1; j < SIZE; j++)
        {
            // printf("i: %zu, j: %zu\n", i, j);
            int temp = grid[i][j];
            grid[i][j] = grid[j][i];
            grid[j][i] = temp;
            // afficherTableau(grid);
        }
    }
}

int mouvementGauche(int grid[SIZE][SIZE])
{
    int score = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        score += slideRowLeft(grid[i]);
    }
    return score;
}

int mouvementDroite(int grid[SIZE][SIZE])
{
    int score = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        reverseRow(grid[i]);
        score += slideRowLeft(grid[i]);
        reverseRow(grid[i]);
    }
    return score;
}

int mouvementHaut(int grid[SIZE][SIZE])
{
    int score = 0;
    transposeGrid(grid);
    score += mouvementGauche(grid);
    transposeGrid(grid);
    return score;
}

int mouvementBas(int grid[SIZE][SIZE])
{
    int score = 0;
    transposeGrid(grid);
    score += mouvementDroite(grid);
    transposeGrid(grid);
    return score;
}

int mouvementPossible(int grid[SIZE][SIZE])
{
    // size_t car on ne varie que dans [0...SIZE-1], pas besoin de valeurs négatives
    // Sinon ça se comporte comme un int avec un maxi plus grand que int
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 0)
                return 1; // Il reste des cases vides

            // i < SIZE - 1 pour éviter de sortir du tableau
            if (i < SIZE - 1 && grid[i][j] == grid[i + 1][j])
                return 1; // Il reste des cases adjacentes horizontalement

            if (j < SIZE - 1 && grid[i][j] == grid[i][j + 1])
                return 1; // Il reste des cases adjacentes verticalement
        }
    }
    return 0;
}
