#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <mmsystem.h>
#include <iostream>
#include <cstdlib>

using namespace std;

void Gra(int &jakiLevel, bool poczatek, int &lives, int &points);
void Exit();
void Help();
void Credits();
void Menu();
void WybierzPoziom();

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
	ShowConsoleCursor(false);
	srand(time(NULL));
	Menu();
	return 0;
}

#pragma region Klasy

class Frog {

public:

	char frogChar = 2;
	int xPositionFrog = 5;
	int yPositionFrog = 10;

	void ShowFrog()
	{
		cout << frogChar;
	}
};

class Car {

public:

	char carChar = 223;
	bool left = false;
	bool jedz = false;
	bool up = false;
	int xPositionCar, yPositionCar;
	char tab[12][12];

	Car(char tab[12][12], int x = 1, int y = 9, bool l = false, bool u = false)
	{
		xPositionCar = x;
		yPositionCar = y;
		left = l;
		up = u;
	}

	void Go(char tab[12][12])
	{
		if (xPositionCar == 10 && left == false && up == false)
		{
			tab[yPositionCar][xPositionCar] = 0;
			xPositionCar = 1, yPositionCar = 9;
			yPositionCar = rand() % (10 - 8) + 8;
			jedz = false;
		}

		if (xPositionCar == 1 & left == true && up == false)
		{
			tab[yPositionCar][xPositionCar] = 0;
			xPositionCar = 10, yPositionCar = 9;
			yPositionCar = rand() % (8 - 6) + 6;
			jedz = false;
		}

		if (xPositionCar == 1 & left == true && up == true)
		{
			tab[yPositionCar][xPositionCar] = 0;
			xPositionCar = 10, yPositionCar = 3;
			yPositionCar = rand() % (5 - 3) + 3;
			jedz = false;
		}

		if (jedz == false)
		{
			tab[yPositionCar][xPositionCar] = carChar;
		}

		if (xPositionCar <= 9 && left == false && jedz == true)
		{
			xPositionCar++;
			tab[yPositionCar][xPositionCar] = carChar;
			tab[yPositionCar][xPositionCar - 1] = 0;
		}

		if (xPositionCar >= 1 && left == true && jedz == true)
		{
			xPositionCar--;
			tab[yPositionCar][xPositionCar] = carChar;
			tab[yPositionCar][xPositionCar + 1] = 0;
		}
	}
};

class Snake 
{
public:

	char carChar = 126;
	int xPositionCar;
	int yPositionCar;
	bool left = false;
	bool jedz = false;
	char tab[12][12];

	Snake(char tab[12][12], int x = 1, int y = 9, bool l = false)
	{
		xPositionCar = x;
		yPositionCar = y;
		left = l;
	}

	void Go(char tab[12][12])
	{
		if (xPositionCar <= 9 && left == false && jedz == true)
		{
			xPositionCar++;
			tab[yPositionCar][xPositionCar] = carChar;
			tab[yPositionCar][xPositionCar - 1] = 177;
		}

		if (xPositionCar >= 1 && left == true && jedz == true)
		{
			xPositionCar--;
			tab[yPositionCar][xPositionCar] = carChar;
			tab[yPositionCar][xPositionCar + 1] = 177;
		}

		if (xPositionCar == 1)
		{
			tab[yPositionCar][xPositionCar] = 177;
			int lewy = rand() % 2;
			int gora = rand() % 2;

			if (lewy == 0)
			{
				left = false;
				xPositionCar = 10;
			}
			if (gora == 1)
			{
				yPositionCar = 5;
			}
			else
			{
				yPositionCar = 10;
			}
		}

		if (jedz == false)
		{
			tab[yPositionCar][xPositionCar] = carChar;
		}

		if (xPositionCar == 10)
		{
			tab[yPositionCar][xPositionCar] = 177;
			int lewy = rand() % 2;
			int gora = rand() % 2;

			if (lewy == 0)
			{
				left = false;
				xPositionCar = 1;
			}

			if (gora == 1)
			{
				yPositionCar = 5;
			}
			else
			{
				yPositionCar = 10;
			}
		}
	}
};

