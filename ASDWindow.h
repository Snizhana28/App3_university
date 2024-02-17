#pragma once

#include "ASDString.h"
#include "ASDArray.h"
#include "ASDList.h"

namespace ASD {
	class Window {
	protected:
		int x, y, w, h;
		int color, bgColor, borderColor, borderShadowColor;
		char border[6];
	public:
		enum {
			Left = 0,
			Center = 1,
			Right = 2
		};

		enum {
			Top = 0,
			Middle = 1,
			Bottom = 2
		};

		Window();

		int GetHeight();
		int GetWidth();
		int GetClientWidth();
		int GetClientHeight();
		void SetHeight(int _h);
		void SetWidth(int _w);

		void AlignCenterHorz() { x = (GetCols() - w) / 2.0; }
		void AlignCenterVert() { y = (GetRows() - h) / 2.0; }
		void AlignCenter() { AlignCenterHorz(); AlignCenterVert();  }

		void Move(int _x, int _y, int _w, int _h);

		void Show();
		void Write(int, int, ASD::String);		
		void WriteRow(int, ASD::String, int align = Left);
	};

	class BaseMenu : public Window {
	protected:
		int activeColor, activeBgColor;
		int activeIndex;
		int align;
	public:
		BaseMenu() :Window() {
			activeColor = Yellow;
			activeBgColor = Black;
			activeIndex = -1;
			align = Middle;
		}

		int GetIndex() { return activeIndex; }
		void SetAlign(int a) { align = a; }

		virtual int GetCount() { return 0; }
		virtual void DrawMenu(int y, int index) {}

		int Modal() {
			activeIndex = 0;
			bool oldCaret = GetCaret();
			ShowCaret(false);
			int first = 0;
			while (1) {
				Show();

				int startY = 0;
				int startRow = 0;
				if (align == Middle && GetCount() < GetClientHeight()) {
					startRow = (GetClientHeight() - GetCount()) / 2;
				}
				else if (align == Bottom && GetCount() < GetClientHeight()) {
					startRow = GetClientHeight() - GetCount();
				}

				if (activeIndex >= first + GetClientHeight()) {
					first = activeIndex - GetClientHeight() + 1;
				}
				if (activeIndex < first) {
					first = activeIndex;
				}

				for (int i = first; i < GetCount() && startY < GetClientHeight(); i++, startY++)
				{
					DrawMenu(startY + startRow, i);
				}

				int key = _getch();
				if (key == 27) {
					activeIndex = -1;
					break;
				}
				if (key == 13) {
					break;
				}
				if (key == 224) {
					key = _getch();
					//up
					if (key == 72) {
						activeIndex--;
						if (activeIndex < 0) {
							activeIndex = GetCount() - 1;
						}
					}
					//down
					if (key == 80) {
						activeIndex++;
						if (activeIndex >= GetCount()) {
							activeIndex = 0;
						}
					}
				}

			}
			ShowCaret(oldCaret);
			return activeIndex;
		}
	};

	class Menu : public BaseMenu {
		int alignText;
		Array<String> items;
	public:
		Menu() :BaseMenu() {
			alignText = Center;
		}
		void SetAlignText(int a) { alignText = a; }
		void Add(String s) { items.Add(s); }
		virtual int GetCount() { return items.GetCount(); }
		virtual void DrawMenu(int y, int index) {
			if (index == activeIndex) {
				SetColor(activeColor, activeBgColor);
			}
			else {
				SetColor(color, bgColor);
			}
			WriteRow(y, items[index], alignText);
		}
	};

	class ColorMenu : public BaseMenu {
		public: 
			ColorMenu() : BaseMenu() {

			}
			virtual int GetCount() { return 16; }
			virtual void DrawMenu(int y, int index) {
				SetColor(index, index);
				WriteRow(y, "");
				if (index == activeIndex) {
					SetColor(color, bgColor);
					Write(0, y, ">");
				}
			}
	};
}
