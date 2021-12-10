#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;
CONSOLE_CURSOR_INFO ci1;
COORD c1 = { 38,4 };
COORD c_letters = { c1.X,c1.Y };
int sleep_time = 15;

HANDLE hout_menu;
DWORD r = 0;
int arrLetter[5][5];
int arr[11][46] = { 0 };
int counter = 0;

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
    COORD c_tmp = c_letters;
    for (int i = 0; i < 5; i++)
    {
        SetConsoleCursorPosition(hout_menu, c_tmp);
        for (int j = 0; j < 5; j++)
        {
            cout << (char)arr[i][j];
            Sleep(sleep_time-5);
        }
        c_tmp.Y++;
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
    if (counter == 0) counter = 1;
    else if (counter == 1) c_letters.X += 7;
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
    c_letters.X += 7;
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
    arrLetter[3][3] = 219;
    c_letters.X += 7;
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
    c_letters.X += 7;
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
    c_letters.X += 7;
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
    COORD c_tmp = c1;
    SetConsoleCursorPosition(hout_menu, c_tmp);
    for (int i = 0; i < 11; i++)
    {
        SetConsoleCursorPosition(hout_menu, c_tmp);
        for (int j = 0; j < 46; j++)
        {
            if (i == 0 || i == 10 || j == 0 || j == 45)
            {
                cout << (char)arr[i][j];
                Sleep(sleep_time);
            }
            else cout << (char)arr[i][j];
        }
        c_tmp.Y++;
    }
    c_letters.Y += 2;
    c_letters.X += 3;
    letter_T(arrLetter);
    letter_E(arrLetter);
    letter_T(arrLetter);
    letter_R(arrLetter);
    letter_I(arrLetter);
    letter_S(arrLetter);
    c1.X += 15;
    c1.Y += 8;
    SetConsoleCursorPosition(hout_menu, c1);
    cout << "by Blue Warriors";
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