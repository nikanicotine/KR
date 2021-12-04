
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

	strcpy(passive[0], "   ||        ������ ����� �� �����        ||");
	strcpy(passive[1], "   ||          ������ ���� �����          ||");
	strcpy(passive[2], "   ||          ��������� �������          ||");
	strcpy(passive[3], "   ||         ���������� ���������        ||");
	strcpy(passive[4], "   ||    ���������� ����������� � ����    ||");
	strcpy(passive[5], "   ||                �����                ||");

	strcpy(active[0],  "   ||      � ������ ����� �� ����� �      ||");
	strcpy(active[1],  "   ||        � ������ ���� ����� �        ||");
	strcpy(active[2],  "   ||        � ��������� ������� �        ||");
	strcpy(active[3],  "   ||       � ���������� ��������� �      ||");
	strcpy(active[4],  "   ||  � ���������� ����������� � ���� �  ||");
	strcpy(active[5],  "   ||              � ����� �              ||");
	//MENU

	while (i!=amount) {
		i = menu(i);

		switch (i) {
		case 0: {
			system("cls");
			openfile(arr, n);
			printf("   ���� ������� ������!\n");
			system("pause");
			break; 
		}
		case 1: {
			system("cls");
			printf("   ������� ���������� ������: \n");
			scanf_s("%d", &n);
			arr = (int**)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++) {
				arr[i] = (int*)malloc(n * sizeof(int));
			}
			printf("   ��������� �������! \n   ");

			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					scanf_s("%d", &arr[i][j]);
				}
				printf("\n   ");
			}
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					if (arr[i][j] != 0 && i == j) {
						printf("   ���������� 0 �� ������� ���������\n");
						system("pause");
						break;
					}
					if (arr[i][j] < 0) {
						printf("   ����� �������������� ����\n");
						system("pause");
						break;
					}
					if (arr[i][j] != arr[j][i]) {
						printf("   ������� ������������� ������������ ������� ���������\n");
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
			printf("\n   ������� ���������� ������: ");
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
				printf("\n   ���� �� ��� ������!\n");
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

				if (visited[b] == 0)  // ���� ������� �� ���������� �� 
				{
					way[vis_n] = b;  //������ ������ �������
					vis_n++;
					visited[b] = 1;  //�������� ��� ����������
				}
				arr[a][b] = arr[b][a] = 0;  // ��������� ����������� ������
			}

			printf("\n   ");

			for (int i = 0; i < n; i++)
			{
				printf("%d ", way[i]);
				if (i < n - 1)
					printf("�> ");
			}
			printf("\n");
			free(visited);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			if (arr == NULL) {
				printf("\n   ���� �� ��� ������!\n");
				break;
			}

			if (way == NULL) {
				printf("\n   �������� ������ �� ���� �������!\n");
				break;
			}
			char filename[260];
			FILE* file;

			printf("\n   ������� ��� �����: ");
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
					fprintf(file, "�>");
			}

			fclose(file);
			printf("   ������ ������� ���������!\n");
			system("pause");
			break;
		}
		case 5: exit(0);

		}
	}
}