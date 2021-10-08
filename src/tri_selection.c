#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tri_selection(float *tab, int n)
{
    int min, temp;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (tab[j] < tab[min])
                min = j;
        if (min != i)
        {
            temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp;
        }
    }
}