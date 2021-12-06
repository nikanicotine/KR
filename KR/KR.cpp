
#include "pch.h"
#include "Header.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>


int main() {
	setlocale(0, "RUS");

	for (int i = 0; i < amount; i++) {
		passive[i] = (char*)malloc(sizeof(char) * 50);
		active[i] = (char*)malloc(sizeof(char) * 50);
	}

	strcpy(passive[0], "   ||        Чтение графа из файла        ||");
	strcpy(passive[1], "   ||          Ручной ввод графа          ||");
	strcpy(passive[2], "   ||          Генерация матрицы          ||");
	strcpy(passive[3], "   ||         Выполнение алгоритма        ||");
	strcpy(passive[4], "   ||    Сохранение результатов в файл    ||");
	strcpy(passive[5], "   ||                Выход                ||");

	strcpy(active[0],  "   ||      — ЧТЕНИЕ ГРАФА ИЗ ФАЙЛА —      ||");
	strcpy(active[1],  "   ||        — РУЧНОЙ ВВОД ГРАФА —        ||");
	strcpy(active[2],  "   ||        — ГЕНЕРАЦИЯ МАТРИЦЫ —        ||");
	strcpy(active[3],  "   ||       — ВЫПОЛНЕНИЕ АЛГОРИТМА —      ||");
	strcpy(active[4],  "   ||  — СОХРАНЕНИЕ РЕЗУЛЬТАТОВ В ФАЙЛ —  ||");
	strcpy(active[5],  "   ||              — ВЫХОД —              ||");
	//MENU

	while (i!=amount) {
		i = menu(i);

		switch (i) {
		case 0: { // чтение
			system("cls");
			openfile(arr, n);
			printf("   Файл успешно открыт!\n");
			system("pause");
			break; 
		}
		case 1: { // ручной
			system("cls");
			printf("   Введите количество вершин: ");
			scanf_s("%d", &n);
			arr = (int**)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++) {
				arr[i] = (int*)malloc(n * sizeof(int));
			}
			printf("\n   Заполните матрицу! \n   ");

			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					scanf_s("%d", &arr[i][j]);
				}
				printf("   ");
			}
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (arr[i][j] != 0 && i == j) {
						printf("   Содержится 0 на главной диагонали\n   ");
						system("pause");
						break;
					}
					if (arr[i][j] < 0) {
						printf("   Ребро отрицательного веса\n   ");
						system("pause");
						break;
					}
					if (arr[i][j] != arr[j][i]) {
						printf("   Матрица несимметрична относительно главной диагонали\n   ");
						system("pause");
						break;
					}
				}
			}
			break;
		}
		case 2: { // генерация 
			system("cls");
			srand(time(NULL));
			printf("\n   Введите количество вершин: ");
			scanf_s("%d", &n);
			arr = (int**)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++) {
				arr[i] = (int*)malloc(n * sizeof(int));
			}
			printf("\n");
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++)
					arr[i][j] = rand() % 10;
			}
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					arr[i][j] = arr[j][i];
					if (i == j)
						arr[i][j] = 0;
				}
			}
			for (i = 0; i < n; i++) {
				printf("  ");
				for (j = 0; j < n; j++) {
					printf("%2d", arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			system("pause");
			break;
		}
		case 3: { //алгоритм
			system("cls");
			if (arr == NULL) {
				printf("\n   Граф не был создан!\n   ");
				system("pause");
				break;
			}

			printf("\n");
			for (i = 0; i < n; i++) {
				printf("  ");
				for (j = 0; j < n; j++) {
					printf("%2d", arr[i][j]);
				}
				printf("\n");
			}

			visited = (int*)calloc(n, sizeof(int));

			if (way != NULL)
				free(way);
			way = (int*)malloc((n) * sizeof(int));
			
			visited[0] = 1;
			way[0] = 0;
			vis_n = 1;
			while (vis_n < n)
			{
				min = INT_MAX;
				for (i = 0; i < n; i++)
					for (j = i + 1; j < n; j++)
						if (arr[i][j] < min && arr[i][j] != 0 && visited[j] == 0 && visited[i] != 0)
						{
							min = arr[i][j];
							a = i;
							b = j;
						}

				if (visited[b] == 0)  // если вершина не посещалась то 
				{
					way[vis_n] = b;  //запись номера вершины
					vis_n++;
					visited[b] = 1;  //отметить как посещенную
				}

			}

			printf("\n   ");

			for (int i = 0; i < n; i++)
			{
				printf("%d ", way[i]);
				if (i < n - 1)
					printf("—> ");
			}
			printf("\n");
			free(visited);
			system("pause");
			break;
		}
		case 4: { // сохранение
			system("cls");
			if (arr == NULL) {
				printf("\n   Граф не был создан!\n   ");
				system("pause");
				break;
			}

			if (way == NULL) {
				printf("\n   Остовное дерево не было создано!\n   ");
				system("pause");
				break;
			}
			char filename[260];
			FILE* file;

			printf("\n   Введите имя файла: ");
			scanf("%s", filename);
			strcat(filename, ".txt");
			file = fopen(filename, "w");
			fprintf(file, "Матрица:\n");
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					fprintf(file, "%d ", arr[i][j]);
				}
				fprintf(file, "\n");
			}

			fprintf(file, "Минимальное остовное дерево:\n");
			for (int i = 0; i < n; i++)
			{
				fprintf(file, "%d ", way[i]);
				if (i < n - 1)
					fprintf(file, "—> ");
			}

			fclose(file);
			printf("   Данные успешно сохранены!\n   ");
			system("pause");
			break;
		}
		case 5: exit(0);

		}
	}
}