class Boat
{
public:

	char boatChar = 61;

	bool left = false;
	bool jedz = false;
	bool up = false;
	int xPositionBoat, yPositionBoat;
	char tab[12][12];

	Boat(char tab[12][12], int x = 1, int y = 4, bool l = false, bool u = false)
	{
		xPositionBoat = x;
		yPositionBoat = y;
		left = l;
		up = u;
	}

public: void Go(char tab[12][12])
{
	if (xPositionBoat == 10 && left == false && up == false)
	{
		tab[yPositionBoat][xPositionBoat] = 176;
		xPositionBoat = 1, yPositionBoat = 4;
		jedz = false;
	}

	if (xPositionBoat == 10 && left == false && up == true)
	{
		tab[yPositionBoat][xPositionBoat] = 176;
		xPositionBoat = 1, yPositionBoat = 2;
		jedz = false;
	}

	if (xPositionBoat == 1 & left == true)
	{
		tab[yPositionBoat][xPositionBoat] = 176;
		xPositionBoat = 10, yPositionBoat = 3;
		jedz = false;
	}

	if (jedz == false)
	{
		tab[yPositionBoat][xPositionBoat] = boatChar;
	}

	if (xPositionBoat <= 9 && left == false && jedz == true)
	{
		xPositionBoat++;
		tab[yPositionBoat][xPositionBoat] = boatChar;
		tab[yPositionBoat][xPositionBoat - 1] = 176;
	}

	if (xPositionBoat >= 1 && left == true && jedz == true)
	{
		xPositionBoat--;
		tab[yPositionBoat][xPositionBoat] = boatChar;
		tab[yPositionBoat][xPositionBoat + 1] = 176;
	}
}
};

#pragma endregion

void TworzeniePlanszy(int jakiLevel, char tab[12][12])
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i <= 11; i++)
		for (int j = 0; j <= 11; j++)
		{
			tab[i][j] = 0;
		}

	for (int i = 0; i <= 11; i++)
	{
		tab[0][i] = 219;
	}
	for (int i = 0; i <= 11; i++)
	{
		tab[11][i] = 219;
	}
	for (int i = 0; i <= 11; i++)
	{
		tab[i][0] = 219;
	}
	for (int i = 0; i <= 11; i++)
	{
		tab[i][11] = 219;
	}
	tab[1][2] = 219;
	tab[1][4] = 219;
	tab[1][6] = 219;
	tab[1][8] = 219;
	tab[1][10] = 219;

	if (jakiLevel != 1)
	{
		for (int i = 2; i <= 4; i++)
			for (int j = 1; j <= 10; j++)
			{
				tab[i][j] = 176;
			}
	}

	for (int j = 1; j <= 10; j++)
	{
		tab[10][j] = 177;
	}
	for (int j = 1; j <= 10; j++)
	{
		tab[5][j] = 177;
	}
}

