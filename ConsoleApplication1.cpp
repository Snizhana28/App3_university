// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "fun_console.h"
#include <windows.h>
#include "ASDWindow.h"
#include "ASDInput.h"
#include <iomanip>


int main()
{
	SetColor(White, Black);
	cls();


	/*ASD::Menu a;
	a.SetWidth(40);
	a.SetHeight(5);
	a.AlignCenter();
	a.Add("Open");
	a.Add("Save");
	a.Add("Settings");
	a.Add("Remove");
	a.Add("Exit");
	a.Modal();

	if (a.GetIndex() >= 0) {
		std::cout << a.GetIndex();
	}*/
	
	ASD::ColorMenu b;
	b.SetWidth(40);
	b.SetHeight(10);
	b.AlignCenter();
	b.Modal();


	_getch();
	return 0;
}


