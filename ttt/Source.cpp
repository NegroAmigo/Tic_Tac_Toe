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
COORD c = {33,7};
COORD inf_out = {0,21};
CONSOLE_CURSOR_INFO ci;
int field[13][13];
int game[3][3] = { 0 };
int curX = 0;
int curY = 0;
bool flag;
int winner = 0;
int x;
int turn_counter = 0;

void Bot_turn(int priority) {
	COORD move[3][3] = {{{35,9}, {39,9}, {43,9}}, {{35,13}, {39,13}, {43,13}}, {{35,17}, {39,17}, {43,17}}};
	for (int i = 0; i < 3; i++) {
		if ((game[0][i]==priority && game[1][i]==priority) || (game[1][i] == priority && game[2][i] == priority) || (game[0][i] == priority && game[2][i] == priority)) {
			for (int j = 0; j < 3; j++) {
				if (game[j][i] == 0) {
					game[j][i] = 2;
					SetConsoleCursorPosition(hout, move[j][i]);
					cout << "O";
					turn_counter++;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if ((game[i][0] == priority && game[i][1] == priority) || (game[i][1] == priority && game[i][2] == priority) || (game[i][0] == priority && game[i][2] == priority)) {
			for (int j = 0; j < 3; j++) {
				if (game[i][j] == 0) {
					game[i][j] = 2;
					SetConsoleCursorPosition(hout, move[i][j]);
					cout << "O";
					turn_counter++;
					return;
				}
			}
		}
	}
	if ((game[0][0] == priority && game[1][1] == priority) || (game[1][1] == priority && game[2][2] == priority) || (game[0][0] == priority && game[2][2] == priority)) {
		for (int j = 0; j < 3; j++) {
			if (game[j][j] == 0) {
				game[j][j] = 2;
				SetConsoleCursorPosition(hout, move[j][j]);
				cout << "O";
				turn_counter++;
				return;
			}
		}
	}
	if ((game[2][0] == priority && game[1][1] == priority) || (game[1][1] == priority && game[0][2] == priority) || (game[0][2] == priority && game[2][0] == priority)) {
		for (int j = 0; j < 3; j++) {
			if (game[j][2-j] == 0) {
				game[j][2-j] = 2;
				SetConsoleCursorPosition(hout, move[j][2 - j]);
				cout << "O";
				turn_counter++;
				return;
			}
		}
	}
	if (priority == 2) Bot_turn(1);
	else 
		for(int i = 0; i<3; i++)
			for (int j = 0; j < 3; j++) {
				if (game[i][j] == 0) {
					game[i][j] = 2;
					SetConsoleCursorPosition(hout, move[i][j]);
					cout << "O";
					turn_counter++;
					return;
				}
			}
}

void Player_turn() {
	COORD move[3][3] = { {{35,9}, {39,9}, {43,9}}, {{35,13}, {39,13}, {43,13}}, {{35,17}, {39,17}, {43,17}} };
	while (true){
		SetConsoleCursorPosition(hout, move[curX][curY]);
		x = _getch();
		switch (x){
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
				if (game[curX][curY] != 0) {
					SetConsoleCursorPosition(hout, inf_out);
					cout << "Wrong move!";
				}
				else {
					cout << "X";
					game[curX][curY] = 1;
					turn_counter++;
					return;
				}
				break;
		}
	}
}
void Game(){
	SetConsoleCursorPosition(hout, { 35,9 });
	flag = true;
	int x = _getch();
	while (flag) {
		Player_turn();
		Check();
		if (flag == 0) break;
		Bot_turn(2);
		Check();
	}
	SetConsoleCursorPosition(hout, inf_out);
	cout << "                ";
	SetConsoleCursorPosition(hout, inf_out);
	if (winner == 1) cout << "Player win!";
	else if (winner == 2) cout << "Computer win!";
	else cout << "Tie!";
	ci.bVisible = false;
	SetConsoleCursorInfo(hout, &ci);
}

void Check(){
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
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2]) {//диагональ слева на право
		if (game[0][0] == 1) {
			winner = 1;
			flag = 0;
		}
		else if (game[0][0] == 2) {
			winner = 2;
			flag = 0;
		}
	}
	if (game[2][0] == game[1][1] && game[1][1] == game[0][2]) {//диагональ справа на лево
		if (game[2][0] == 1) {
			winner = 1;
			flag = 0;
		}
		else if (game[2][0] == 2) {
			winner = 2;
			flag = 0;
		}
	}
	if (turn_counter == 9) flag = 0;
}

void Draw(){
	for (int i = 0; i < 13; i++){
		SetConsoleCursorPosition(hout, c);
		for (int j = 0; j < 13; j++){
			cout << (char)field[i][j];
		}
		c.Y++;
	}
}

void Create_field(){
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 13; j++){
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
	Draw();
}

int main(){
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	ci.dwSize = 100;
	ci.bVisible = true;
	SetConsoleCursorInfo(hout, &ci);
	SetConsoleCursorPosition(hout, c);
	Create_field();
	Game();
	cout << "\n\n" << endl;
	system("pause");
}