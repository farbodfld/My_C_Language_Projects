#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

void gotoxy(int x, int y) {
    COORD c = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {


    for (int x = 1; x <= 1; x += 1) {
        for (int y = 1; y <= 49; y += 1) {
            printf("%c", '$');
        }
        printf("%c\n", ' ');
    }
    {
        for (int y = 1; y <= 7; y += 1) {
            for (int y = 1; y <= 4; y += 1)
                printf("%c\t\t", '@');
            printf("%c\n", ' ');
        }

        for (int x = 1; x <= 1; x += 1) {
            for (int y = 1; y <= 49; y += 1)
                printf("%c", '$');
        }
        printf("%c\n", ' ');
        {
            for (int y = 1; y <= 7; y += 1) {
                for (int y = 1; y <= 4; y += 1)
                    printf("%c\t\t", '@');
                printf("%c\n", ' ');
            }
            for (int x = 1; x <= 1; x += 1) {
                for (int y = 1; y <= 49; y += 1)
                    printf("%c", '$');
            }
            printf("%c\n", ' ');
            {
                for (int y = 1; y <= 7; y += 1) {
                    for (int y = 1; y <= 4; y += 1)
                        printf("%c\t\t", '@');
                    printf("%c\n", ' ');
                }
                for (int x = 1; x <= 1; x += 1) {
                    for (int y = 1; y <= 49; y += 1)
                        printf("%c", '$');
                }
            }
        }
        int n;
        gotoxy(2, 1);
        printf("1");
        gotoxy(18, 1);
        printf("2");
        gotoxy(34, 1);
        printf("3");
        gotoxy(2, 9);
        printf("4");
        gotoxy(18, 9);
        printf("5");
        gotoxy(34, 9);
        printf("6");
        gotoxy(2, 17);
        printf("7");
        gotoxy(18, 17);
        printf("8");
        gotoxy(34, 17);
        printf("9");

        gotoxy(55, 1);
        printf("@ number of location ");
        gotoxy(55, 3);
        printf("@ number of color cod ");
        gotoxy(55, 5);
        printf("@ please enter number of repetition = ");

        //scanf_s("%d", &n);
        cin >> n;

        {
            for (int i = 1; i <= n; i += 1) {


                srand(time(0));
                int a = rand() % 9 + 1;
                gotoxy(78, 1);
                printf("%d\n", a);

                srand(time(0));
                int b = 2 * (rand() % 3 + 1);
                gotoxy(78, 3);
                printf("%d\n", b);

                if (b == 2)
                    system("color 2");
                if (b == 2)
                    Sleep(500);
                if (b == 4)
                    system("color 4");
                if (b == 4)
                    Sleep(1000);
                if (b == 6)
                    system("color 6");
                if (b == 6)
                    Sleep(1000);
                //1

                if (a == 1)
                    gotoxy(6, 3);
                if (a == 1)
                    _putch('@');
                if (a == 1)
                    gotoxy(7, 3);
                if (a == 1)
                    _putch('~');
                if (a == 1)
                    gotoxy(8, 3);
                if (a == 1)
                    _putch('~');
                if (a == 1)
                    gotoxy(9, 3);
                if (a == 1)
                    _putch('~');
                if (a == 1)
                    gotoxy(10, 3);
                if (a == 1)
                    _putch('@');
                if (a == 1)
                    gotoxy(7, 4);
                if (a == 1)
                    _putch('.');
                if (a == 1)
                    gotoxy(9, 4);
                if (a == 1)
                    _putch('.');
                if (a == 1)
                    gotoxy(6, 4);
                if (a == 1)
                    _putch('(');
                if (a == 1)
                    gotoxy(10, 4);
                if (a == 1)
                    _putch(')');
                if (a == 1)
                    gotoxy(7, 5);
                if (a == 1)
                    _putch('=');
                if (a == 1)
                    gotoxy(8, 5);
                if (a == 1)
                    _putch('*');
                if (a == 1)
                    gotoxy(9, 5);
                if (a == 1)
                    _putch('=');

                //2

                if (a == 2)
                    gotoxy(22, 3);
                if (a == 2)
                    _putch('@');
                if (a == 2)
                    gotoxy(23, 3);
                if (a == 2)
                    _putch('~');
                if (a == 2)
                    gotoxy(24, 3);
                if (a == 2)
                    _putch('~');
                if (a == 2)
                    gotoxy(25, 3);
                if (a == 2)
                    _putch('~');
                if (a == 2)
                    gotoxy(26, 3);
                if (a == 2)
                    _putch('@');
                if (a == 2)
                    gotoxy(23, 4);
                if (a == 2)
                    _putch('.');
                if (a == 2)
                    gotoxy(25, 4);
                if (a == 2)
                    _putch('.');
                if (a == 2)
                    gotoxy(22, 4);
                if (a == 2)
                    _putch('(');
                if (a == 2)
                    gotoxy(26, 4);
                if (a == 2)
                    _putch(')');
                if (a == 2)
                    gotoxy(23, 5);
                if (a == 2)
                    _putch('=');
                if (a == 2)
                    gotoxy(24, 5);
                if (a == 2)
                    _putch('*');
                if (a == 2)
                    gotoxy(25, 5);
                if (a == 2)
                    _putch('=');

                //3

                if (a == 3)
                    gotoxy(38, 3);
                if (a == 3)
                    _putch('@');
                if (a == 3)
                    gotoxy(39, 3);
                if (a == 3)
                    _putch('~');
                if (a == 3)
                    gotoxy(40, 3);
                if (a == 3)
                    _putch('~');
                if (a == 3)
                    gotoxy(41, 3);
                if (a == 3)
                    _putch('~');
                if (a == 3)
                    gotoxy(42, 3);
                if (a == 3)
                    _putch('@');
                if (a == 3)
                    gotoxy(39, 4);
                if (a == 3)
                    _putch('.');
                if (a == 3)
                    gotoxy(41, 4);
                if (a == 3)
                    _putch('.');
                if (a == 3)
                    gotoxy(38, 4);
                if (a == 3)
                    _putch('(');
                if (a == 3)
                    gotoxy(42, 4);
                if (a == 3)
                    _putch(')');
                if (a == 3)
                    gotoxy(39, 5);
                if (a == 3)
                    _putch('=');
                if (a == 3)
                    gotoxy(40, 5);
                if (a == 3)
                    _putch('*');
                if (a == 3)
                    gotoxy(41, 5);
                if (a == 3)
                    _putch('=');

                //4

                if (a == 4)
                    gotoxy(6, 11);
                if (a == 4)
                    _putch('@');
                if (a == 4)
                    gotoxy(7, 11);
                if (a == 4)
                    _putch('~');
                if (a == 4)
                    gotoxy(8, 11);
                if (a == 4)
                    _putch('~');
                if (a == 4)
                    gotoxy(9, 11);
                if (a == 4)
                    _putch('~');
                if (a == 4)
                    gotoxy(10, 11);
                if (a == 4)
                    _putch('@');
                if (a == 4)
                    gotoxy(7, 12);
                if (a == 4)
                    _putch('.');
                if (a == 4)
                    gotoxy(9, 12);
                if (a == 4)
                    _putch('.');
                if (a == 4)
                    gotoxy(6, 12);
                if (a == 4)
                    _putch('(');
                if (a == 4)
                    gotoxy(10, 12);
                if (a == 4)
                    _putch(')');
                if (a == 4)
                    gotoxy(7, 13);
                if (a == 4)
                    _putch('=');
                if (a == 4)
                    gotoxy(8, 13);
                if (a == 4)
                    _putch('*');
                if (a == 4)
                    gotoxy(9, 13);
                if (a == 4)
                    _putch('=');

                //5

                if (a == 5)
                    gotoxy(22, 11);
                if (a == 5)
                    _putch('@');
                if (a == 5)
                    gotoxy(23, 11);
                if (a == 5)
                    _putch('~');
                if (a == 5)
                    gotoxy(24, 11);
                if (a == 5)
                    _putch('~');
                if (a == 5)
                    gotoxy(25, 11);
                if (a == 5)
                    _putch('~');
                if (a == 5)
                    gotoxy(26, 11);
                if (a == 5)
                    _putch('@');
                if (a == 5)
                    gotoxy(23, 12);
                if (a == 5)
                    _putch('.');
                if (a == 5)
                    gotoxy(25, 12);
                if (a == 5)
                    _putch('.');
                if (a == 5)
                    gotoxy(22, 12);
                if (a == 5)
                    _putch('(');
                if (a == 5)
                    gotoxy(26, 12);
                if (a == 5)
                    _putch(')');
                if (a == 5)
                    gotoxy(23, 13);
                if (a == 5)
                    _putch('=');
                if (a == 5)
                    gotoxy(24, 13);
                if (a == 5)
                    _putch('*');
                if (a == 5)
                    gotoxy(25, 13);
                if (a == 5)
                    _putch('=');

                //6

                if (a == 6)
                    gotoxy(38, 11);
                if (a == 6)
                    _putch('@');
                if (a == 6)
                    gotoxy(39, 11);
                if (a == 6)
                    _putch('~');
                if (a == 6)
                    gotoxy(40, 11);
                if (a == 6)
                    _putch('~');
                if (a == 6)
                    gotoxy(41, 11);
                if (a == 6)
                    _putch('~');
                if (a == 6)
                    gotoxy(42, 11);
                if (a == 6)
                    _putch('@');
                if (a == 6)
                    gotoxy(39, 12);
                if (a == 6)
                    _putch('.');
                if (a == 6)
                    gotoxy(41, 12);
                if (a == 6)
                    _putch('.');
                if (a == 6)
                    gotoxy(38, 12);
                if (a == 6)
                    _putch('(');
                if (a == 6)
                    gotoxy(42, 12);
                if (a == 6)
                    _putch(')');
                if (a == 6)
                    gotoxy(39, 13);
                if (a == 6)
                    _putch('=');
                if (a == 6)
                    gotoxy(40, 13);
                if (a == 6)
                    _putch('*');
                if (a == 6)
                    gotoxy(41, 13);
                if (a == 6)
                    _putch('=');

                //7

                if (a == 7)
                    gotoxy(6, 19);
                if (a == 7)
                    _putch('@');
                if (a == 7)
                    gotoxy(7, 19);
                if (a == 7)
                    _putch('~');
                if (a == 7)
                    gotoxy(8, 19);
                if (a == 7)
                    _putch('~');
                if (a == 7)
                    gotoxy(9, 19);
                if (a == 7)
                    _putch('~');
                if (a == 7)
                    gotoxy(10, 19);
                if (a == 7)
                    _putch('@');
                if (a == 7)
                    gotoxy(7, 20);
                if (a == 7)
                    _putch('.');
                if (a == 7)
                    gotoxy(9, 20);
                if (a == 7)
                    _putch('.');
                if (a == 7)
                    gotoxy(6, 20);
                if (a == 7)
                    _putch('(');
                if (a == 7)
                    gotoxy(10, 20);
                if (a == 7)
                    _putch(')');
                if (a == 7)
                    gotoxy(7, 21);
                if (a == 7)
                    _putch('=');
                if (a == 7)
                    gotoxy(8, 21);
                if (a == 7)
                    _putch('*');
                if (a == 7)
                    gotoxy(9, 21);
                if (a == 7)
                    _putch('=');

                //8

                if (a == 8)
                    gotoxy(22, 19);
                if (a == 8)
                    _putch('@');
                if (a == 8)
                    gotoxy(23, 19);
                if (a == 8)
                    _putch('~');
                if (a == 8)
                    gotoxy(24, 19);
                if (a == 8)
                    _putch('~');
                if (a == 8)
                    gotoxy(25, 19);
                if (a == 8)
                    _putch('~');
                if (a == 8)
                    gotoxy(26, 19);
                if (a == 8)
                    _putch('@');
                if (a == 8)
                    gotoxy(23, 20);
                if (a == 8)
                    _putch('.');
                if (a == 8)
                    gotoxy(25, 20);
                if (a == 8)
                    _putch('.');
                if (a == 8)
                    gotoxy(22, 20);
                if (a == 8)
                    _putch('(');
                if (a == 8)
                    gotoxy(26, 20);
                if (a == 8)
                    _putch(')');
                if (a == 8)
                    gotoxy(23, 21);
                if (a == 8)
                    _putch('=');
                if (a == 8)
                    gotoxy(24, 21);
                if (a == 8)
                    _putch('*');
                if (a == 8)
                    gotoxy(25, 21);
                if (a == 8)
                    _putch('=');

                //9

                if (a == 9)
                    gotoxy(38, 19);
                if (a == 9)
                    _putch('@');
                if (a == 9)
                    gotoxy(39, 19);
                if (a == 9)
                    _putch('~');
                if (a == 9)
                    gotoxy(40, 19);
                if (a == 9)
                    _putch('~');
                if (a == 9)
                    gotoxy(41, 19);
                if (a == 9)
                    _putch('~');
                if (a == 9)
                    gotoxy(42, 19);
                if (a == 9)
                    _putch('@');
                if (a == 9)
                    gotoxy(39, 20);
                if (a == 9)
                    _putch('.');
                if (a == 9)
                    gotoxy(41, 20);
                if (a == 9)
                    _putch('.');
                if (a == 9)
                    gotoxy(38, 20);
                if (a == 9)
                    _putch('(');
                if (a == 9)
                    gotoxy(42, 20);
                if (a == 9)
                    _putch(')');
                if (a == 9)
                    gotoxy(39, 21);
                if (a == 9)
                    _putch('=');
                if (a == 9)
                    gotoxy(40, 21);
                if (a == 9)
                    _putch('*');
                if (a == 9)
                    gotoxy(41, 21);
                if (a == 9)
                    _putch('=');
                Sleep(500);
//clean 1.
                gotoxy(6, 3);
                _putch(' ');
                gotoxy(22, 3);
                _putch(' ');
                gotoxy(38, 3);
                _putch(' ');
                gotoxy(6, 11);
                _putch(' ');
                gotoxy(22, 11);
                _putch(' ');
                gotoxy(38, 11);
                _putch(' ');
                gotoxy(6, 19);
                _putch(' ');
                gotoxy(22, 19);
                _putch(' ');
                gotoxy(38, 19);
                _putch(' ');
//clean 2.
                gotoxy(7, 3);
                _putch(' ');
                gotoxy(23, 3);
                _putch(' ');
                gotoxy(39, 3);
                _putch(' ');
                gotoxy(7, 11);
                _putch(' ');
                gotoxy(23, 11);
                _putch(' ');
                gotoxy(39, 11);
                _putch(' ');
                gotoxy(7, 19);
                _putch(' ');
                gotoxy(23, 19);
                _putch(' ');
                gotoxy(39, 19);
                _putch(' ');
//clean 3.
                gotoxy(8, 3);
                _putch(' ');
                gotoxy(24, 3);
                _putch(' ');
                gotoxy(40, 3);
                _putch(' ');
                gotoxy(8, 11);
                _putch(' ');
                gotoxy(24, 11);
                _putch(' ');
                gotoxy(40, 11);
                _putch(' ');
                gotoxy(8, 19);
                _putch(' ');
                gotoxy(24, 19);
                _putch(' ');
                gotoxy(40, 19);
                _putch(' ');
//clean 4.
                gotoxy(9, 3);
                _putch(' ');
                gotoxy(25, 3);
                _putch(' ');
                gotoxy(41, 3);
                _putch(' ');
                gotoxy(9, 11);
                _putch(' ');
                gotoxy(25, 11);
                _putch(' ');
                gotoxy(41, 11);
                _putch(' ');
                gotoxy(9, 19);
                _putch(' ');
                gotoxy(25, 19);
                _putch(' ');
                gotoxy(41, 19);
                _putch(' ');
//clean 5.
                gotoxy(10, 3);
                _putch(' ');
                gotoxy(26, 3);
                _putch(' ');
                gotoxy(42, 3);
                _putch(' ');
                gotoxy(10, 11);
                _putch(' ');
                gotoxy(26, 11);
                _putch(' ');
                gotoxy(42, 11);
                _putch(' ');
                gotoxy(10, 19);
                _putch(' ');
                gotoxy(26, 19);
                _putch(' ');
                gotoxy(42, 19);
                _putch(' ');
//clean 6
                gotoxy(6, 4);
                _putch(' ');
                gotoxy(22, 4);
                _putch(' ');
                gotoxy(38, 4);
                _putch(' ');
                gotoxy(6, 12);
                _putch(' ');
                gotoxy(22, 12);
                _putch(' ');
                gotoxy(38, 12);
                _putch(' ');
                gotoxy(6, 20);
                _putch(' ');
                gotoxy(22, 20);
                _putch(' ');
                gotoxy(38, 20);
                _putch(' ');
//clean 7
                gotoxy(7, 4);
                _putch(' ');
                gotoxy(23, 4);
                _putch(' ');
                gotoxy(39, 4);
                _putch(' ');
                gotoxy(7, 12);
                _putch(' ');
                gotoxy(23, 12);
                _putch(' ');
                gotoxy(39, 12);
                _putch(' ');
                gotoxy(7, 20);
                _putch(' ');
                gotoxy(23, 20);
                _putch(' ');
                gotoxy(39, 20);
                _putch(' ');
//clean 8
                gotoxy(8, 4);
                _putch(' ');
                gotoxy(24, 4);
                _putch(' ');
                gotoxy(40, 4);
                _putch(' ');
                gotoxy(8, 12);
                _putch(' ');
                gotoxy(24, 12);
                _putch(' ');
                gotoxy(40, 12);
                _putch(' ');
                gotoxy(8, 20);
                _putch(' ');
                gotoxy(24, 20);
                _putch(' ');
                gotoxy(40, 20);
                _putch(' ');
//clean 9
                gotoxy(9, 4);
                _putch(' ');
                gotoxy(25, 4);
                _putch(' ');
                gotoxy(41, 4);
                _putch(' ');
                gotoxy(9, 12);
                _putch(' ');
                gotoxy(25, 12);
                _putch(' ');
                gotoxy(41, 12);
                _putch(' ');
                gotoxy(9, 20);
                _putch(' ');
                gotoxy(25, 20);
                _putch(' ');
                gotoxy(41, 20);
                _putch(' ');
//clean 10
                gotoxy(10, 4);
                _putch(' ');
                gotoxy(26, 4);
                _putch(' ');
                gotoxy(42, 4);
                _putch(' ');
                gotoxy(10, 12);
                _putch(' ');
                gotoxy(26, 12);
                _putch(' ');
                gotoxy(42, 12);
                _putch(' ');
                gotoxy(10, 20);
                _putch(' ');
                gotoxy(26, 20);
                _putch(' ');
                gotoxy(42, 20);
                _putch(' ');
//clean 11
                gotoxy(6, 5);
                _putch(' ');
                gotoxy(22, 5);
                _putch(' ');
                gotoxy(38, 5);
                _putch(' ');
                gotoxy(6, 13);
                _putch(' ');
                gotoxy(22, 13);
                _putch(' ');
                gotoxy(38, 13);
                _putch(' ');
                gotoxy(6, 21);
                _putch(' ');
                gotoxy(22, 21);
                _putch(' ');
                gotoxy(38, 21);
                _putch(' ');
//clean 12
                gotoxy(7, 5);
                _putch(' ');
                gotoxy(23, 5);
                _putch(' ');
                gotoxy(39, 5);
                _putch(' ');
                gotoxy(7, 13);
                _putch(' ');
                gotoxy(23, 13);
                _putch(' ');
                gotoxy(39, 13);
                _putch(' ');
                gotoxy(7, 21);
                _putch(' ');
                gotoxy(23, 21);
                _putch(' ');
                gotoxy(39, 21);
                _putch(' ');
//clean 13
                gotoxy(8, 5);
                _putch(' ');
                gotoxy(24, 5);
                _putch(' ');
                gotoxy(40, 5);
                _putch(' ');
                gotoxy(8, 13);
                _putch(' ');
                gotoxy(24, 13);
                _putch(' ');
                gotoxy(40, 13);
                _putch(' ');
                gotoxy(8, 21);
                _putch(' ');
                gotoxy(24, 21);
                _putch(' ');
                gotoxy(40, 21);
                _putch(' ');
//clean 14
                gotoxy(9, 5);
                _putch(' ');
                gotoxy(25, 5);
                _putch(' ');
                gotoxy(41, 5);
                _putch(' ');
                gotoxy(9, 13);
                _putch(' ');
                gotoxy(25, 13);
                _putch(' ');
                gotoxy(41, 13);
                _putch(' ');
                gotoxy(9, 21);
                _putch(' ');
                gotoxy(25, 21);
                _putch(' ');
                gotoxy(41, 21);
                _putch(' ');
//clean 15
                gotoxy(10, 5);
                _putch(' ');
                gotoxy(26, 5);
                _putch(' ');
                gotoxy(42, 5);
                _putch(' ');
                gotoxy(10, 13);
                _putch(' ');
                gotoxy(26, 13);
                _putch(' ');
                gotoxy(42, 13);
                _putch(' ');
                gotoxy(10, 21);
                _putch(' ');
                gotoxy(26, 21);
                _putch(' ');
                gotoxy(42, 21);
                _putch(' ');


            }

        }
    }
    _getch();
}