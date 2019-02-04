// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include "windows.h"
#include<ctime>
#include <conio.h>
using namespace std;

int position_vertical = 7;
int position_horizontal = 6;
int qx, qy, counts = 0;
int mario = 0;
bool bmario = true;
bool hp = true;
bool gh = true;
int scount = 0;

void setcur(int x, int y)//установка курсора на позицию  x y
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void creates(char arr[9][14])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			arr[i][j] = ' ';
		}

	}
}

int randy()
{
	//srand(time_t(0) + rand() % 11 +2 - 1);

	int r = rand() % 22 + 1;
	return r;
}

int findy(char arr[9][14], int a)
{
	int lx;
	if (a == 0) {
		for (int i = 0; i < 14; i++)
			if (arr[0][i] == 'x')
			{
				lx = i; break;
			}
		return lx;
	}
	if (a == 1)
	{
		counts = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 14; j++)
				if (arr[i][j] == 's')
				{
					qx = i;
					qy = j;
					counts++;
				}
	}
	else
		return 0;
}

void player(char arr[9][14])
{
	if (position_vertical >= 2)
	{
		arr[position_vertical][position_horizontal] = '0';
		arr[position_vertical - 1][position_horizontal] = '0';
	}
}
void delplayer(char arr[9][14])
{
	arr[position_vertical][position_horizontal] = ' ';
	arr[position_vertical - 1][position_horizontal] = ' ';
}
void jump(char arr[9][14])
{
	if (mario == 0)
	{
		if (arr[position_vertical + 1][position_horizontal] == ' ')
		{
			delplayer(arr);
			position_vertical++;
			player(arr);
		}
		else
			bmario = true;
	}
	else mario--;

}
void playermove(char arr[9][14], int nn)
{
	if (gh&&hp)
	{
		if (nn == 4)
		{
			if (position_horizontal > 1)
			{
				if (arr[position_vertical][position_horizontal - 1] == ' ')
				{
					delplayer(arr);
					position_horizontal--;
					player(arr);
				}
				if (arr[position_vertical][position_horizontal - 1] == 'S' &&arr[position_vertical][position_horizontal - 2] == ' ')
				{
					arr[position_vertical][position_horizontal - 2] = 'S';
					delplayer(arr);
					position_horizontal--;
					player(arr);
				}
				if (arr[position_vertical][position_horizontal - 1] == 's' &&arr[position_vertical][position_horizontal - 2] == ' ')
				{
					arr[position_vertical][position_horizontal - 2] = 's';
					delplayer(arr);
					position_horizontal--;
					player(arr);
				}

			}gh = false;

		}
		if (nn == 6)
		{
			if (position_horizontal < 12)
			{
				if (arr[position_vertical][position_horizontal + 1] == ' ')
				{

					delplayer(arr);
					position_horizontal++;
					player(arr);
				}
				if (arr[position_vertical][position_horizontal + 1] == 'S' && arr[position_vertical][position_horizontal + 2] == ' ')
				{
					arr[position_vertical][position_horizontal + 2] = 'S';
					delplayer(arr);
					position_horizontal++;
					player(arr);
				}
				if (arr[position_vertical][position_horizontal + 1] == 's' && arr[position_vertical][position_horizontal + 2] == ' ')
				{
					arr[position_vertical][position_horizontal + 2] = 's';
					delplayer(arr);
					position_horizontal++;
					player(arr);
				}

			}gh = false;
		}
		if (nn == 8)
		{
			if (bmario)
			{
				if (position_vertical >= 3)
				{
					if (mario == 0)
					{
						bmario = false;
						mario = 2;
						//jump
						delplayer(arr);
						position_vertical--;
						player(arr);
					}

				}
			}
			gh = false;
		}
		if (nn == 2)
		{
			//afterjump
			if (position_vertical < 7)
			{
				delplayer(arr);
				position_vertical++;
				player(arr);

			}
			gh = false;
		}
	}

}



void after(char arr[9][14], int &cx, int &lx, int &ls, bool &sidex, bool&cang)
{
	cang = false;
	cx = randy();
	lx = findy(arr, 0);
	ls = findy(arr, 1);
	sidex = true;

}

