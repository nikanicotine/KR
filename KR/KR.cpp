
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

	strcpy(passive[0], "   ||        „тение графа из файла        ||");
	strcpy(passive[1], "   ||          –учной ввод графа          ||");
	strcpy(passive[2], "   ||          √енераци€ матрицы          ||");
	strcpy(passive[3], "   ||         ¬ыполнение алгоритма        ||");
	strcpy(passive[4], "   ||    —охранение результатов в файл    ||");
	strcpy(passive[5], "   ||                ¬ыход                ||");

	strcpy(active[0],  "   ||      Ч „“≈Ќ»≈ √–ј‘ј »« ‘ј…Ћј Ч      ||");
	strcpy(active[1],  "   ||        Ч –”„Ќќ… ¬¬ќƒ √–ј‘ј Ч        ||");
	strcpy(active[2],  "   ||        Ч √≈Ќ≈–ј÷»я ћј“–»÷џ Ч        ||");
	strcpy(active[3],  "   ||       Ч ¬џѕќЋЌ≈Ќ»≈ јЋ√ќ–»“ћј Ч      ||");
	strcpy(active[4],  "   ||  Ч —ќ’–јЌ≈Ќ»≈ –≈«”Ћ№“ј“ќ¬ ¬ ‘ј…Ћ Ч  ||");
	strcpy(active[5],  "   ||              Ч ¬џ’ќƒ Ч              ||");
	//MENU

	while (i!=amount) {
		i = menu(i);

		switch (i) {
		case 0: {
			system("cls");
			openfile(arr, n);
			printf("   ‘айл успешно открыт!\n");
			system("pause");
			break; 
		}
		case 1: {
			system("cls");
			printf("   ¬ведите количество вершин: \n");
			scanf_s("%d", &n);
			arr = (int**)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++) {
				arr[i] = (int*)malloc(n * sizeof(int));
			}
			printf("   «аполните матрицу! \n   ");

			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					scanf_s("%d", &arr[i][j]);
				}
				printf("\n   ");
			}
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					if (arr[i][j] != 0 && i == j) {
						printf("   —одержитс€ 0 на главной диагонали\n");
						system("pause");
						break;
					}
					if (arr[i][j] < 0) {
						printf("   –ебро отрицательного веса\n");
						system("pause");
						break;
					}
					if (arr[i][j] != arr[j][i]) {
						printf("   ћатрица несимметрична относительно главной диагонали\n");
						system("pause");
						break;
					}
				}
			}
			break;
		}
		case 2: {
			system("cls");
			srand(time(NULL));
			printf("\n   ¬ведите количество вершин: ");
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
		case 3: {
			system("cls");
			if (arr == NULL) {
				printf("\n   √раф не был создан!\n");
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
						if (arr[i][j] < min && arr[i][j] != 0 && visited[i] != 0)
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
				arr[a][b] = arr[b][a] = 0;  // обнуление проверенных вершин
			}

			printf("\n   ");

			for (int i = 0; i < n; i++)
			{
				printf("%d ", way[i]);
				if (i < n - 1)
					printf("Ч> ");
			}
			printf("\n");
			free(visited);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			if (arr == NULL) {
				printf("\n   √раф не был создан!\n");
				break;
			}

			if (way == NULL) {
				printf("\n   ќстовное дерево не было создано!\n");
				break;
			}
			char filename[260];
			FILE* file;

			printf("\n   ¬ведите им€ файла: ");
			scanf("%s", filename);
			strcat(filename, ".txt");
			file = fopen(filename, "w");
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					fprintf(file, "%2d", arr[i][j]);
				}
				fprintf(file, "\n");
			}

			for (int i = 0; i < n; i++)
			{
				fprintf(file, " %d ", way[i]);
				if (i < n - 1)
					fprintf(file, "Ч>");
			}

			fclose(file);
			printf("   ƒанные успешно сохранены!\n");
			system("pause");
			break;
		}
		case 5: exit(0);

		}
	}
}