#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* #include "../include/tri_bulle.h"
#include "../include/tri_insertion.h"
#include "../include/tri_selection.h" */

int main()
{
	clock_t debut, fin; //temps de debut et de fin en micro seconde
	float temp_total;

	/* 	//Test function tri_selection()
	float T[] = {30, 8, 1, 9, 85, 17, 55, 10, 11, 100};
	tri_selection(T, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%.2f ", T[i]);
	} */

	/* 	//Test function tri_bulle()
	float T[] = {30, 8, 1, 9, 85, 17, 55, 10, 11, 100};
	tri_bulle(T, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%.2f ", T[i]);
	} */

	/* 	//Test function tri_insertion()
	float T[] = {173, 83, 170, 71, 41, 76, 150, 184, 12, 185, 169, 59, 89, 116, 138, 140, 24, 176, 68, 23, 104, 131, 148, 163, 141, 159, 1, 93, 65, 95, 46, 7, 82, 64, 56, 24};
	debut = clock();
	tri_insertion(T, 10);
	fin = clock();
	temp_total = (fin - debut); //calcule du temp total en seconde
	printf("%f\n", temp_total);
	for (int i = 0; i < 10; i++)
	{
		printf("%.2f ", T[i]);
	} */

	//Génération d'un tableau de taille = X
	srand((unsigned int)time(NULL));
	int taille;
	printf("Entrez la taille de votre tableau de valeurs aléatoires : ");
	scanf("%d", &taille);
	float T[taille];

	for (int i = 0; i < taille; i++)
	{
		int nb = rand() % 100 + 1;
		T[i] = ((float)rand() / (float)(RAND_MAX)) + nb;
	}
	printf("\n");

	//Test function tri_tas()
	debut = clock();
	tri_tas(T, taille);
	fin = clock();
	temp_total = (fin - debut);
	for (int i = 0; i < taille; ++i)
	{
		printf("%.2f ", T[i]);
	}
	printf("\nLe temps total est de : %f millisecondes.\n", temp_total);
}