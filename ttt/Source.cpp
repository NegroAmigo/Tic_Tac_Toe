#include "Header.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

HANDLE hout;
COORD c = { 33,7 };
CONSOLE_CURSOR_INFO ci;
int field[13][13];
int game[3][3] = { 0 };

int curX = 0;
int curY = 0;
bool flag = true;
int winner = 0;
int counter = 0;
int x;

void Bot(int priority)
{
	COORD move[3][3] = { {{35,9}, {39,9}, {43,9}}, {{35,13}, {39,13}, {43,13}}, {{35,17}, {39,17}, {43,17}} };

	for (int i = 0; i < 3; i++)
	{
		if ((game[0][i] == priority && game[1][i] == priority) || (game[1][i] == priority && game[2][i] == priority) || (game[0][i] == priority && game[2][i] == priority))
		{
			for (int j = 0; j < 3; j++)
			{
				if (game[j][i]==0)
				{
					game[j][i] = 2;
					SetConsoleCursorPosition(hout, move[j][i]);
					cout << "O";
					counter++;
					return;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if ((game[i][0] == priority && game[i][1] == priority) || (game[i][1] == priority && game[i][2] == priority) || (game[i][0] == priority && game[i][2] == priority))
		{
			for (int j = 0; j < 3; j++)
			{
				if (game[i][j] == 0)
				{
					game[i][j] = 2;
					SetConsoleCursorPosition(hout, move[i][j]);
					cout << "O";
					counter++;
					return;
				}
			}
		}
	}

	if ((game[0][0] == priority && game[1][1] == priority) || (game[1][1] == priority && game[2][2] == priority) || (game[0][0] == priority && game[2][2] == priority))
	{
		for (int i = 0; i < 3; i++)
		{
			if (game[i][i] == 0)
			{
				game[i][i] = 2;
				SetConsoleCursorPosition(hout, move[i][i]);
				cout << "0";
				counter++;
				return;
			}
		}
	}
		
	if ( game[0][2] == game[1][1] == priority || game[1][1] == game[2][0] == priority || game[0][2] == game[2][0] == priority)
	{
		for (int i = 0; i < 3; i++)
		{
			if (game[i][i] == 0)
			{
				game[i][i] = 2;
				SetConsoleCursorPosition(hout, move[i][i]);
				cout << "0";
				counter++;
				return;
			}
		}
	}

	if (priority == 2) Bot(1);
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (game[i][j] == 0)
				{
					game[i][j] = 2;
					SetConsoleCursorPosition(hout, move[i][j]);
					cout << "O";
					counter++;
					return;
				}
			}
		}
	}
}

void Player() {
	COORD move[3][3] = { {{35,9}, {39,9}, {43,9}}, {{35,13}, {39,13}, {43,13}}, {{35,17}, {39,17}, {43,17}} };

	
	while (true)
	{
		SetConsoleCursorPosition(hout, move[curX][curY]);
		x = _getch();
		switch (x)
		{
		case 75:
			if (curY - 1 >= 0 && curY - 1 <= 2) curY--;
			break;
		case 77:
			if (curY + 1 >= 0 && curY + 1 <= 2) curY++;
			break;
		case 80:
			if (curX + 1 >= 0 && curX + 1 <= 2) curX++;
			break;
		case 72:
			if (curX - 1 >= 0 && curX - 1 <= 2) curX--;
			break;
		case 32:
			if (game[curX][curY] != 0)
			{
				SetConsoleCursorPosition(hout, { 0,20 });
				cout << "That cage has been reserved!";
			}
			else
			{
				cout << "X";
				game[curX][curY] = 1;
				counter++;
				return;
			}
			break;
		}
	}
}
void Game()
{
	SetConsoleCursorPosition(hout, { 35, 9});
	int x = _getch();
	while (flag)
	{
		Player();
		Check();
		if (counter >= 9 || flag == false) break;
		Bot(2);
		Check();
	}

	SetConsoleCursorPosition(hout, { 0,20 });
	cout << "                                              ";
	SetConsoleCursorPosition(hout, { 0,20 });
	if (winner == 1) cout << "Player win!";
	else if (winner == 2) cout << "Comp win!";
	else if (counter>=9) cout << "Tie!";
}

void Check()
{
	for (int i = 0; i < 3; i++)
	{
		if (game[i][0] == game[i][1] && game[i][0] == game[i][2])
		{
			if (game[i][0] == 1)
			{
				flag = 0;
				winner = 1;
			}
			else if (game[i][0] == 2)
			{
				flag = 0;
				winner = 2;
			}
		}
	}
	
	for (int j = 0; j < 3; j++)
	{
		if (game[0][j] == game[1][j] && game[0][j] == game[2][j])
		{
			if (game[0][j] == 1)
			{
				flag = 0;
				winner = 1;
			}
			else if (game[0][j] == 2)
			{
				flag = 0;
				winner = 2;
			}
		}
	}
	
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] == game[2][2]) //диагональ слева на право
	{
		if (game[0][0] == 1)
		{
			flag = 0;
			winner = 1;
		}
		else if (game[0][0] == 2)
		{
			flag = 0;
			winner = 2;
		}
	}
	if (game[2][0] == game[1][1] && game[1][1] == game[2][0] && game[0][2] == game[2][0]) //диагональ справа на лево
	{
		if (game[2][0] == 1)
		{
			flag = 0;
			winner = 1;
		}
		else if (game[2][0] == 2)
		{
			flag = 0;
			winner = 2;
		}
	}
}

void Draw_Field()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (i == 0 && j % 4 == 0) field[i][j] = 203; // ╦
			else if (i == 12 && j % 4 == 0) field[i][j] = 202; // ╩
			else if (i % 4 == 0 && j % 4 != 0) field[i][j] = 205; // ═
			else if (i % 4 != 0 && j % 4 == 0) field[i][j] = 186; // ║
			else if (i % 4 == 0 && j % 4 == 0 && i != 0 && j != 0 && j != 12 && i != 12) field[i][j] = 206; // ╬
			else if (i % 4 == 0 && j == 0) field[i][j] = 204; // ╠
			else if (i % 4 == 0 && j == 12) field[i][j] = 185; // ╣
			else if (i % 4 != 0 && j % 4 != 0) field[i][j] = 255; //space
		}
		field[0][0] = 201; // ╔
		field[0][12] = 187; // ╗
		field[12][0] = 200; // ╚
		field[12][12] = 188; // ╝
	}

	for (int i = 0; i < 13; i++)
	{
		SetConsoleCursorPosition(hout, c);
		for (int j = 0; j < 13; j++)
		{
			cout << (char)field[i][j];
		}
		c.Y++;
	}
}

int main()
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	ci.dwSize = 100;
	ci.bVisible = true;
	SetConsoleCursorInfo(hout, &ci);
	SetConsoleCursorPosition(hout, c);
	Draw_Field();
	SetConsoleCursorPosition(hout, { 35,9 });
	Game();

	cout << "\n\n" << endl;
	system("pause");
}