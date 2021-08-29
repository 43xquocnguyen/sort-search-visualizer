#include "Menu.h"

Menu::Menu() {
	this->x = this->y = this->w = this->h = this->soLuong = 0;
	this->tColor = 7;
	this->box = NULL;
	this->text = NULL;
}
Menu::~Menu() {
	this->x = this->y = this->w = this->h = this->soLuong = 0;
	this->tColor = 7;
	this->box = NULL;
	this->text = NULL;
	delete[] this->box;
	delete[] this->text;
}

void Menu::SetMenu(int x, int y, int w, int h, int tColor, int soLuong, string *text) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->tColor = tColor;
	this->soLuong = soLuong;
	this->box = new Box[this->soLuong];
	this->text = text;

	// Set Box
	for (int i = 0; i < this->soLuong; i++)
	{
		// set cho moi box cach nhau 1 o^
		this->box[i].SetAll(this->x, this->y + (i * this->h), 0);
		this->box[i].SetWHText(this->w, this->h, this->text[i]);
	}

}
void Menu::VeMenu() {
	for (int i = 0; i < this->soLuong; i++)
	{
		this->box[i].VeBox(false);
		this->box[i].InChuoi(0, false);
	}
}
void Menu::Chay(int &check) {
	int mauChon = this->tColor;
    char phim;
	int viTri = 0;
	int viTriTruocDo = viTri;
	bool nhanPhimMuiTen = false;

	this->VeMenu();
	this->box[viTri].XoaBox(false);
	this->box[viTri].VeBox(mauChon);
	this->box[viTri].InChuoi(0, mauChon);

	while (true)
	{
		if (_kbhit()) {
			phim = _getch();
			if (phim == -32) {
				phim = _getch();
				viTriTruocDo = viTri;
				nhanPhimMuiTen = true;
				if (phim == 72) // mui ten len ^
				{
					if (viTri == 0) {
						viTri = soLuong - 1;
					}
					else {
						viTri--;
					}
				}
				else if (phim == 80) { // mui ten xuong 
					if (viTri == soLuong - 1) {
						viTri = 0;
					}
					else {
						viTri++;
					}
				}
			}
			else if (phim == 13) {
				check = viTri;
				// xoa du lieu cu, xoa box truoc do
				this->box[viTri].XoaBox(mauChon);
				this->box[viTri].XoaChu(Color_Black);
				break;
			}
		}
		if (nhanPhimMuiTen) {
			nhanPhimMuiTen = false;
			// xoa du lieu cu, xoa box truoc do
			this->box[viTriTruocDo].XoaBox(mauChon);
			this->box[viTriTruocDo].VeBox(Color_Black);
			this->box[viTriTruocDo].InChuoi(0, Color_Black);
			// in ra box duoc chon
			this->box[viTri].XoaBox(Color_Black);
			this->box[viTri].VeBox(mauChon);
			this->box[viTri].InChuoi(0, mauChon);
		}
	}
}