#pragma once Algorithms
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../Graphics&Support/Graphic.h"
#include "../Menu/Box.h"
#include "../Graphics&Support/HoTro.h"
using namespace std;

class Algorithms
{
protected:
	Box* A; // mảng A
	int size; // size mảng
	int tocDo; // tốc độ thực hiện

public:
	Algorithms();
	~Algorithms();

	//-----Setter-----//
	void NhapTocDo();
	void NhapSoLuong();

	//------Input-----//
	virtual void NhapTuBanPhim();
	virtual void SinhNgauNhien();
	virtual void NhapTuFile();

};