void PokazPlansze(int &lives, int &points, char tab[12][12])
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char frogChar = 2;

	for (int i = 0; i <= 11; i++)
	{
		cout << endl;
		for (int j = 0; j <= 11; j++)
		{
			if (tab[i][j] == -80)//Water
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << tab[i][j];
				continue;
			}

			if (tab[i][j] == -79)//Save
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << tab[i][j];
				continue;
			}

			if (tab[i][j] == 240)//Boat
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << tab[i][j];
				continue;
			}

			if (tab[i][j] == 2)//Frog
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << tab[i][j];
				continue;
			}

			if (tab[i][j] == -33 || tab[i][j] == 126)//Car
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << tab[i][j];
				continue;
			}
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			cout << tab[i][j];
		}
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	char water = 219;
	if (tab[1][1] != 2)
	{
		gotoxy(2, 3);
		cout << water;
	}
	if (tab[1][3] != 2)
	{
		gotoxy(4, 3);
		cout << water;
	}
	if (tab[1][5] != 2)
	{
		gotoxy(6, 3);
		cout << water;
	}
	if (tab[1][7] != 2)
	{
		gotoxy(8, 3);
		cout << water;
	}
	if (tab[1][9] != 2)
	{
		gotoxy(10, 3);
		cout << water;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	gotoxy(1, 13);
	cout << endl;
	if (lives == 3)
	{
		cout << "\nPozostale szanse: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << frogChar << frogChar << frogChar;
	}
	else if (lives == 2)
	{
		cout << "\nPozostale szanse: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << frogChar << frogChar;
	}
	else if (lives == 1)
	{
		cout << "\nPozostale szanse: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << frogChar;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "\nPunkty: " << points;
	cout << endl << endl;
}

void Menu()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int position = 1;
	char arrow = 24;
	int znak = NULL;
	char empty = 0;
	bool poczatek = true;
	system("cls");
	sndPlaySound(TEXT("FroggerMenu.wav"), SND_ASYNC);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << "\t######## ########   #######   ######    ######   ######## ########  " << endl;
	cout << "\t##       ##     ## ##     ## ##    ##  ##    ##  ##       ##     ## " << endl;
	cout << "\t##       ##     ## ##     ## ##        ##        ##       ##     ## " << endl;
	cout << "\t######   ########  ##     ## ##   #### ##   #### ######   ########  " << endl;
	cout << "\t##       ##   ##   ##     ## ##    ##  ##    ##  ##       ##   ##   " << endl;
	cout << "\t##       ##    ##  ##     ## ##    ##  ##    ##  ##       ##    ##  " << endl;
	cout << "\t##       ##     ##  #######   ######    ######   ######## ##     ## " << endl << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "\t    Nowa gra";
	cout << "         Pomoc";
	cout << "\t      Autorzy";
	cout << "\t      Wyjscie";

	if (poczatek == true)
	{
		gotoxy(17, 12); cout << arrow;
	}

	while (true)
	{
		znak = _getch();

		switch (znak)
		{
		case 100: //d
		{
			poczatek = false;

			if (position == 1)
			{
				position++;
				gotoxy(32, 12); cout << arrow;
				gotoxy(17, 12); cout << empty;
				break;
			}
			else if (position == 2)
			{
				position++;
				gotoxy(50, 12); cout << arrow;
				gotoxy(32, 12); cout << empty;
				break;
			}
			else if (position == 3)
			{
				position++;
				gotoxy(66, 12); cout << arrow;
				gotoxy(50, 12); cout << empty;
				break;
			}
			else if (position == 4)
			{
				position = 1;
				gotoxy(17, 12); cout << arrow;
				gotoxy(66, 12); cout << empty;
				break;
			}
		}
		case 97://a
		{
			poczatek = false;
			if (position == 1)
			{
				position = 4;
				gotoxy(66, 12); cout << arrow;
				gotoxy(17, 12); cout << empty;
				break;
			}

			else if (position == 2)
			{
				position--;
				gotoxy(17, 12); cout << arrow;
				gotoxy(32, 12); cout << empty;
				break;
			}

			else if (position == 3)
			{
				position--;
				gotoxy(32, 12); cout << arrow;
				gotoxy(50, 12); cout << empty;
				break;
			}
			else if (position == 4)
			{
				position--;
				gotoxy(50, 12); cout << arrow;
				gotoxy(66, 12); cout << empty;
				break;
			}
		}

		case 13:
		{
			poczatek = false;
			if (position == 1)
			{
				WybierzPoziom();
			}
			else if (position == 2)
			{
				Help();
				break;
			}
			else if (position == 3)
			{
				Credits();
				break;
			}
			else if (position == 4)
			{
				Exit();
				break;
			}
		}
		}
	}
}

