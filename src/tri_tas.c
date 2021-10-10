/**
 * @file tri_tas.c
 * @authors Pierre JANVIER et Oscar SAPY
 * @brief Ce fichier contient la fonction de tri par tas
 * @version 1.0
 * @date 2021-10-10
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cette fonction permet l'inversement de 2 valeurs
 * @param a 
 * @param b 
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Cette fonction permet de restructurer notre tas en arbre binaire afin de ranger les noeuds
 * @param tab 
 * @param n 
 * @param i 
 */
void heapify(int tab[], int n, int i)
{
    int max = i; //Initialize max as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //If left child is greater than root
    if (left < n && tab[left] > tab[max])
        max = left;

    //If right child is greater than max
    if (right < n && tab[right] > tab[max])
        max = right;

    //If max is not root
    if (max != i)
    {
        swap(&tab[i], &tab[max]);
        //heapify the affected sub-tree recursively
        heapify(tab, n, max);
    }
}

/**
 * @brief Cette fonction permet de trier un tableau grâce à l'agorithme de tri par tas
 * @param tab 
 * @param longueur 
 */
void tri_tas(float *tab, int longueur)
{
    //Rearrange array (building heap)
    for (int i = longueur / 2 - 1; i >= 0; i--)
        heapify(tab, longueur, i);

    //Extract elements from heap one by one
    for (int i = longueur - 1; i >= 0; i--)
    {
        swap(&tab[0], &tab[i]); //Current root moved to the end

        heapify(tab, i, 0); //calling max heapify on the heap reduced
    }
}
