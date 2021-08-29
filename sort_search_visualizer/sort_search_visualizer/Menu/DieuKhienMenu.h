#pragma once
// include sort
#include "../DerivedSort/InterchangeSort.h"
#include "../DerivedSort/BubbleSort.h"
#include "../DerivedSort/SelectionSort.h"
#include "../DerivedSort/ShakerSort.h"
#include "../DerivedSort/InsertionSort.h"
#include "../DerivedSort/BinaryInsertionSort.h"
// include search
#include "../DerivedSearch/LinearSearch.h"
#include "../DerivedSearch/BinarySearch.h"
#include "../DerivedSearch/JumpSearch.h"
// include support
#include "Menu.h"
#include "../Graphics&Support/HoTro.h"


class DieuKhienMenu
{
private:
	vector<Menu*> menu;
	Sort* sort;
	Search* search;
public:
	DieuKhienMenu();
	~DieuKhienMenu();

	void OnScreen();
	void KhoiTao();
	void ChayChuongTrinh();
};

