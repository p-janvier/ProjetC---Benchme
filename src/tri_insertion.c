#include <stdio.h>
#include <stdlib.h>

void tri_insertion(float *tab, int longueur)
{
    int i, j;
    float en_cours;

    for (i = 0; i < longueur; i++)
    {
        en_cours = tab[i];
        for (j = i; j > 0 && tab[j - 1] > en_cours; j--)
        {
            tab[j] = tab[j - 1];
        }
        tab[j] = en_cours;
    }
}