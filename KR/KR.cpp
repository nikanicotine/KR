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

	int i = 0;

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

	strcpy(active[0], "   ||      — ЧТЕНИЕ ГРАФА ИЗ ФАЙЛА —      ||");
	strcpy(active[1], "   ||        — РУЧНОЙ ВВОД ГРАФА —        ||");
	strcpy(active[2], "   ||        — ГЕНЕРАЦИЯ МАТРИЦЫ —        ||");
	strcpy(active[3], "   ||       — ВЫПОЛНЕНИЕ АЛГОРИТМА —      ||");
	strcpy(active[4], "   ||  — СОХРАНЕНИЕ РЕЗУЛЬТАТОВ В ФАЙЛ —  ||");
	strcpy(active[5], "   ||              — ВЫХОД —              ||");
	//MENU

	while (i != amount) {
		i = menu(i);

		switch (i) {
		case 0: { // чтение
			system("cls");
			arr = openfile(arr);
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
			printf("   Заполните матрицу! \n   ");

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					scanf_s("%d", &arr[i][j]);
				}
				printf("   ");
			}
			err = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] != 0 && i == j) {
						printf("Ошибка! Не содержится 0 на главной диагонали\n   ");
						err = 1;
						system("pause");
						break;
					}
					if (arr[i][j] < 0) {
						printf("Ошибка! Ребро отрицательного веса\n   ");
						err = 1;
						system("pause");
						break;
					}
					if (arr[i][j] != arr[j][i]) {
						printf("Ошибка! Матрица несимметрична относительно главной диагонали\n   ");
						err = 1;
						system("pause");
						break;
					}
				}
				if (err == 1) {
					for (int i = 0; i < n; i++)
						free(arr[i]);
						free(arr);
						arr = NULL;
						break;
				}
			}
			break;
		}
		case 2: { // генерация 
			system("cls");
			srand(time(NULL));
			if (arr != NULL) {
				for (int i = 0; i < n; i++)
					free(arr[i]);
				free(arr);
			}
			printf("\n   Введите количество вершин: ");
			scanf_s("%d", &n);
			arr = (int**)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++) {
				arr[i] = (int*)malloc(n * sizeof(int));
			}
			printf("\n");
			for (int i = 0; i < n; i++) {
				arr[i][i] = 0;
				for (int j = i + 1; j < n; j++) {
					arr[i][j] = rand() % 10;
					arr[j][i] = arr[i][j];
				}
			}
			/*for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {

					if (i == j)
						arr[i][j] = 0;
				}
			}*/
			for (int i = 0; i < n; i++) {
				printf("  ");
				for (int j = 0; j < n; j++) {
					printf("%2d", arr[i][j]);
				}
				printf("\n");
			}
			printf("\n   ");
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

			printf("\n   Матрица:\n");
			for (int i = 0; i < n; i++) {
				printf("  ");
				for (int j = 0; j < n; j++) {
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
			int sum;
			tn = n;
			for (int i = 0; i < n; i++) {
				sum = 0;
				for (int j = 0; j < n; j++) {
					sum += arr[i][j];
				}
				if (sum == 0)
					tn--;
			}

			while (vis_n < tn)
			{
				min = INT_MAX;
				for (i = 0; i < n; i++)
					for (j = 0; j < n; j++)
						if (arr[i][j] < min && arr[i][j] != 0 && visited[j] == 0 && visited[i] != 0)
						{
							min = arr[i][j];
							a = i;
							b = j;
						}

				if (visited[b] == 0) {  // если вершина не посещалась то
					way[vis_n] = b;		//запись номера вершины
					vis_n++;
					visited[b] = 1;		//отметить как посещенную
				}
			}

			printf("\n   Минимальное остновное дерево:\n   ");
			for (int i = 0; i < tn; i++) {
				printf("%d ", way[i]);
				if (i < tn - 1)
					printf("—> ");
			}
			printf("\n   ");
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
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					fprintf(file, "%d ", arr[i][j]);
				}
				fprintf(file, "\n");
			}

			fprintf(file, "Минимальное остовное дерево:\n");
			for (int i = 0; i < tn; i++)
			{
				fprintf(file, "%d ", way[i]);
				if (i < tn - 1)
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