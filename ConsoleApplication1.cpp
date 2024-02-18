// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "fun_console.h"
#include <windows.h>
#include "ASDWindow.h"
#include "ASDInput.h"
#include "ASDString.h"
#include <iomanip>

using namespace ASD;


int main()
{
    SetColor(White, Black);
    cls();

    Array<int> arr;
    int choice;
    bool exit = false;

    while (!exit) {
        SetColor(White, Black);
        cls(); 

        // Create menu
        Menu menu;
        menu.Add("Input digit");
        menu.Add("Show array");
        menu.Add("Show result");
        menu.Add("Delete array");
        menu.Add("Exit");

        menu.Move(30, 10, 20, 5); // Move menu to position

        choice = menu.Modal(); // Display menu and get user choice

        switch (choice) {
        case 0: { // Input digit
            //SetColor(White, Black);
            //cls();
            //Window win;
            //win.Move(30, 10, 40, 5);
            //win.Show();
            //int num;
            //Input input("0000");
            //input.input(33, 12); // Input position
            //
            //num = atoi(input.get().get());
            //arr << num; // Add number to array
            //break;
            SetColor(White, Black);
            cls();
            bool inputting = true;

            while (inputting) {
                Window win;
                win.Move(30, 10, 40, 5);

                win.Show();
                std::cout << "Input digit: ";


                int num;
                Input input("0000");
                input.input(33, 12); // Input position

                num = atoi(input.get());
                arr << num; // Add number to array

                int key = _getch();
                if (key == 27) // ESC key
                    inputting = false;

            }
            break;
        }
        case 1: { // Show array
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 40, 5);
            win.Show();
            std::cout << "Array: ";
            for (unsigned int i = 0; i < arr.GetCount(); ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            _getch();
            break;
        }
        case 2: { // Show result
            SetColor(White, Black);
            cls();
            Window win;
            win.Move(30, 10, 40, 5);
            win.Show();
            arr.CalculateSumAndProduct(arr);
            _getch();
            break;
        }
        case 3: { // Delete array
            arr.RemoveAll();
            _getch();
            break;
        }
        case 4: { // Exit
            exit = true;
            break;
        }
        }
    }

	return 0;
}