void WybierzPoziom()
{
	int lives = 3;
	int points = 0;
	bool poczatek = true;
	int jakiLevel = 1;
	int position = 1;
	char arrow = 27;
	int znak = 0;
	char empty = 0;
	bool poczatekWyboru = true;
	system("cls");
	cout << "Wybierz poziom \n\n";
	cout << "Poziom 1\n";
	cout << "Poziom 2\n";
	cout << "Poziom 3\n";
	if (poczatekWyboru == true)
	{
		gotoxy(10, 3); cout << arrow;
	}

	while (true)
	{
		znak = _getch();

		switch (znak)
		{
		case 115: //s
		{
			poczatekWyboru = false;

			if (position == 1)
			{
				position++;
				gotoxy(10, 4); cout << arrow;
				gotoxy(10, 3); cout << empty;
				break;
			}

			else if (position == 2)
			{
				position++;
				gotoxy(10, 5); cout << arrow;
				gotoxy(10, 4); cout << empty;
				break;
			}

			else if (position == 3)
			{
				position = 1;
				gotoxy(10, 3); cout << arrow;
				gotoxy(10, 5); cout << empty;
				break;
			}
		}

		case 119://w
		{
			poczatekWyboru = false;
			if (position == 1)
			{
				position = 3;
				gotoxy(10, 5); cout << arrow;
				gotoxy(10, 3); cout << empty;
				break;
			}

			else if (position == 2)
			{
				position--;
				gotoxy(10, 3); cout << arrow;
				gotoxy(10, 4); cout << empty;
				break;
			}

			else if (position == 3)
			{
				position--;
				gotoxy(10, 4); cout << arrow;
				gotoxy(10, 5); cout << empty;
				break;
			}
		}

		case 13:
		{
			poczatekWyboru = false;
			if (position == 1)
			{
				jakiLevel = 1;
				//TworzeniePlanszy(jakiLevel);
				lives = 3, points = 0;
				poczatek = true;
				Gra(jakiLevel, poczatek, lives, points);
				break;
			}
			else if (position == 2)
			{
				jakiLevel = 2;
				//TworzeniePlanszy(jakiLevel);
				lives = 3, points = 0;
				poczatek = true;
				Gra(jakiLevel, poczatek, lives, points);
				break;
			}
			else if (position == 3)
			{
				jakiLevel = 3;
				//TworzeniePlanszy(jakiLevel);
				lives = 3, points = 0;
				poczatek = true;
				Gra(jakiLevel, poczatek, lives, points);
				break;
			}
		}
		}
	}
}

void Help()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char frog = 2;
	char car = 223;
	char boat = 61;
	char snake = 126;
	char water = 176;
	char leaf = 219;
	char safe = 178;
	system("cls");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << frog;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << " To ty. Twoim zadaniem jest dostac sie na lisc ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << leaf;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << endl;
	cout << "Uwazaj na samochody ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << car;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << " oraz na to by nie wpasc do rzeki ";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << water;
	cout << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "Rzeke mozesz pokonac za pomoca lodzi ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << boat;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << endl;
	cout << "Na chodniku ";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << safe;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << " jestes w miare bezpieczny, ale musisz uwazac na weze ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << snake;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "\n\n\nSterowanie:\n\n W - Ruch do gory\n S - Ruch w dol\n A - Ruch w lewo\n D - Ruch w prawo\n\n";
	cout << "Nacisnij dowolny klawisz by wrocic";
	_getch();
	Menu();
}

void Credits()
{
	system("cls");
	cout << "Autorzy: \n";
	cout << "Marcin Owczarz\nSzymon Dyrcz";
	cout << "\n\nNacisnij dowolny klawisz by wrocic";
	_getch();
	Menu();
}

void Exit()
{
	exit(1);
}

