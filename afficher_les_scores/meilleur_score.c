void classement(int *tabscore, int nbjoueur);
void classement(int *tabscore, int nbjoueur)
{
    for (int i = 0; i < nbjoueur; i++)
    {
        if (tabscore[i] > scoremax)
        {
            scoremax = tabscore[i];
        }
    }
}
