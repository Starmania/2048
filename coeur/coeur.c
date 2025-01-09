#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4

void initializeGrid(int grid[SIZE][SIZE]);
void displayGrid(int grid[SIZE][SIZE]);
int getNextNonZero(int row[SIZE], int index);
void slideRowLeft(int row[SIZE]);
void spawnTile(int grid[SIZE][SIZE]);
void moveLeft(int grid[SIZE][SIZE]);
void moveRight(int grid[SIZE][SIZE]);
void moveUp(int grid[SIZE][SIZE]);
void moveDown(int grid[SIZE][SIZE]);
int canMove(int grid[SIZE][SIZE]);
int getRandomCaseNumber();
void reverseRow(int row[SIZE]);
void transposeGrid(int grid[SIZE][SIZE]);

int main()
{
    int grid[SIZE][SIZE];
    char move;
    int gameOver = 0;

    srand(time(NULL));

    initializeGrid(grid);

    grid[1][1] = 1111;
    grid[1][2] = 2222;
    grid[2][1] = 3333;
    grid[2][2] = 4444;

    // Ajoute deux cases au démarrage
    // spawnTile(grid);
    // spawnTile(grid);

    while (!gameOver)
    {
        displayGrid(grid);

        printf("Enter move (z/q/s/d): ");
        scanf(" %c", &move);
        // printf("Appuyer sur entré pour continuer...");
        // scanf("%c");

        switch (move)
        {
        case 'z':
            moveUp(grid);
            break;
        case 'q':
            moveLeft(grid);
            break;
        case 's':
            moveDown(grid);
            break;
        case 'd':
            moveRight(grid);
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
            printf("Invalid move. Try again.\n");
            continue;
        }

        // spawnTile(grid);

        slideRowLeft(grid[0]);

        if (!canMove(grid))
        {
            gameOver = 1;
            printf("Game Over! No more moves possible.\n");
        }
    }

    return 0;
}

void initializeGrid(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = 0; // SIZE * i + j + 1;
}

void displayGrid(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("|%4d", grid[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// Faire apparaître une case de manière aléatoire
void spawnTile(int grid[SIZE][SIZE])
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
    }
}

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

// Retourne le premier index à partir de `index` avec une valeur différente de 0
// Si pas d'autre objet, retourne -1
int getNextNonZero(int row[SIZE], int index)
{
    int i = index;
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

void slideRowLeft(int row[SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
    {
        int movedObject = getNextNonZero(row, i);
        if (movedObject == -1)
            break;

        int addedObject = getNextNonZero(row, movedObject + 1);
        if (addedObject != -1 && row[movedObject] == row[addedObject])
        {
            row[movedObject] *= 2;
            row[addedObject] = 0;
        }
        if (i != movedObject)
        {
            row[i] = row[movedObject];
            row[movedObject] = 0;
        }
    }
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
            // displayGrid(grid);
        }
    }
}

void moveLeft(int grid[SIZE][SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
    {
        slideRowLeft(grid[i]);
    }
}

void moveRight(int grid[SIZE][SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
    {
        reverseRow(grid[i]);
        slideRowLeft(grid[i]);
        reverseRow(grid[i]);
    }
}

void moveUp(int grid[SIZE][SIZE])
{
    transposeGrid(grid);
    printf("Transposed:\n");
    displayGrid(grid);
    moveLeft(grid);
    transposeGrid(grid);
}

void moveDown(int grid[SIZE][SIZE])
{
    transposeGrid(grid);
    moveRight(grid);
    transposeGrid(grid);
}

int canMove(int grid[SIZE][SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 0)
                return 1; // Il reste des cases vides

            if (i < SIZE - 1 && grid[i][j] == grid[i + 1][j])
                return 1; // Il reste des cases adjacentes horizontalement

            if (j < SIZE - 1 && grid[i][j] == grid[i][j + 1])
                return 1; // Il reste des cases adjacentes verticalement
        }
    }
    return 0;
}
