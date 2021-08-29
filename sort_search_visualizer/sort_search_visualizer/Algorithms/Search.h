#pragma once
#include "Algorithms.h"

class Search : public Algorithms
{
protected:
	int key;
	void SapXep();
public:
	Search();
	~Search();

	//------Setter------//
	void NhapPhanTuCanTim();

	//------Input------//
	void NhapTuBanPhim();
	void SinhNgauNhien();
	void NhapTuFile();

	//------Output------//
	virtual void Searching() = 0;
};