void Gra(int &jakiLevel, bool poczatek, int &lives, int &points)
{
	char tab[12][12];

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	sndPlaySound(TEXT("Jump.wav"), SND_ASYNC);
	Frog frog;
	int znak = 0;

	Car *wskCar[7];
	wskCar[0] = new Car(tab, 1, 9);
	wskCar[1] = new Car(tab, 7, 8);
	wskCar[2] = new Car(tab, 1, 7, true);
	wskCar[3] = new Car(tab, 7, 6, true);
	wskCar[4] = new Car(tab, 5, 4, true, true);
	wskCar[5] = new Car(tab, 2, 3, true, true);
	wskCar[6] = new Car(tab, 9, 3, true, true);

	Boat *wskBoat[6];
	wskBoat[0] = new Boat(tab, 1, 4);
	wskBoat[1] = new Boat(tab, 7, 4);
	wskBoat[2] = new Boat(tab, 3, 2, false, true);
	wskBoat[3] = new Boat(tab, 9, 2, false, true);
	wskBoat[4] = new Boat(tab, 2, 3, true);
	wskBoat[5] = new Boat(tab, 8, 3, true);

	Snake *wskSnake;
	wskSnake = new Snake(tab, 5, 5);

	TworzeniePlanszy(jakiLevel, tab);
	PokazPlansze(lives, points, tab);

	while (true)
	{
		znak = 0;

		if (frog.yPositionFrog == 1)//Zdobycie punktu
		{
			sndPlaySound(TEXT("Point.wav"), SND_ASYNC);
			tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			gotoxy(frog.xPositionFrog + 1, frog.yPositionFrog + 2);
			frog.ShowFrog();
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			Sleep(500);
			frog.yPositionFrog = 10;
			frog.xPositionFrog = 5;
			tab[10][5] = frog.frogChar;
			points++;
			system("cls");
			PokazPlansze(lives, points, tab);
		}

		if (jakiLevel == 2 || jakiLevel == 3)
		{

			if (frog.yPositionFrog < 5 && frog.yPositionFrog>1)//Wpadnienie do wody
				if (frog.xPositionFrog == wskBoat[0]->xPositionBoat && frog.yPositionFrog == wskBoat[0]->yPositionBoat || frog.xPositionFrog == wskBoat[1]->xPositionBoat && frog.yPositionFrog == wskBoat[1]->yPositionBoat || frog.xPositionFrog == wskBoat[2]->xPositionBoat && frog.yPositionFrog == wskBoat[2]->yPositionBoat || frog.xPositionFrog == wskBoat[3]->xPositionBoat && frog.yPositionFrog == wskBoat[3]->yPositionBoat || frog.xPositionFrog == wskBoat[4]->xPositionBoat && frog.yPositionFrog == wskBoat[4]->yPositionBoat || frog.xPositionFrog == wskBoat[5]->xPositionBoat && frog.yPositionFrog == wskBoat[5]->yPositionBoat)
				{
					//Nie rób nic
				}
				else
				{
					sndPlaySound(TEXT("Plunk.wav"), SND_ASYNC);
					poczatek = true;
					gotoxy(frog.xPositionFrog + 1, frog.yPositionFrog + 2);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					frog.ShowFrog();
					Sleep(700);
					tab[frog.yPositionFrog][frog.xPositionFrog] = 176;
					frog.xPositionFrog = 5;
					frog.yPositionFrog = 10;
					tab[10][5] = 2;//Ustawienie froggera na start;
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					PokazPlansze(lives, points, tab);
					lives--;
				}
		}

		if (tab[1][1] == frog.frogChar && tab[1][3] == frog.frogChar && tab[1][5] == frog.frogChar && tab[1][7] == frog.frogChar && tab[1][9] == frog.frogChar)
		{					//Level ukoñczony
			jakiLevel++;
			if (jakiLevel == 4)
			{
				frog.xPositionFrog = 5;
				frog.yPositionFrog = 10;
				poczatek = true;
				Sleep(1000);
				system("cls");
				cout << "Lvl complete! ";
				Sleep(2000);
				system("cls");
				sndPlaySound(TEXT("Point.wav"), SND_ASYNC);
				cout << "Gra ukonczona! Zdobyles " << points << " punktow!";
				Sleep(3000);
				system("cls");
				//delete[] wskCar;
				//delete[] wskBoat;
				delete wskSnake;
				Menu();
			}
			else
			{
				frog.xPositionFrog = 5;
				frog.yPositionFrog = 10;
				poczatek = true;
				Sleep(1000);
				system("cls");
				cout << "Lvl complete! ";
				Sleep(2000);
				system("cls");
				if (jakiLevel == 2)
				{
					cout << "Lvl 2";
				}
				if (jakiLevel == 3)
				{
					cout << "Lvl 3";
				}
				Sleep(2000);
				system("cls");
				TworzeniePlanszy(jakiLevel, tab);
				PokazPlansze(lives, points, tab);
				//delete[] wskCar;
				//delete[] wskBoat;
				delete wskSnake;
				Gra(jakiLevel, poczatek, lives, points);
			}
		}

		if (poczatek)
		{
			tab[10][5] = 2;//Ustawienie froggera na start;
		}

		if ((frog.xPositionFrog == wskCar[0]->xPositionCar && frog.yPositionFrog == wskCar[0]->yPositionCar) || (frog.xPositionFrog == wskCar[1]->xPositionCar && frog.yPositionFrog == wskCar[1]->yPositionCar) || (frog.xPositionFrog == wskCar[2]->xPositionCar && frog.yPositionFrog == wskCar[2]->yPositionCar) || (frog.xPositionFrog == wskCar[3]->xPositionCar && frog.yPositionFrog == wskCar[3]->yPositionCar) || (frog.xPositionFrog == wskCar[4]->xPositionCar && frog.yPositionFrog == wskCar[4]->yPositionCar) || (frog.xPositionFrog == wskCar[5]->xPositionCar && frog.yPositionFrog == wskCar[5]->yPositionCar) || (frog.xPositionFrog == wskCar[6]->xPositionCar && frog.yPositionFrog == wskCar[6]->yPositionCar) || frog.xPositionFrog == wskSnake->xPositionCar && frog.yPositionFrog == wskSnake->yPositionCar)//Zderzenie
		{			//Kolizje
			sndPlaySound(TEXT("Squash.wav"), SND_ASYNC);
			poczatek = true;
			gotoxy(frog.xPositionFrog + 1, frog.yPositionFrog + 2);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			frog.ShowFrog();
			Sleep(700);
			frog.xPositionFrog = 5;
			frog.yPositionFrog = 10;
			tab[10][5] = 2;//Ustawienie froggera na start;
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			PokazPlansze(lives, points, tab);
			lives--;
		}

		if (frog.xPositionFrog == wskBoat[0]->xPositionBoat && frog.yPositionFrog == wskBoat[0]->yPositionBoat)
		{//P³ywanie po ³ódkach
			if (frog.xPositionFrog == 10)
			{
				frog.xPositionFrog = 1;
			}
			else if (frog.yPositionFrog == 4 || frog.yPositionFrog == 2)
			{
				frog.xPositionFrog = wskBoat[0]->xPositionBoat + 1;
				frog.yPositionFrog = wskBoat[0]->yPositionBoat;
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				wskBoat[0]->boatChar = frog.frogChar;
			}
			else if (frog.yPositionFrog == 3)
			{
				frog.xPositionFrog = wskBoat[0]->xPositionBoat - 1;
				frog.yPositionFrog = wskBoat[0]->yPositionBoat;
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				wskBoat[0]->boatChar = frog.frogChar;
			}
		}
		else
		{
			wskBoat[0]->boatChar = 61;
		}

		if (frog.xPositionFrog == wskBoat[1]->xPositionBoat && frog.yPositionFrog == wskBoat[1]->yPositionBoat)
		{
			if (frog.xPositionFrog == 10)
			{
				frog.xPositionFrog = 1;
			}
			else
			{
				frog.xPositionFrog = wskBoat[1]->xPositionBoat + 1;
				frog.yPositionFrog = wskBoat[1]->yPositionBoat;
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				wskBoat[1]->boatChar = frog.frogChar;
			}
		}
		else
		{
			wskBoat[1]->boatChar = 61;
		}

		if (frog.xPositionFrog == wskBoat[2]->xPositionBoat && frog.yPositionFrog == wskBoat[2]->yPositionBoat)
		{
			if (frog.xPositionFrog == 10)
			{
				frog.xPositionFrog = 1;
			}
			else
			{
				frog.xPositionFrog = wskBoat[2]->xPositionBoat + 1;
				frog.yPositionFrog = wskBoat[2]->yPositionBoat;
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				wskBoat[2]->boatChar = frog.frogChar;
			}
		}
		else
		{
			wskBoat[2]->boatChar = 61;
		}

		if (frog.xPositionFrog == wskBoat[3]->xPositionBoat && frog.yPositionFrog == wskBoat[3]->yPositionBoat)
		{
			if (frog.xPositionFrog == 10)
			{
				frog.xPositionFrog = 1;
			}
			else
			{
				frog.xPositionFrog = wskBoat[3]->xPositionBoat + 1;
				frog.yPositionFrog = wskBoat[3]->yPositionBoat;
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				wskBoat[3]->boatChar = frog.frogChar;
			}
		}
		else
		{
			wskBoat[3]->boatChar = 61;
		}

		if (frog.xPositionFrog == wskBoat[4]->xPositionBoat && frog.yPositionFrog == wskBoat[4]->yPositionBoat)
		{
			if (frog.xPositionFrog == 1)
			{
				frog.xPositionFrog = 10;
			}
			else
			{
				frog.xPositionFrog = wskBoat[4]->xPositionBoat - 1;
				frog.yPositionFrog = wskBoat[4]->yPositionBoat;
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				wskBoat[4]->boatChar = frog.frogChar;
			}
		}
		else
		{
			wskBoat[4]->boatChar = 61;
		}

		if (frog.xPositionFrog == wskBoat[5]->xPositionBoat && frog.yPositionFrog == wskBoat[5]->yPositionBoat)
		{
			if (frog.xPositionFrog == 1)
			{
				frog.xPositionFrog = 10;
			}
			else
			{
				frog.xPositionFrog = wskBoat[5]->xPositionBoat - 1;
				frog.yPositionFrog = wskBoat[5]->yPositionBoat;
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				wskBoat[5]->boatChar = frog.frogChar;
			}
		}
		else
		{
			wskBoat[5]->boatChar = 61;
		}

		if (lives <= 0)//Koniec gry
		{
			Sleep(1000);
			system("cls");
			sndPlaySound(TEXT("Time.wav"), SND_ASYNC);
			cout << "Koniec gry! Zdobyles " << points << " punkty";
			Sleep(3000);
			//delete[] wskCar;
			//delete[] wskBoat;
			delete wskSnake;
			Menu();
		}

		Sleep(100); //G³ówny licznik gry

		for (int i = 0; i <= 3; i++)
		{
			wskCar[i]->Go(tab);
			wskCar[i]->jedz = true;
		}

		if (jakiLevel == 1)
		{
			for (int i = 4; i <= 6; i++)
			{
				wskCar[i]->Go(tab);
				wskCar[i]->jedz = true;
			}
		}

		else
		{
			for (int i = 4; i <= 6; i++)
			{
				wskCar[i]->xPositionCar = 0;
				wskCar[i]->yPositionCar = 0;
			}
		}

		if (jakiLevel == 2 || jakiLevel == 3)
		{
			for (int i = 0; i <= 5; i++)
			{
				wskBoat[i]->Go(tab);
				wskBoat[i]->jedz = true;
			}
		}
		else
		{
			for (int i = 0; i <= 5; i++)
			{
				wskBoat[i]->xPositionBoat = 0;
			}
		}

		if (jakiLevel == 3)
		{
			wskSnake->Go(tab);
			wskSnake->jedz = true;
		}
		else
		{
			wskSnake->xPositionCar = 0;
			wskSnake->yPositionCar = 0;
		}

		if (_kbhit())//Sterowanie
		{
			znak = _getch();

			switch (znak)
			{
			case 'w':
			{
				if (frog.yPositionFrog > 1)
				{
					if ((frog.xPositionFrog == 2 && frog.yPositionFrog == 2) || (frog.xPositionFrog == 4 && frog.yPositionFrog == 2) || (frog.xPositionFrog == 6 && frog.yPositionFrog == 2) || (frog.xPositionFrog == 8 && frog.yPositionFrog == 2) || (frog.xPositionFrog == 10 && frog.yPositionFrog == 2))
					{
						break;
					}

					if ((frog.xPositionFrog == 1 && frog.yPositionFrog == 2 && tab[1][1] == 2) || (frog.xPositionFrog == 3 && frog.yPositionFrog == 2 && tab[1][3] == 2) || (frog.xPositionFrog == 5 && frog.yPositionFrog == 2 && tab[1][5] == 2) || (frog.xPositionFrog == 7 && frog.yPositionFrog == 2 && tab[1][7] == 2) || (frog.xPositionFrog == 9 && frog.yPositionFrog == 2 && tab[1][9] == 2))
					{
						break;
					}

					sndPlaySound(TEXT("Jump.wav"), SND_ASYNC);
					if (frog.yPositionFrog == 4 && jakiLevel != 1)
					{
						frog.yPositionFrog--;
						frog.xPositionFrog--;
						tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
						system("cls");
						PokazPlansze(lives, points, tab);
						break;
					}

					if (frog.yPositionFrog == 3 && jakiLevel != 1)
					{
						frog.yPositionFrog--;
						frog.xPositionFrog++;
						tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
						system("cls");
						PokazPlansze(lives, points, tab);
						break;
					}

					frog.yPositionFrog--;
					tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;

					if (poczatek == false)
					{
						tab[frog.yPositionFrog + 1][frog.xPositionFrog] = 0;
					}
					else if (poczatek == true)
					{
						tab[10][5] = 0;
					}

					if (frog.yPositionFrog == 9 || frog.yPositionFrog == 4)
					{
						tab[frog.yPositionFrog + 1][frog.xPositionFrog] = 177;
					}

					poczatek = false;
					system("cls");
					PokazPlansze(lives, points, tab);
					break;
				}
				else
					break;

			}

			case 's':
			{
				if (frog.yPositionFrog < 10)
				{
					sndPlaySound(TEXT("Jump.wav"), SND_ASYNC);

					frog.yPositionFrog++;
					tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;

					if (poczatek == false)
					{
						tab[frog.yPositionFrog - 1][frog.xPositionFrog] = 0;
					}
					else if (poczatek == true)
					{
						tab[10][5] = 0;
					}

					if (frog.yPositionFrog == 9 || frog.yPositionFrog == 6)
					{
						tab[frog.yPositionFrog - 1][frog.xPositionFrog] = 177;
					}

					poczatek = false;
					system("cls");
					PokazPlansze(lives, points, tab);
					break;
				}
				else
					break;
			}

			case 'a':
			{
				if (frog.xPositionFrog > 1)
				{
					sndPlaySound(TEXT("Jump.wav"), SND_ASYNC);
					frog.xPositionFrog--;
					tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;

					if (poczatek == false)
					{
						tab[frog.yPositionFrog][frog.xPositionFrog + 1] = 0;
					}
					else if (poczatek == true)
					{
						tab[10][5] = 0;
					}

					if (frog.yPositionFrog == 10 || frog.yPositionFrog == 5)
					{
						tab[frog.yPositionFrog][frog.xPositionFrog + 1] = 177;
					}

					poczatek = false;
					system("cls");
					PokazPlansze(lives, points, tab);
					break;
				}
				else
					break;
			}

			case 'd':
			{
				if (frog.xPositionFrog < 10)
				{
					sndPlaySound(TEXT("Jump.wav"), SND_ASYNC);
					frog.xPositionFrog++;
					tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;

					if (poczatek == false)
					{
						tab[frog.yPositionFrog][frog.xPositionFrog - 1] = 0;
					}
					else if (poczatek == true)
					{
						tab[10][5] = 0;
					}

					if (frog.yPositionFrog == 10 || frog.yPositionFrog == 5)
					{
						tab[frog.yPositionFrog][frog.xPositionFrog - 1] = 177;
					}

					poczatek = false;
					system("cls");
					PokazPlansze(lives, points, tab);
					break;
				}
				else
					break;
			}
			case 27:
			{
				//delete[] wskCar;
				//delete[] wskBoat;
				delete wskSnake;
				Menu();
			}
			default:
			{
				tab[frog.yPositionFrog][frog.xPositionFrog] = frog.frogChar;
				poczatek = false;
				system("cls");
				PokazPlansze(lives, points, tab);
				break;
			}
			}
		}
		else
		{
			system("cls");
			PokazPlansze(lives, points, tab);
		}
	}
}