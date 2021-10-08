#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void tri_bulle(float *tab, int longueur)
{
    float temporaire;
    bool tour = true;
    while (tour == true)
    {
        tour = false;
        for (int i = 0; i < longueur; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                temporaire = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temporaire;
                tour = true;
            }
        }
    }
}