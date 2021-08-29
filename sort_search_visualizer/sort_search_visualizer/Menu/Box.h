#pragma once
#include "../Graphics&Support/Graphic.h"
#include <string>
using namespace std;

class Box
{
private:
	int x, y, w, h;
	int value;
	string text;

public:
	Box();
	Box(const Box&);
	~Box();

	// x, y, value
	void SetAll(int, int, int);
	void SetWHText(int, int, string);
	void SetValue(int);

	int GetValue();

	// Color
	void VeBox(int);
	// CanLe: 0-giua | 1-phai | ..-trai
	// Color
	void InChuoi(int, int);
	void InThongBao(int, string);


	// Box Chon hoac Box thuong (true or false)
	// Xoa nen: true or false
	void XoaVienBox(bool);
	void XoaChu(bool);
	// Box Chon hoac Box thuong (true or false)
	void XoaBox(bool);
};

