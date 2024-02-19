// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <string>
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

    while (!exit) 
    {
        SetColor(White, Black);
        cls(); 

        Menu menu;
        menu.Add("Input digit");
        menu.Add("Show array");
        menu.Add("Show result");
        menu.Add("Delete array");
        menu.Add("Exit");
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
                    arr.Add(num);
                }
                break;
            }
            case 1: {
                SetColor(White, Black);
                cls();
                Window win;
                win.Move(30, 10, 30, 8);
                win.Show();
                if (arr.GetCount() != 0)
                {
                    win.Write(8, 0, "Your Input: ");
                    win.Write(2, 1, "Press any key for EXIT");
                    GotoXY(33, 13);
                    int y = 1; 
                    for (unsigned int i = 0; i < arr.GetCount(); i++) { 
                        std::cout << arr[i] << " "; 
                        if ((i + 1) % 10 == 0) { 
                            GotoXY(33, 13 + y); 
                            y++; 
                        }
                    }
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

                if (arr.GetCount() >= 4) {
                    win.Write(10, 0, "Result: ");
                    win.Write(2, 4, "Press any key for EXIT");
                    GotoXY(33, 13);
                    arr.CalculateSumAndProduct(arr);
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
                win.Move(30, 10, 30, 7);
                win.Show();
                if (arr.GetCount() != 0) 
                {
                    arr.RemoveAll();
                    win.Write(5, 2, "Array is deleted");
		    	}
                else 
                {
		    		win.Write(5, 2, "Array is empty");
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


