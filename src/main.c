#include <stdio.h>
/* #include "../include/tri_bulle.h"
#include "../include/tri_insertion.h"
#include "../include/tri_selection.h" */

int main()
{
	/* 	//Test function tri_selection()
	float T[] = {30, 8, 1, 9, 85, 17, 55, 10, 11, 100};
	tri_selection(T, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%.f ", T[i]);
	} */

	/* 	//Test function tri_bulle()
	float T[] = {30, 8, 1, 9, 85, 17, 55, 10, 11, 100};
	tri_bulle(T, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%.f ", T[i]);
	} */

	//Test function tri_insertion()
	float T[] = {30, 8, 1, 9, 85, 17, 55, 10, 11, 100};
	tri_insertion(T, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%.f ", T[i]);
	}
}