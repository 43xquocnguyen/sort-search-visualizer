#pragma once
#include "Algorithms.h"

class Sort : public Algorithms
{
protected:
	bool isIncrease;

public:
	Sort();
	~Sort();

	//------Setter------//
	void NhapTangDanHoacGiamDan(bool);

	//------Output------//
	virtual void Sorting() = 0;
};

