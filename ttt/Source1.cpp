#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;
CONSOLE_CURSOR_INFO ci;
COORD c = { 30,7 };

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

int main(int argv, char** argc)
{
    HANDLE hout;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    ci.dwSize = 100;
    ci.bVisible = false;
    SetConsoleCursorInfo(hout, &ci);
    DWORD r = 0;
    int arr[11][46] = { 0 };

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

    /*for (int i = 0; i < 256; i++)
    {
        cout << (char)i << " - " << i << endl;
    }*/

    int arrT[5][5] = { 219 };
    Zapoj(arrT);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0) arrT[i][j] = 220;
            if (j == 2 && i != 0) arrT[i][j] = 219;
        }
    }
    //Letter_Draw(arrT);

    int arrE[5][5];
    Zapoj(arrE);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i % 2 == 0) arrE[i][j] = 220;
            if (j == 0 && i != 0) arrE[i][j] = 219;
        }
    }
    /* for (int i = 0; i < 5; i++)
     {
         for (int j = 0; j < 5; j++)
         {
             cout << arrE[i][j] << '\t';
         }
         cout << '\n';
     }*/
     //Letter_Draw(arrE);

    cout << '\n';
    int arrR[5][5];
    Zapoj(arrR);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0 && i != 0) arrR[i][j] = 219;
            if (i == 0) arrR[i][j] = 220;
            if (j == 4 && i != 0 && i != 3) arrR[i][j] = 219;
            if (i != 0 && i == 2 && j != 0 && j != 4) arrR[i][j] = 220;
        }
    }
    arrR[3][3] = 219;
    //Letter_Draw(arrR);

    int arrI[5][5];
    Zapoj(arrI);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 4) arrI[i][j] = 220;
            if (j == 2 && i != 0) arrI[i][j] = 219;
        }
    }
    //Letter_Draw(arrI);

    int arrS[5][5];
    Zapoj(arrS);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((j == 0 && (i == 1 || i == 2)) || (j == 4 && (i == 3 || i == 4))) arrS[i][j] = 219;
            if (i == 0) arrS[i][j] = 220;
            if (i == 2 && j != 0) arrS[i][j] = 220;
            if (i == 4 && j != 4) arrS[i][j] = 220;
        }
    }
    //Letter_Draw(arrS);





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






    /* Letter_Draw(arrT);
     cout << endl;
     Letter_Draw(arrE);
     cout << endl;
     Letter_Draw(arrT);
     cout << endl;
     Letter_Draw(arrR);
     cout << endl;
     Letter_Draw(arrI);
     cout << endl;
     Letter_Draw(arrS);
     cout << endl;*/
    SetConsoleCursorPosition(hout, c);
    for (int i = 0; i < 11; i++)
    {
        SetConsoleCursorPosition(hout, c);
        for (int j = 0; j < 46; j++)
        {
            cout << (char)arr[i][j];
        }
        c.Y++;
    }
    //SetConsoleTextAttribute(hout, FOREGROUND_RED);


}