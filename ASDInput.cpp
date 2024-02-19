#include "ASDInput.h"
#include <conio.h>
#include <iostream>
#include "fun_console.h"

bool ASD::Input::input(int x, int y) {
	str = "";	
	int px = 0; 
	while (true) {
		GotoXY(x, y);
		for (int i = 0; i < mask.length(); i++) {
			std::cout << " ";
		}
		GotoXY(x, y);
		std::cout << str;
		GotoXY(x + px, y);
		int key = _getch();
		if (key == 13)
		{			
			break;
		}
		if (key == 27) {
			return false;
		}

		//backspace key
		if (key == 8 && px > 0) {
			str.RemoveAt(px - 1);
			px--;
			continue;
		}
		if (key == 224) {
			key = _getch();
			//left key
			if (key == 75 && px > 0) {
				px--;
				continue;
			}
			//right key
			if (key == 77 && px < str.length()) {
				px++;
				continue;
			}
			//del key
			if (key == 83) {
				str.RemoveAt(px);
				continue;
			}
		}

		if (mask[px] == '0' && (key < '0' || key > '9')) {
			continue;
		}
		if (mask[px] == 'L' && (key < 'A' || key > 'z')) {
			continue;
		}
		if (mask[px] == 'A' && (key < 'A' || key > 'Z')) {
			continue;
		}
		if (mask[px] == 'a' && (key < 'a' || key > 'z')) {
			continue;
		}
		if (str.length() >= mask.length()) {
			continue;
		}
		
		//input char
		if (px >= str.length()) {
			str += (char)key;
		}
		else {
			str[px] = (char)key;
		}

		px++;
	}
	return true;
}

