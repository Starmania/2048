#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for 4 pointers to char
    char **noms = malloc(4 * sizeof(char *));
    if (!noms)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    noms[0] = "Jean";
    noms[1] = "Paul";
    noms[2] = "Jacques";
    noms[3] = "Marie";

    char **noms_nouveau = realloc(noms, 5 * sizeof(char *));
    if (!noms_nouveau)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    noms = noms_nouveau;
    noms[4] = "Pierre";

    // Free the allocated memory
    free(noms);

    return 0;
}
