/**
 * @file tri_insertion.c
 * @authors Pierre JANVIER et Oscar SAPY
 * @brief Ce fichier contient la fonction de tri par insertion
 * @version 1.0
 * @date 2021-10-10
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cette fonction permet de trier un tableau grâce à l'agorithme de tri par insertion
 * @param tab 
 * @param longueur 
 */
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