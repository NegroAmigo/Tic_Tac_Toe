// tic_tac_toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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
int game[3][3] = {0};
int hod = 1;

int curX = 0;
int curY = 0;
bool flag = true;
bool flag1 = true;
int winner = 0;
 
void Game() 
{
	COORD move[3][3] = { {{35,9}, {39,9}, {43,9}}, {{35,13}, {39,13}, {43,13}}, {{35,17}, {39,17}, {43,17}} };
	SetConsoleCursorPosition(hout, move[0][0]);
	int x = _getch();
	while (flag)
	{
		SetConsoleCursorPosition(hout, move[curX][curY]);
		x = _getch();

		switch (x)
		{
		case 75:
			if (curY >= 0 && curY <= 2) {
				if (curY - 1 >= 0 && curY - 1 <= 2) 
				{
					curY--;
					SetConsoleCursorPosition(hout, move[curY][curX]);
				}
			}
			break;
		case 77:
			if (curY >= 0 && curY <= 2)
				if (curY + 1 >= 0 && curY + 1 <= 2) 
				{
					curY++;
					SetConsoleCursorPosition(hout, move[curY][curX]);
				}
			break;
		case 80:
			if (curX >= 0 && curX <= 2)
				if (curX + 1 >= 0 && curX + 1 <= 2) 
				{
					curX++;
					SetConsoleCursorPosition(hout, move[curY][curX]);
				}
			break;
		case 72:
			if (curX >= 0 && curX <= 2)
				if (curX - 1 >= 0 && curX - 1 <= 2) 
				{
					curX--;
					SetConsoleCursorPosition(hout, move[curY][curX]);
				}
			break;
		case 32:
			if (game[curX][curY] == 1) 
			{
				SetConsoleCursorPosition(hout, { 0,20 });
				cout << "Fuck you leatherman!";
			}
			else 
			{
				cout << "X";
				SetConsoleCursorPosition(hout, move[curY][curX]);
				game[curX][curY] = 1;
				hod = 2;
			}
			break;
		}
		check();
	}
}

void check() 
{
	if (game[0][0] == game[0][1] && game[0][0] == game[0][2]) //первая горизонталь
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
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2]) //вторая горизонталь
	{
		if (game[1][0] == 1) 
		{
			flag = 0;
			winner = 1;
		}
		else if (game[1][0] == 2) 
		{
			flag = 0;
			winner = 2;
		}
	}
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][0] == game[2][2]) //третья горизонталь
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
			if (game[curX][curY] == 1){
				SetConsoleCursorPosition(hout, { 0,20 });
				cout << "Wrong move!";
			}
			else{
				cout << "X";
				game[curX][curY] = 1;
				player_flag = 0;
			}
			break;
		}
	}
 }
void Game() 
{
	SetConsoleCursorPosition(hout, {35,9});
	int x = _getch();
	while (flag) {
		Player_turn();
		Check();
		Bot_turn();
		Check();
	}
	SetConsoleCursorPosition(hout, { 0,20 });
	cout << "                ";
	SetConsoleCursorPosition(hout, { 0,20 });
	if (winner == 1) cout << "Player win!";
	else if (winner == 2) cout << "Computer win!";
	else cout << "Tie!";
	ci.bVisible = false;
	SetConsoleCursorInfo(hout, &ci);
}

void Check() 
{
	for (int i = 0; i < 3; i++) {
		if (game[0][i] == game[1][i] && game[1][i] == game[2][i]) {
			if (game[0][i] != 0 && game[1][i] != 0 && game[2][i] != 0) {
				if (game[0][i] == 1) winner = 1;
				else if (game[0][i] == 2) winner = 2;
				flag = 0;
				break;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (game[i][0] == game[i][1] && game[i][1] == game[i][2]) {
			if (game[i][0] != 0 && game[i][1] != 0 && game[i][2] != 0) {
				if (game[i][0] == 1) winner = 1;
				else if (game[i][0] == 2) winner = 2;
				flag = 0;
				break;
			}
		}
	}
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2]) //диагональ слева на право
	{
		if (game[0][0] == 1) {
			winner = 1;
			flag = 0;
		} 
		else if (game[0][0] == 2) {
			winner = 2;
			flag = 0;
		} 
	}
	if (game[2][0] == game[1][1] && game[1][1] == game[0][2]) //диагональ справа на лево
	{
		if (game[2][0] == 1) {
			winner = 1;
			flag = 0;
		}
		else if (game[2][0] == 2) {
			winner = 2;
			flag = 0;
		}
	}
	/*for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++)
			if (game[i][j] != 0) counter++;
	if (counter == 9) flag = 0;
	counter = 0;*/
	
}

void Draw()
{
	for (int i = 0; i < 13; i++)
	{
		SetConsoleCursorPosition(hout, c);
		for (int j = 0; j < 13; j++)
		{
			cout <<(char)field[i][j];
		}
		c.Y++;
	}
}

void Field(int arr[13][13])
{
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 13; j++)
		{
			if (i == 0 && j % 4 == 0) arr[i][j] = 203; // ╦
			else if (i == 12 && j % 4 == 0) arr[i][j] = 202; // ╩
			else if (i % 4 == 0 && j % 4 != 0) arr[i][j] = 205; // ═
			else if (i % 4 != 0 && j % 4 == 0) arr[i][j] = 186; // ║
			else if (i % 4 == 0 && j % 4 == 0 && i != 0 && j != 0 && j != 12 && i != 12) arr[i][j] = 206; // ╬
			else if (i % 4 == 0 && j == 0) arr[i][j] = 204; // ╠
			else if (i % 4 == 0 && j == 12) arr[i][j] = 185; // ╣
			else if (i % 4 != 0 && j % 4 != 0) arr[i][j] = 255; //space
		}
		arr[0][0] = 201; // ╔
		arr[0][12] = 187; // ╗
		arr[12][0] = 200; // ╚
		arr[12][12] = 188; // ╝
	}
}

int main()
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	ci.dwSize = 100;
	ci.bVisible = true;
	SetConsoleCursorInfo(hout, &ci);
	SetConsoleCursorPosition(hout, c);

	Field(field);
	Draw();
	Game();
	/*for (int i = 0; i < 256; i++)
	{
		cout << i << '\t' << (char)i << "\n\n";
	}*/
	
	cout << "\n\n" << endl;
	system("pause");
}