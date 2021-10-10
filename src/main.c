/**
 * @file main.c
 * @authors Pierre JANVIER et Oscar SAPY
 * @brief Ce programme permet de confronter et de déterminer le meilleur algortihme de tri par rapport à un tableau de X valeurs allant de 0 à 10⁶
 * @version 1.0
 * @date 2021-10-10
 * @copyright Copyright (c) 2021
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/tri_bulle.h"
#include "../include/tri_insertion.h"
#include "../include/tri_selection.h"
#include "../include/tri_tas.h"

/**
 * @brief Cette fonction permet la création d'un fichier .csv
 * @param filename 
 * @param csvtab 
*/
void create_csv(char *filename, float csvtab[6][4])
{

	FILE *fp;
	printf("%s", filename);
	fp = fopen("benchme_result.csv", "a");

	//Définition du model du fichier .csv qui va être généré
	fprintf(fp, "Taille tableau / tri, Tri à bulle, Tri par sélection, Tri par insertion, Tri par tas\n");
	fprintf(fp, "100, %.2f, %.2f, %.2f, %.2f\n", csvtab[0][0], csvtab[0][1], csvtab[0][2], csvtab[0][3]);
	fprintf(fp, "10³, %.2f, %.2f, %.2f, %.2f\n", csvtab[1][0], csvtab[1][1], csvtab[1][2], csvtab[1][3]);
	fprintf(fp, "10⁴, %.2f, %.2f, %.2f, %.2f\n", csvtab[2][0], csvtab[2][1], csvtab[2][2], csvtab[2][3]);
	fprintf(fp, "10⁵, %.2f, %.2f, %.2f, %.2f\n", csvtab[3][0], csvtab[3][1], csvtab[3][2], csvtab[3][3]);
	fprintf(fp, "10⁶, %.2f, %.2f, %.2f, %.2f\n", csvtab[4][0], csvtab[4][1], csvtab[4][2], csvtab[4][3]);
	fprintf(fp, "10⁷, %.2f, %.2f, %.2f, %.2f\n", csvtab[5][0], csvtab[5][1], csvtab[5][2], csvtab[5][3]);

	fclose(fp);
	printf("Fichier %s modifié !\n", filename);
}

