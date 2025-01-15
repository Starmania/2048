void affichagetab();

void affichagetab()
{
    int i;
    printf("| ");
    for (i = 0; i < nbjoueur; i++)
    {
        printf("   joueur %d   | ", i + 1);
    }
    printf("\n| ");

    for (i = 0; i < nbjoueur; i++)
    {
        printf("%10d    | ", tabscore[i]);
    }
    printf("\n");
}
