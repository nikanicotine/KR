#pragma once
#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void menu() {
	system("cls");
	i = 1;
	main_menu_pos();
	char klav;
	do {
		klav = _getch();
		if (klav == 80) {
			i++;
			switch (i) {
			case 10:
				i = 1;
				main_menu_pos();
				break;
			default:
				main_menu_pos();
			}
		}
		if (klav == 72) {
			i--;
			switch (i) {
			case 0:
				i = 9;
				main_menu_pos();
				break;
			default:
				main_menu_pos();
			}
		}

	} while (klav != 13);
}
