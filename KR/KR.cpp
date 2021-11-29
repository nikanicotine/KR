
#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>


int a, b, n, i, j, ne = 1;
int visited[10] = { 0 }, min, cost[10][10];

void main_menu_pos(char* passive[], char* active[], int amount, int selected) {
	for (int i = 0; i < selected; i++) {
		printf("������������\n");
		printf("%s\n", passive[i]);
		printf("������������\n");
	}
	printf("������������\n");
	printf("%s\n", active[selected]);
	printf("������������\n");

	for (int i = selected + 1; i < amount; i++) {
		printf("������������\n");
		printf("%s\n", passive[i]);
		printf("������������\n");
	}
}
int main()
{
	setlocale(0, "RUS");
	int way[20] = { 0 };
	int index = 0, amount = 4;
	char* passive[4];
	char* active[4];
	for (int i = 0; i < amount; i++) {
		passive[i] = (char*)malloc(sizeof(char) * 50);
		active[i] = (char*)malloc(sizeof(char) * 50);
	}

	strcpy(passive[0], "����");
	strcpy(passive[1], "����");
	strcpy(passive[2], "���");
	strcpy(passive[3], "�����");

	strcpy(active[0], "���");
	strcpy(active[1], "�����");
	strcpy(active[2], "���������");
	strcpy(active[3], "� ��� ����?");

	//MENU
	printf("\n   ������� 1, ����� ������ ������� ���� � ����������\n");
	printf("   ������� 2, ����� �������� ������������� �������\n   ");
	scanf_s("%d", &i);
	if (i == 1) {
		printf("   ������� ���-�� ������: \n");
		scanf_s("%d", &n);
		printf("   ������� ������� ����:  \n");

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				scanf_s("%d", &cost[i][j]);
			}
			printf("\n");
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (cost[i][j] != 0 && i == j) {
					printf("   ���������� 0 �� ������� ���������");
					//getch();
					exit(0);
				}
				if (cost[i][j] < 0) {
					printf("   ����� �������������� ����");
					//getch();
					exit(0);
				}
				if (cost[i][j] != cost[j][i]) {
					printf("   ������� ������������� ������������ ������� ���������");
					//getch();
					exit(0);
				}
			}
		}
	}
	if (i == 2) {
		srand(time(NULL));
		printf("   ������� ���������� ������: ");
		scanf_s("%d", &n);
		printf("\n");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)
				cost[i][j] = rand() % 10;
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				cost[i][j] = cost[j][i];
				if (i == j)
					cost[i][j] = 0;
			}
		}
		for (i = 1; i <= n; i++) {
			printf("  ");
			for (j = 1; j <= n; j++) {
				printf("%2d", cost[i][j]);
			}
			printf("\n");
		}
	}

	//

	visited[1] = 1;

	int sum=0;

	while (ne < n)
	{
		min = INT_MAX;
		for (i = 1; i <= n; i++)
			for (j = i+1; j <= n; j++)
				if (cost[i][j] < min && cost[i][j] != 0 && visited[i] != 0)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}

		if (visited[b] == 0)  // ���� ������� �� ���������� �� 
		{
			way[index] = b;  //������ ������ �������
			index++; // ������� ������� ��� ������
			ne++;
			visited[b] = 1;  //�������� ��� ����������
			sum += min;

		}
		cost[a][b] = cost[b][a] = 0;  // ��������� ����������� ������
	}


	printf("\n");

	printf("   1 �> ");
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", way[i]);
		if (i < n - 2)
			printf("�> ");
	}
	printf(" %d", sum);

	//getch();
}