#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;
CONSOLE_CURSOR_INFO ci1;
COORD c1 = { 30,7 };
HANDLE hout_menu;
DWORD r = 0;
int arrLetter[5][5];
int arr[11][46] = { 0 };

void Zapoj(int arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = 255;
        }
    }
}

void Letter_Draw(int arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << (char)arr[i][j];
        }
        cout << endl;
    }
}

void letter_T(int arrLetter[5][5])
{
    
    Zapoj(arrLetter);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0) arrLetter[i][j] = 220;
            if (j == 2 && i != 0) arrLetter[i][j] = 219;
        }
    }
    Letter_Draw(arrLetter);
}

void letter_E(int arrLetter[5][5])
{
    Zapoj(arrLetter);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i % 2 == 0) arrLetter[i][j] = 220;
            if (j == 0 && i != 0) arrLetter[i][j] = 219;
        }
    }
    Letter_Draw(arrLetter);
}

void letter_R(int arrLetter[5][5])
{
    Zapoj(arrLetter);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0 && i != 0) arrLetter[i][j] = 219;
            if (i == 0) arrLetter[i][j] = 220;
            if (j == 4 && i != 0 && i != 3) arrLetter[i][j] = 219;
            if (i != 0 && i == 2 && j != 0 && j != 4) arrLetter[i][j] = 220;
        }
    }
    Letter_Draw(arrLetter);
}

void letter_I(int arrLetter[5][5])
{
    Zapoj(arrLetter);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 4) arrLetter[i][j] = 220;
            if (j == 2 && i != 0) arrLetter[i][j] = 219;
        }
    }
    Letter_Draw(arrLetter);
}

void letter_S(int arrLetter[5][5])
{
    Zapoj(arrLetter);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((j == 0 && (i == 1 || i == 2)) || (j == 4 && (i == 3 || i == 4))) arrLetter[i][j] = 219;
            if (i == 0) arrLetter[i][j] = 220;
            if (i == 2 && j != 0) arrLetter[i][j] = 220;
            if (i == 4 && j != 4) arrLetter[i][j] = 220;
        }
    }
    Letter_Draw(arrLetter);
}

void Draw_Frame()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 46; j++)
        {
            if (j == 0 || j == 45) arr[i][j] = 219;
            if (i == 0) arr[i][j] = 220;
            if (i == 10) arr[i][j] = 223;
            if (i != 0 && i != 10 && j != 0 && j != 45) arr[i][j] = 255;

        }
    }

    SetConsoleCursorPosition(hout_menu, c1);
    for (int i = 0; i < 11; i++)
    {
        SetConsoleCursorPosition(hout_menu, c1);
        for (int j = 0; j < 46; j++)
        {
            cout << (char)arr[i][j];
        }
        c1.Y++;
    }
}

int main_draw_menu()
{
    hout_menu = GetStdHandle(STD_OUTPUT_HANDLE);
    ci1.dwSize = 100;
    ci1.bVisible = false;
    SetConsoleCursorInfo(hout_menu, &ci1);
    
    Draw_Frame();

    //░ - 176
    // 
    //▒ - 177
    // 
    //▓ - 178
    //    │ - 179
    //    ┤ - 180
    //    ╡ - 181
    //    ╢ - 182
    //    ╖ - 183
    //    ╕ - 184
    //    ╣ - 185
    //    ║ - 186
    //    ╗ - 187
    //    ╝ - 188
    //    ╜ - 189
    //    ╛ - 190
    //    ┐ - 191
    //    └ - 192
    //    ┴ - 193
    //    ┬ - 194
    //    ├ - 195
    //    ─ - 196
    //    ┼ - 197
    //    ╞ - 198
    //    ╟ - 199
    //    ╚ - 200
    //    ╔ - 201
    //    ╩ - 202
    //    ╦ - 203
    //    ╠ - 204
    //    ═ - 205
    //    ╬ - 206
    //    ╧ - 207
    //    ╨ - 208
    //    ╤ - 209
    //    ╥ - 210
    //    ╙ - 211
    //    ╘ - 212
    //    ╒ - 213
    //    ╓ - 214
    //    ╫ - 215
    //    ╪ - 216
    //    ┘ - 217
    //    ┌ - 218
    //    █ - 219
    //    ▄ - 220
    //    ▌ - 221
    //    ▐ - 222
    //    ▀ - 223

   

    return 0;
}