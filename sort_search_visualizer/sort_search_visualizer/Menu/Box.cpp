#include "Box.h"

Box::Box() {
	this->x = this->y = 0;
	this->w = 10;
	this->h = 5;
	this->text = "";
}
Box::Box(const Box &cop) {
	this->x = cop.x;
	this->y = cop.y;
	this->w = cop.w;
	this->h = cop.h;
	this->value = cop.value;
	this->text = cop.text;
}
Box::~Box() {
	this->x = this->y = 0;
	this->w = this->h = 0;
	this->text = "";
}

// Set Box
void Box::SetAll(int x, int y, int value) {
	this->x = x;
	this->y = y;
	this->value = value;
	this->text = to_string(value);
}
void Box::SetWHText(int w, int h, string text) {
	this->w = w;
	this->h = h;
	this->text = text;
}

// Ve Box
void Box::VeBox(int color) {
	int x = this->x;
	int y = this->y;
	int w = this->w;

	//=== khai bao cac ki tu ve box
	char traiTren = 218;
	char phaiTren = 191;
	char traiDuoi = 192;
	char phaiDuoi = 217;
	char keNgang = 196;
	char keDoc = 179;

	//=== ve 4 canh box
	for (int i = 0; i <= w - 1; i++)
	{
		for (int j = 0; j <= h - 1; j++)
		{
			GotoXY(x + i, y + j);
			if (i == 0 && j == 0) {
				cout << traiTren;
			}
			else if (i == 0 && j == h - 1) {
				cout << traiDuoi;
			}
			else if (i == w - 1 && j == 0) {
				cout << phaiTren;
			}
			else if (i == w - 1 && j == h - 1) {
				cout << phaiDuoi;
			}
			else {
				if (i == 0 || i == w - 1) {
					cout << keDoc;
				}
				else if (j == 0 || j == h - 1) {
					cout << keNgang;
				}
				else {
					BackgroundColor(color);
					if (color == Color_Black) {
						TextColor(Color_White);
					}
					else {
						TextColor(Color_Black);
					}
					cout << " ";
					BackgroundColor(Color_Black);
					TextColor(Color_White);
				}
			}
		}
	}
}
void Box::SetValue(int value) {
	this->value = value;
	this->text = to_string(value);
}
int Box::GetValue() {
	return this->value;
}

// In Chuoi
void Box::InChuoi(int canLe, int color) {
	int x = this->x;
	int y = this->y;
	int w = this->w;
	int h = this->h;
	string text = this->text;

	TextColor(Color_White);
	BackgroundColor(color);


	int centerY = h / 2 + y;
	int posX = 0;

	if (canLe == 0) {
		posX = (w / 2) - (text.length() / 2);
	}
	else if (canLe == 1) {
		posX = w - text.length() - 1;
	}
	else {
		posX = 1;
	}

	posX += x;
	GotoXY(posX, centerY);
	cout << text;

	TextColor(7);
	BackgroundColor(Color_Black);
}
void Box::InThongBao(int color, string txt) {
	int x = this->x;
	int y = this->y;
	int w = this->w;
	int h = this->h; 
	int posX = (w / 2) - (txt.length() / 2) + x;
	int posY = (w + h) + 1;
	TextColor(color);
	BackgroundColor(Color_Black);
	GotoXY(posX, posY);
	cout << txt;
	TextColor(Color_White);
	BackgroundColor(Color_Black);
}

// Xoa
void Box::XoaVienBox(bool boxChon) {
	int x = this->x;
	int y = this->y;
	int w = this->w;
	int h = this->h;

	if (boxChon) {
		x -= 3;
		GotoXY(x - 3, h / 2 + y);
		cout << "  ";
		GotoXY(x + w + 1, h / 2 + y);
		cout << "  ";
	}

	//===== xoa vien
	for (int i = 0; i <= w - 1; i++)
	{
		for (int j = 0; j <= h - 1; j++)
		{
			GotoXY(x + i, y + j);
			cout << " ";
		}
	}
	this->InChuoi(0, boxChon);
}
void Box::XoaChu(bool boxChon) {
	int x = this->x;
	int y = this->y;
	int w = this->w;
	int h = this->h;

	if (boxChon) {
		x -= 3;
		BackgroundColor(7);
		TextColor(Color_Black);
	}

	int lenght = w - 2;
	string temp(lenght, ' ');
	GotoXY(x + 1, h / 2 + y);
	cout << temp;

	if (boxChon) {
		BackgroundColor(Color_Black);
		TextColor(7);
	}
}
void Box::XoaBox(bool boxChon) {
	this->XoaChu(boxChon);
	this->XoaVienBox(boxChon);
}