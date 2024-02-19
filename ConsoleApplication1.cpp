// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "fun_console.h"
#include <windows.h>
#include "ASDWindow.h"
#include "ASDInput.h"
#include "ASDList.h"
#include <iomanip>

using namespace ASD;

int main()
{
    SetColor(White, Black);
    cls();
    List<int> list;
    int choice;
    bool exit = false;

    while (!exit)
    {
        SetColor(White, Black);
        cls();

        Menu menu;
        menu.Add("1. Input digit");
        menu.Add("2. Show list");
        menu.Add("3. Calculate sum");
        menu.Add("4. Calculate product");
        menu.Add("5. Delete list");
        menu.Add("6. Exit");
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
            win.Write(8, 0, "Input digit: ");
            win.Write(2, 3, "Press Enter for continue");
            win.Write(2, 4, "Press ESC to exit");
            Input input("0000");
            while (input.input(33, 12))
            {
                int num = atoi((const char*)input.get());
                list.AddTail(num);
            }
            break;
        }
        case 1: {
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 30, 8);
            win.Show();
            if (list.GetCount() != 0)
            {
                win.Write(8, 0, "Your Input: ");
                win.Write(2, 1, "Press any key for EXIT");
                GotoXY(33, 13);
                list.showList();
            }
            else {
                win.Write(2, 2, "You don't input the digit");
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

            if (list.GetCount() >= 4) {
                win.Write(10, 0, "Result: ");
                win.Write(2, 4, "Press any key for EXIT");
                GotoXY(33, 13);
                int sum = list.calculateSum();
                std::cout << "Sum: " << sum << std::endl;
            }
            else
            {
                win.Write(2, 2, "You don't input the digit");
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
            win.Move(30, 10, 30, 8);
            win.Show();

            if (list.GetCount() >= 4) {
                win.Write(10, 0, "Result: ");
                win.Write(2, 4, "Press any key for EXIT");
                GotoXY(33, 13);
                int product = list.calculateProduct();
                std::cout << "Product: " << product << std::endl;
            }
            else
            {
                win.Write(2, 2, "You don't input the digit");
                win.Write(2, 3, "Press any key for EXIT");
            }
            _getch();
            break;
        }
        case 4:
        {
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 30, 7);
            win.Show();
            if (list.GetCount() != 0)
            {
                list.RemoveAll();
                win.Write(5, 2, "Array is deleted");
            }
            else
            {
                win.Write(5, 2, "Array is empty");
            }
            _getch();
            break;
        }
        case 5: {
            exit = true;
            cls();
            break;
        }
        }
    }
	return 0;
}


