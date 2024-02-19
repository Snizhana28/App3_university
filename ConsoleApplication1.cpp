// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "fun_console.h"
#include <windows.h>
#include "ASDWindow.h"
#include "ASDInput.h"
#include <iomanip>

using namespace ASD;

int main()
{
    SetColor(White, Black);
    cls();
    String str;
    int choice;
    bool exit = false;

    while (!exit)
    {
        SetColor(White, Black);
        cls();

        Menu menu;
        menu.Add("1. Input word");
        menu.Add("2. Original word");
        menu.Add("3. Reverse word");
        menu.Add("4. Delete word");
        menu.Add("5. Exit");

        menu.Move(30, 10, 20, 5);
        choice = menu.Modal();

        switch (choice)
        {
        case 0: {
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 30, 8);
            win.Show();
            win.Write(8, 0, "Input word: ");
            win.Write(2, 4, "Press ESC to exit");

            Input input("LLLLLLLLLLLLLLL");
            while (input.input(33, 12))
            {
                str.add(input.get());
                if (str.length() == 1) {
                    str.empty();
                    win.Write(0, 4, "The word must be more than 1 letter");
                    _getch();
                }
                break;
            }
            break;
        }
        case 1: {
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 30, 8);
            win.Show();
            if (str.length() != 0)
            {
                win.Write(8, 0, "Original word: ");
                GotoXY(33, 13);
                win.Write(2, 2, str.get());
                win.Write(2, 4, "Press any key for EXIT");
            }
            else {
                win.Write(2, 2, "You don't input the word");
                win.Write(2, 3, "Press any key for EXIT");
            }
            _getch();
            break;
        }
        case 2: {
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 30, 8);
            win.Show();
            if (str.length() != 0)
            {
                win.Write(8, 0, "Reverse word: ");
                GotoXY(33, 13);
                win.Write(2, 2, str.Reverse().get());
                win.Write(2, 4, "Press any key for EXIT");
            }
            else {
                win.Write(2, 2, "You don't input the word");
                win.Write(2, 3, "Press any key for EXIT");
            }
            _getch();
            break;
        }
        case 3:
        {
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 30, 7);
            win.Show();
            if (str.length() != 0)
            {
                str.empty();
                win.Write(5, 2, "Word is deleted");
            }
            else
            {
                win.Write(5, 2, "String is empty");
            }
            _getch();
            break;
        }
        case 4: {
            exit = true;
            cls();
            break;
        }
        }
    }
	return 0;
}


