#include <stdio.h>
#include <stdlib.h>

void tri_insertion(float *t, int longueur)
{
    int i, j;
    float en_cours;

    for (i = 0; i < longueur; i++)
    {
        en_cours = t[i];
        for (j = i; j > 0 && t[j - 1] > en_cours; j--)
        {
            t[j] = t[j - 1];
        }
        t[j] = en_cours;
    }
}