int main()
{

	//Initialisation d'un tableau permettant de récupérer les valeurs du CSV
	float csvtab[6][4];

	//Initialisation de nos variables de temps en millisecondes
	clock_t debut, fin;

	//Initialisation des variable de temps moyen pour les differents tris et des variables permetant de stocker le temps pour chaque test
	float temp_bulle[5], temp_selec[5], temp_insert[5], temp_tas[5], temp_total[2];

	//Initialisation des différentes taille possible pour les tableaux
	int taille[4] = {100, 1000, 10000, 100000};

	//Initialisation d'une seed random pour la génération des valeurs de nos tableaux
	srand((unsigned int)time(NULL));

	printf("*******************\n");
	printf("Début du programme.\n");
	printf("*******************\n\n");

	for (int f = 0; f < 4; f++)
	{
		//Initialisation de tabtri et de tab_global contenant les trois tableaux de valeurs aléatoires
		float tabtri[taille[f]];
		float tab_global[3][taille[f]];

		//Création des trois listes de valeur aleatoire dans tab_global
		for (int i = 0; i < taille[f]; i++)
		{
			int nb = rand() % 1000000 + 1;
			tab_global[0][i] = ((float)rand() / (float)(RAND_MAX)) + nb;
		}
		for (int j = 0; j < taille[f]; j++)
		{
			int nb = rand() % 1000000 + 1;
			tab_global[1][j] = ((float)rand() / (float)(RAND_MAX)) + nb;
		}
		for (int k = 0; k < taille[f]; k++)
		{
			int nb = rand() % 1000000 + 1;
			tab_global[2][k] = ((float)rand() / (float)(RAND_MAX)) + nb;
		}

		//Test de l'algorithme de tri à bulle avec les 3 tableaux différents
		for (int l = 0; l < 3; l++)
		{
			//Transfere du l-eme tableau dans tabtri (c'est à dire le tableau qui va être trié)
			for (int m = 0; m < taille[f]; m++)
			{
				tabtri[m] = tab_global[l][m];
			}

			//Lancement du compteur de temps
			debut = clock();

			//Le tableau se fait trier
			tri_bulle(tabtri, taille[f]);

			//Arrêt du compteur de temps
			fin = clock();

			//Calcul et affichage du temps de tri du tableau en milliseconde
			temp_total[l] = fin - debut;
			printf("Test %d : %.2f ms.\n", l + 1, temp_total[l]);
		}
		//Calcul et affichage de la moyenne du temps d'exécution du tri à bulle en milliseconde suivant les 3 tris effectués
		temp_bulle[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		csvtab[f][0] = temp_bulle[f];
		printf("La moyenne de temps pour effectuer les tests d'un tableau de %d valeurs pour un tri à bulle est de : %.2f ms.\n\n", taille[f], temp_bulle);

		//Test de l'algorithme de tri par sélection avec les 3 tableaux différents
		for (int l = 0; l < 3; l++)
		{
			//Transfere du l-eme tableau dans tabtri (c'est à dire le tableau qui va être trié)
			for (int m = 0; m < taille[f]; m++)
			{
				tabtri[m] = tab_global[l][m];
			}

			//Lancement du compteur de temps
			debut = clock();

			//Le tableau se fait trier
			tri_insertion(tabtri, taille[f]);

			//Arrêt du compteur de temps
			fin = clock();

			//Calcul et affichage du temps de tri du tableau en milliseconde
			temp_total[l] = fin - debut;
			printf("Test %d : %.2f ms.\n", l + 1, temp_total[l]);
		}
		//Calcul et affichage de la moyenne du temps d'exécution du tri par sélection en milliseconde suivant les 3 tris effectués
		temp_selec[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		csvtab[f][1] = temp_selec[f];
		printf("La moyenne de temps pour effectuer les tests d'un tableau de %d valeurs pour un tri par sélection est de : %.2f ms.\n\n", taille[f], temp_selec);

		//Test de l'algorithme de tri par insertion avec les 3 tableaux différents
		for (int l = 0; l < 3; l++)
		{
			//Transfere du l-eme tableau dans tabtri (c'est à dire le tableau qui va être trié)
			for (int m = 0; m < taille[f]; m++)
			{
				tabtri[m] = tab_global[l][m];
			}

			//Lancement du compteur de temps
			debut = clock();

			//Le tableau se fait trier
			tri_insertion(tabtri, taille[f]);

			//Arrêt du compteur de temps
			fin = clock();

			//Calcul et affichage du temps de tri du tableau en milliseconde
			temp_total[l] = fin - debut;
			printf("Test %d : %.2f ms.\n", l + 1, temp_total[l]);
		}
		//Calcul et affichage de la moyenne du temps d'exécution du tri par insertion en milliseconde suivant les 3 tris effectués
		temp_insert[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		csvtab[f][2] = temp_insert[f];
		printf("La moyenne de temps pour effectuer les tests d'un tableau de %d valeurs pour un tri par insertion est de : %.2f ms.\n\n", taille[f], temp_insert);

		//Test de l'algorithme de tri par tas avec les 3 tableaux différents
		for (int l = 0; l < 3; l++)
		{
			//Transfere du l-eme tableau dans tabtri (c'est à dire le tableau qui va être trié)
			for (int m = 0; m < taille[f]; m++)
			{
				tabtri[m] = tab_global[l][m];
			}

			//Lancement du compteur de temps
			debut = clock();

			//Le tableau se fait trier
			tri_tas(tabtri, taille[f]);

			//Arrêt du compteur de temps
			fin = clock();

			//Calcul et affichage du temps de tri du tableau en milliseconde
			temp_total[l] = fin - debut;
			printf("Test %d : %.2f ms.\n", l + 1, temp_total[l]);
		}
		//Calcul et affichage de la moyenne du temps d'exécution du tri par tas en milliseconde suivant les 3 tris effectués
		temp_tas[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		csvtab[f][3] = temp_tas[f];
		printf("La moyenne de temps pour effectuer les tests d'un tableau de %d valeurs pour un tri par tas est de : %.2f ms.\n\n", taille[f], temp_tas);
	}

	create_csv("benchme_result.csv", *csvtab);
	printf("*******************\n");
	printf("Programme terminé.\n");
	printf("*******************\n");
}