#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* #include "../include/tri_bulle.h"
#include "../include/tri_insertion.h"
#include "../include/tri_selection.h"
#include "../include/tri_tas.h" */

int main()
{
	clock_t debut, fin; //temps de debut et de fin en micro seconde
	//initialisation de des variable de temps moyen pour les differents tries et des variable permetant de stoquer le temps a chaque teste des tries
	float temp_bulle, temp_insert, temp_tas, temp_selec, temp_total[2];

	//initialisation des tableau et de leur tailles
	int taille;
	printf("Entrez la taille de votre tableau de valeurs aléatoires : ");
	scanf("%d", &taille);
	float tabtri[taille];
	//set d'un tableau global contenant les les trois tableau definit precedement
	float tab_global[3][taille];

	//initialisation de la seed random
	srand((unsigned int)time(NULL));

	//set des trois liste de valeur aleatoire dans un tableau global
	for (int i = 0; i < taille; i++)
	{
		int nb = rand() % 100 + 1;
		tab_global[0][i] = ((float)rand() / (float)(RAND_MAX)) + nb;
	}
	for (int j = 0; j < taille; j++)
	{
		int nb = rand() % 100 + 1;
		tab_global[1][j] = ((float)rand() / (float)(RAND_MAX)) + nb;
	}
	for (int k = 0; k < taille; k++)
	{
		int nb = rand() % 100 + 1;
		tab_global[2][k] = ((float)rand() / (float)(RAND_MAX)) + nb;
	}

	//test de tri_bulle avec trois tableau different
	for (int l = 0; l < 3; l++)
	{
		//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
		for (int m = 0; m < taille; m++)
		{
			tabtri[m] = tab_global[l][m];
		}

		//lancement du compteur de temps
		debut = clock();

		//trie du tableau
		tri_bulle(tabtri, taille);

		//fin du compteur de temps
		fin = clock();

		//calcule et affichage du temp total en ms
		temp_total[l] = fin - debut;
		printf("tour %d : %.2f ms\n ", l, temp_total[l]);
	}
	//calcule et affichage de la moyene des different temps en ms pour tri_bulle
	temp_bulle = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
	printf("la moyenne de temps pour les differents testes de tri_bulle est de : %.2f ms\n", temp_bulle);

	//test de tri_selection avec trois tableau different
	for (int l = 0; l < 3; l++)
	{
		//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
		for (int m = 0; m < taille; m++)
		{
			tabtri[m] = tab_global[l][m];
		}

		//lancement du compteur de temps
		debut = clock();

		//trie du tableau
		tri_insertion(tabtri, taille);

		//fin du compteur de temps
		fin = clock();

		//calcule et affichage du temp total en ms
		temp_total[l] = fin - debut;
		printf("tour %d : %.2f ms\n ", l, temp_total[l]);
	}
	//calcule et affichage de la moyene des different temps en ms pour tri_selection
	temp_selec = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
	printf("la moyenne de temps pour les differents testes de tri_selection est de : %.2f ms\n", temp_selec);

	//test de tri_insertion avec trois tableau different
	for (int l = 0; l < 3; l++)
	{
		//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
		for (int m = 0; m < taille; m++)
		{
			tabtri[m] = tab_global[l][m];
		}

		//lancement du compteur de temps
		debut = clock();

		//trie du tableau
		tri_insertion(tabtri, taille);

		//fin du compteur de temps
		fin = clock();

		//calcule et affichage du temp total en ms
		temp_total[l] = fin - debut;
		printf("tour %d : %.2f ms\n ", l, temp_total[l]);
	}
	//calcule et affichage de la moyene des different temps en ms pour tri_insertion
	temp_insert = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
	printf("la moyenne de temps pour les differents testes de tri_insertion est de : %.2f ms\n", temp_insert);

	//test de tri_tas avec trois tableau different
	for (int l = 0; l < 3; l++)
	{
		//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
		for (int m = 0; m < taille; m++)
		{
			tabtri[m] = tab_global[l][m];
		}

		//lancement du compteur de temps
		debut = clock();

		//trie du tableau
		tri_tas(tabtri, taille);

		//fin du compteur de temps
		fin = clock();

		//calcule et affichage du temp total en ms
		temp_total[l] = fin - debut;
		printf("tour %d : %.2f ms\n ", l, temp_total[l]);
	}
	//calcule et affichage de la moyene des different temps en ms pour tri_tas
	temp_tas = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
	printf("la moyenne de temps pour les differents testes de tri_tas est de : %.2f ms\n", temp_tas);
}