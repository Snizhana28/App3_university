#include <iostream>
#include <conio.h>
#include "fun_console.h"
#include "ASDWindow.h"

ASD::Window::Window() {
	x = y = 0;
	w = GetCols();
	h = GetRows() - 1;
	color = White;
	bgColor = Blue;
	borderColor = LightCyan;
	borderShadowColor = Red;
	border[0] = 218;
	border[1] = 196;
	border[2] = 191;
	border[3] = 179;
	border[4] = 192;
	border[5] = 217;
}

int ASD::Window::GetHeight() { return h; }
int ASD::Window::GetWidth() { return w; }
int ASD::Window::GetClientWidth() { return w - 2; }
int ASD::Window::GetClientHeight() { return h - 2; }

void ASD::Window::SetHeight(int _h) {
	if (_h < 3) { _h = h; }
	if (y + _h >= GetRows()) {
		h = GetRows() - y - 1;
	}
	else {
		h = _h;
	}	
	h = _h;
}
void ASD::Window::SetWidth(int _w) {	
	if (_w < 3) { _w = w; }
	if (x + _w > GetCols()) {
		w = GetCols() - x;
	}
	else {
		w = _w;
	}
	
	w = _w;
}

void ASD::Window::Move(int _x, int _y, int _w, int _h) {
	if (_x >= 0 && _x <= GetCols() - 2) {
		x = _x;
	}
	if (_y >= 0 && _y <= GetRows() - 3) {
		y = _y;
	}
	SetHeight(_h);
	SetWidth(_w);
}

void ASD::Window::Show() {
	
	SetColor(borderColor, bgColor);
	for (int i = y ; i <= y + h - 1; i++) {
		GotoXY(x, i);
		SetColor(borderColor, bgColor);
		if (i == y) {
			std::cout << border[0];
		}
		else if (i == y + h -1) {
			std::cout << border[4];
			SetColor(borderShadowColor, bgColor);
		}
		else {
			std::cout << border[3];
		}
		for (int j = x + 1; j < x + w - 1; j++) {			
			if (i == y || i == y + h - 1) {
				std::cout << border[1];
			}
			else {
				std::cout << " ";
			}
		}
		SetColor(borderShadowColor, bgColor);
		if (i == y) {
			std::cout << border[2];
		}
		else if (i == y + h - 1) {
			std::cout << border[5];
		}
		else {
			std::cout << border[3];
		}
	}
	SetColor(color, bgColor);
	GotoXY(x + 1, y + 1);
}

void ASD::Window::Write(int _x, int _y, ASD::String s) {
	int yy = _y;
	int xx = _x;
	for (int i = 0; i < s.length(); i++) {
		if (xx >= GetClientWidth() || s[i] == '\n') {
			yy ++;
			xx = 0;
		}
		if (yy >= GetClientHeight()) break;
		if (s[i] == '\n') { continue; }
		GotoXY(x + 1 + xx, y + 1 + yy);
		if (s[i] < 32) {
			std::cout << ' ';
		}
		else {
			std::cout << s[i];
		}
		xx++;
	}
}

void ASD::Window::WriteRow(int _y, ASD::String s, int align) {
	int _x = 0;
	if (align == Center && s.length() < GetClientWidth()) {
		_x = (GetClientWidth() - s.length()) / 2;
	}
	if (align == Right && s.length() < GetClientWidth()) {
		_x = GetClientWidth() - s.length();
	}
	int j = 0;
	GotoXY(x + 1, y + 1 + _y);
	for (int i = 0; i < GetClientWidth(); i++) {
		if (i < _x) {
			std::cout << ' ';
		}
		else if (j < s.length())
		{
			std::cout << s[j];
			j++;
		}
		else {
			std::cout << ' ';
		}
	}
}

