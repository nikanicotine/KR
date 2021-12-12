#pragma once
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int* way = NULL;
int* visited = NULL;
int** arr = NULL;
int amount = 6;
int min, a, b, i, j, vis_n, tn, n;
char* passive[6];
char* active[6];

void main_menu_pos(char* passive[], char* active[], int amount, int selected) {
	system("cls");
	for (int i = 0; i < selected; i++) {
		printf("   _________________________________________\n\n");
		printf("%s\n", passive[i]);
		printf("   _________________________________________\n");
	}
	printf("   _________________________________________\n\n");
	printf("%s\n", active[selected]);
	printf("   _________________________________________\n");

	for (int i = selected + 1; i < amount; i++) {
		printf("   _________________________________________\n\n");
		printf("%s\n", passive[i]);
		printf("   _________________________________________\n");
	}
}
int** openfile(int** arr) {
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			free(arr[i]);
		}
		free(arr);
	}
	char filename[260];
	FILE* file;
	n = 0;
	printf("\n   Введите имя файла: ");
	scanf("%s", filename);
	strcat(filename, ".txt");
	file = fopen(filename, "r");
	if (file == NULL) {
		printf("   Файла с таким именем не существует!\n   ");
		system("pause");
		return arr;
	}
	 do {
		fscanf(file, "%d");
		n++;
	 } while (fgetc(file) != '\n');

	 fseek(file, 0, SEEK_SET);

	arr = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(file, "%d", &arr[i][j]);
		}
	}
	fclose(file);
	printf("   Матрица из файла успешно считана!\n");
	for (i = 0; i < n; i++) {
		printf("  ");
		for (j = 0; j < n; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n   ");
	system("pause");
	return arr;
}
int menu(int i) {
	system("cls");
	i = 0;
	main_menu_pos(passive, active, amount, i);
	char klav;
	do {
		klav = _getch();
		if (klav == 80) {
			i++;
			if (i == amount) {
				i = 0;
				main_menu_pos(passive, active, amount, i);
			}
			else
				main_menu_pos(passive, active, amount, i);
		}

		if (klav == 72) {
			i--;
			if (i == -1) {
				i = amount - 1;
				main_menu_pos(passive, active, amount, i);
			}
			else
				main_menu_pos(passive, active, amount, i);
		}
	} while (klav != 13);
	return i;
}