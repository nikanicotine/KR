
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
		printf("覧覧覧覧覧覧\n");
		printf("%s\n", passive[i]);
		printf("覧覧覧覧覧覧\n");
	}
	printf("覧覧覧覧覧覧\n");
	printf("%s\n", active[selected]);
	printf("覧覧覧覧覧覧\n");

	for (int i = selected + 1; i < amount; i++) {
		printf("覧覧覧覧覧覧\n");
		printf("%s\n", passive[i]);
		printf("覧覧覧覧覧覧\n");
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

	strcpy(passive[0], "硴褊");
	strcpy(passive[1], "硴竟");
	strcpy(passive[2], "硴�");
	strcpy(passive[3], "硴���");

	strcpy(active[0], "���");
	strcpy(active[1], "�韈萵");
	strcpy(active[2], "���粽��萵");
	strcpy(active[3], "� ��� ��萵?");

	//MENU
	printf("\n   ﾍ琥�頸� 1, ���磊 粐褥�� �瑣�頽� 粢�� � ��珞鞨����\n");
	printf("   ﾍ琥�頸� 2, ���磊 ����琺�� �肄�褞頏�籵�� �瑣�頽�\n   ");
	scanf_s("%d", &i);
	if (i == 1) {
		printf("   ﾂ粢蒻�� ���-粽 粢��竟: \n");
		scanf_s("%d", &n);
		printf("   ﾂ粢蒻�� �瑣�頽� 粢��:  \n");

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				scanf_s("%d", &cost[i][j]);
			}
			printf("\n");
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (cost[i][j] != 0 && i == j) {
					printf("   ﾑ�蒟�跖��� 0 �� 肭珞��� 蒻璢��琿�");
					//getch();
					exit(0);
				}
				if (cost[i][j] < 0) {
					printf("   ﾐ裔�� ���頽瑣褄���胛 粢��");
					//getch();
					exit(0);
				}
				if (cost[i][j] != cost[j][i]) {
					printf("   ﾌ瑣�頽� �褥韲�褪�顆�� �����頸褄��� 肭珞��� 蒻璢��琿�");
					//getch();
					exit(0);
				}
			}
		}
	}
	if (i == 2) {
		srand(time(NULL));
		printf("   ﾂ粢蒻�� ���顆褥�粽 粢��竟: ");
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

		if (visited[b] == 0)  // 褥�� 粢��竟� �� ���襌琿瑰� �� 
		{
			way[index] = b;  //鈞�頌� ���褞� 粢��竟�
			index++; // ��襌瑯� ��鉅��� 蓁� 鈞�頌�
			ne++;
			visited[b] = 1;  //���褪頸� �瑕 ���襌褊���
			sum += min;

		}
		cost[a][b] = cost[b][a] = 0;  // �硼��褊韃 ���粢�褊��� 粢��竟
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