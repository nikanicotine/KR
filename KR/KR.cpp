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

	strcpy(passive[0], "   ||        ������ ����� �� �����        ||");
	strcpy(passive[1], "   ||          ������ ���� �����          ||");
	strcpy(passive[2], "   ||          ��������� �������          ||");
	strcpy(passive[3], "   ||         ���������� ���������        ||");
	strcpy(passive[4], "   ||    ���������� ����������� � ����    ||");
	strcpy(passive[5], "   ||                �����                ||");

	strcpy(active[0], "   ||      � ������ ����� �� ����� �      ||");
	strcpy(active[1], "   ||        � ������ ���� ����� �        ||");
	strcpy(active[2], "   ||        � ��������� ������� �        ||");
	strcpy(active[3], "   ||       � ���������� ��������� �      ||");
	strcpy(active[4], "   ||  � ���������� ����������� � ���� �  ||");
	strcpy(active[5], "   ||              � ����� �              ||");
	//MENU

	while (i != amount) {
		i = menu(i);

		switch (i) {
		case 0: { // ������
			system("cls");
			arr = openfile(arr);
			break;
		}
		case 1: { // ������
			system("cls");
			printf("   ������� ���������� ������: ");
			scanf_s("%d", &n);
			arr = (int**)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++) {
				arr[i] = (int*)malloc(n * sizeof(int));
			}
			printf("   ��������� �������! \n   ");

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
						printf("������! �� ���������� 0 �� ������� ���������\n   ");
						err = 1;
						system("pause");
						break;
					}
					if (arr[i][j] < 0) {
						printf("������! ����� �������������� ����\n   ");
						err = 1;
						system("pause");
						break;
					}
					if (arr[i][j] != arr[j][i]) {
						printf("������! ������� ������������� ������������ ������� ���������\n   ");
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
		case 2: { // ��������� 
			system("cls");
			srand(time(NULL));
			if (arr != NULL) {
				for (int i = 0; i < n; i++)
					free(arr[i]);
				free(arr);
			}
			printf("\n   ������� ���������� ������: ");
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
		case 3: { //��������
			system("cls");
			if (arr == NULL) {
				printf("\n   ���� �� ��� ������!\n   ");
				system("pause");
				break;
			}

			printf("\n   �������:\n");
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

				if (visited[b] == 0) {  // ���� ������� �� ���������� ��
					way[vis_n] = b;		//������ ������ �������
					vis_n++;
					visited[b] = 1;		//�������� ��� ����������
				}
			}

			printf("\n   ����������� ��������� ������:\n   ");
			for (int i = 0; i < tn; i++) {
				printf("%d ", way[i]);
				if (i < tn - 1)
					printf("�> ");
			}
			printf("\n   ");
			free(visited);
			system("pause");
			break;
		}
		case 4: { // ����������
			system("cls");
			if (arr == NULL) {
				printf("\n   ���� �� ��� ������!\n   ");
				system("pause");
				break;
			}

			if (way == NULL) {
				printf("\n   �������� ������ �� ���� �������!\n   ");
				system("pause");
				break;
			}
			char filename[260];
			FILE* file;

			printf("\n   ������� ��� �����: ");
			scanf("%s", filename);
			strcat(filename, ".txt");
			file = fopen(filename, "w");
			fprintf(file, "�������:\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					fprintf(file, "%d ", arr[i][j]);
				}
				fprintf(file, "\n");
			}

			fprintf(file, "����������� �������� ������:\n");
			for (int i = 0; i < tn; i++)
			{
				fprintf(file, "%d ", way[i]);
				if (i < tn - 1)
					fprintf(file, "�> ");
			}

			fclose(file);
			printf("   ������ ������� ���������!\n   ");
			system("pause");
			break;
		}
		case 5: exit(0);
		}
	}
}