#include "Box.h"

class Menu
{
private:
	int x, y; // x, y 
	int w, h; // chiều dài, chiều rộng
	int soLuong; // số lượng
	int tColor; // màu sắc
	Box *box; // gồm {soLuong} phần tử
	string* text; // gồm {soLuong} phần tử
public:
	Menu();
	~Menu();

	// x, y, w, h, tColor, soLuong, *text
	void SetMenu(int, int, int, int, int, int, string*);
	void VeMenu();
	void Chay(int &);
};