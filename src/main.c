#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* #include "../include/tri_bulle.h"
#include "../include/tri_insertion.h"
#include "../include/tri_selection.h"
#include "../include/tri_tas.h" */

void create_csv(char *filename, float csvtab[5][7])
{

	FILE *fp;
	printf("%s", filename);
	fp = fopen(filename, "+w");

	fprintf(fp, "Taille tableau / tri", "Tri à bulle", "Tri par sélection", "Tri par insertion", "Tri par tas");
	fprintf(fp, "100", csvtab[0][0], csvtab[0][1], csvtab[0][2], csvtab[0][3]);
	fprintf(fp, "10³", csvtab[1][0], csvtab[1][1], csvtab[1][2], csvtab[1][3]);
	fprintf(fp, "10⁴", csvtab[2][0], csvtab[2][1], csvtab[2][2], csvtab[2][3]);
	fprintf(fp, "10⁵", csvtab[3][0], csvtab[3][1], csvtab[3][2], csvtab[3][3]);
	fprintf(fp, "10⁶", csvtab[4][0], csvtab[4][1], csvtab[4][2], csvtab[4][3]);
	fprintf(fp, "10⁷", csvtab[5][0], csvtab[5][1], csvtab[5][2], csvtab[5][3]);

	fclose(fp);
	printf("Fichier %s modifié !", filename);
}

int main()
{

	//Tableau permettant de récupérer les valeurs du CSV
	float csvtab[5][7];

	clock_t debut, fin; //temps de debut et de fin en micro seconde
	//initialisation de des variable de temps moyen pour les differents tries et des variable permetant de stoquer le temps a chaque teste des tries
	float temp_bulle[5], temp_insert[5], temp_tas[5], temp_selec[5], temp_total[2];

	//initialisation des tableau et de leur tailles
	int taille[6] = {100, 1000, 10000, 100000, 1000000, 10000000};
	//float tabtri[] = taille[i];

	//initialisation de la seed random
	srand((unsigned int)time(NULL));

	for (int f = 0; f < 6; f++)
	{
		//initialisation de tabtri + set d'un tableau global contenant les les trois tableau definit precedement

		float tabtri[taille[f]];

		float tab_global[3][taille[f]];

		//set des trois liste de valeur aleatoire dans un tableau global
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

		//test de tri_bulle avec trois tableau different
		for (int l = 0; l < 3; l++)
		{
			//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
			for (int m = 0; m < taille[m]; m++)
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
		temp_bulle[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		printf("la moyenne de temps pour les differents testes pour un tableau de %d valeure de tri_bulle est de : %.2f ms\n", taille[f], temp_bulle);

		//test de tri_selection avec trois tableau different
		for (int l = 0; l < 3; l++)
		{
			//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
			for (int m = 0; m < taille[m]; m++)
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
		temp_selec[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		printf("la moyenne de temps pour les differents testes pour un tableau de %d valeure de tri_selection est de : %.2f ms\n", taille[f], temp_selec);

		//test de tri_insertion avec trois tableau different
		for (int l = 0; l < 3; l++)
		{
			//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
			for (int m = 0; m < taille[m]; m++)
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
		temp_insert[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		printf("la moyenne de temps pour les differents testes pour un tableau de %d valeure de tri_insertion est de : %.2f ms\n", taille[f], temp_insert);

		//test de tri_tas avec trois tableau different
		for (int l = 0; l < 3; l++)
		{
			//transfere du l-eme tableau dans tabtri, le tableau qui vas etre trié
			for (int m = 0; m < taille[m]; m++)
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
		temp_tas[f] = (temp_total[0] + temp_total[1] + temp_total[2]) / 3;
		printf("la moyenne de temps pour les differents testes pour un tableau de %d valeure de tri_tas est de : %.2f ms\n", taille[f], temp_tas);
	}
	printf("Fin.");
	/* create_csv(?,csvtab); */
	printf("Programme terminé.");
}