void tostartx(char arr[9][14], bool &xinstart)
{
	int trash = findy(arr, 0);
	if (trash > 1)
	{
		swap(arr[0][trash], arr[0][trash - 1]);
	}
	else
	{
		xinstart = true;
	}
}

void spawns(char arr[9][14])
{
	findy(arr, 1);
	if (counts == 0) {
		int trash2 = findy(arr, 0);
		arr[1][trash2] = ' ';
		arr[1][1] = 's';
	}
}

void create(char arr[9][14])
{
	for (int i = 0; i < 9; i++)
	{
		arr[i][0] = (char)19;
		arr[i][13] = (char)19;
	}
	for (int i = 0; i < 14; i++)
		arr[8][i] = (char)18;
	arr[0][1] = 'x';
	arr[1][1] = 's';
}

void print(char arr[9][14])
{
	//system("cls");
	setcur(0, 0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << "Youre score is: " << scount << endl;
}

void x(char arr[9][14], int &cx, int &lx, int &ls, bool& sidex)
{
	if (lx >= 0 && lx <= 12)
	{
		if (sidex)
		{
			swap(arr[0][lx], arr[0][lx + 1]);
			swap(arr[1][lx], arr[1][lx + 1]);

			lx++;
			if (lx == 12)
				sidex = false;
			cx--;
		}
		else
		{
			swap(arr[0][lx], arr[0][lx - 1]);
			swap(arr[1][lx], arr[1][lx - 1]);
			lx--;;
			cx--;
		}
	}

}
void gfb(char arr[9][14])
{
	for (int j = 0; j < 14; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (arr[i][j] == 'S')
				if (arr[i + 1][j] == ' ')
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = 'S';
				}
		}
	}
}
void g(char arr[9][14], bool&cang, bool &sindown)
{
	{
		if (arr[qx + 1][qy] == ' ')
		{
			swap(arr[qx][qy], arr[qx + 1][qy]);
			sindown = false;
		}
		if (arr[qx + 1][qy] == (char)18 || arr[qx + 1][qy] == 'S')
		{
			arr[qx][qy] = 'S';
			sindown = true;
		}
		if (qx + 1 == position_vertical - 1 && qy == position_horizontal)
		{
			arr[qx][qy] = ' ';
			hp = false;
			sindown = false;
		}
	}

}
void check(char arr[9][14])
{
	int hmm = 0;
	for (int i = 1; i <= 12; i++)
	{
		if (arr[7][i] == 'S')
			hmm++;
	}
	if (hmm == 12)
	{
		for (int i = 1; i <= 12; i++)
			arr[7][i] = ' ';
		scount++;
	}
}
void wait(char arr[9][14], bool&sindown)
{
	if (findy(arr, 0) == 1 && sindown)
	{
		spawns(arr);
	}
}
void end()
{
	cout << endl; cout << endl; cout << endl;
	cout << "\t You was died" << endl;
}
void main()
{
	srand(time(0));
	char arr[9][14];
	creates(arr);
	create(arr);
	int cx = randy();
	int lx = findy(arr, 0);
	int ls = findy(arr, 1);
	bool sidex = true;
	bool xinstart = true;
	bool cang = false;
	bool sindown = false;
	setlocale(0, "");
	int button;
	int mario = 0;
	cout << endl;
	cout << "\tLet's start?" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	system("pause");
	do
	{
		gh = true;
		//Sleep(50);
		//for (int l = 0; l < 20; l++)
		//{

		if (_kbhit())
		{

			button = _getch();
			if (button == 75)
				playermove(arr, 4);
			if (button == 77)
				playermove(arr, 6);
			if (button == 72)
				playermove(arr, 8);
			if (button == 80)
				playermove(arr, 2);
		}
		print(arr);
		//}
		player(arr);
		if (cx <= 0)
		{
			xinstart = false;
			findy(arr, 1);
			tostartx(arr, xinstart);
			if (xinstart&&sindown)
				after(arr, cx, lx, ls, sidex, cang);
			if (cx == 0)
				cang = true;
			if (cx != 0)
				cang = false;
			if (cang)
				g(arr, cang, sindown);
		}
		else
		{
			x(arr, cx, lx, ls, sidex);
		}
		check(arr);
		gfb(arr);
		jump(arr);
		wait(arr, sindown);

		print(arr);
		if (hp == false)
			end();
		Sleep(130);
	} while (1);
}









