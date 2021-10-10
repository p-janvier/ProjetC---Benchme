/**
 * @file tri_selection.c
 * @authors Pierre JANVIER et Oscar SAPY
 * @brief Ce fichier contient la fonction de tri par sélection
 * @version 1.0
 * @date 2021-10-10
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cette fonction permet de trier un tableau grâce à l'agorithme de tri par sélection
 * @param tab 
 * @param longueur 
 */
void tri_selection(float *tab, int longueur)
{
    int min, temp;

    for (int i = 0; i < longueur - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < longueur; j++)
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