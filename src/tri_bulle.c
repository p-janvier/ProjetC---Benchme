/**
 * @file tri_bulle.c
 * @authors Pierre JANVIER et Oscar SAPY
 * @brief Ce fichier contient la fonction de tri à bulle
 * @version 1.0
 * @date 2021-10-10
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Cette fonction permet de trier un tableau grâce à l'agorithme de tri à bulle
 * @param tab 
 * @param longueur 
 */
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