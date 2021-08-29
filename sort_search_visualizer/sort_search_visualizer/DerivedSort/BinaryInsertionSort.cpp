#include "BinaryInsertionSort.h"

BinaryInsertionSort::BinaryInsertionSort() : Sort() {

}
BinaryInsertionSort::~BinaryInsertionSort() {

}

//------Output------//
// true: Tang Dan | false: Giam Dan
void BinaryInsertionSort::Sorting() {
	ShowCur(false); // ẩn trỏ chuột
	int size = this->size, i, j, key; //

	// In ra toàn dãy số
	for (i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Binary Insertion Sort");
	Sleep(this->tocDo);

	// Binary Insertion Sort
	int left, right, mid;
	for (i = 1; i < size; i++)
	{
		key = this->A[i].GetValue();
		left = 0;
		right = i - 1;

		// AQUA dãy đã chèn
		this->A[i - 1].VeBox(Color_Aqua);
		this->A[i - 1].InChuoi(0, Color_Aqua);
		
		// RED thằng cần chèn
		Sleep(this->tocDo);
		this->A[i].VeBox(Color_Red);
		this->A[i].InChuoi(0, Color_Red);
		Text_Mess_Center(24, Color_White, "KEY INSERT: A[" + to_string(i) + "]");
		Sleep(this->tocDo);

		while (left <= right)
		{
			// Select left right
			Text_Mess_Center(25, Color_LightAqua, "SELECT LEFT: A[" + to_string(left) + "] AND RIGHT: A[" + to_string(right) + "]");
			Sleep(this->tocDo);

			// mid
			mid = (left + right) / 2;
			this->A[mid].VeBox(Color_Green);
			this->A[mid].InChuoi(0, Color_Green);
			Text_Mess_Center(26, Color_LightPurple, "MID: A[" + to_string(mid) + "]");
			Sleep(this->tocDo);


			if (SoSanh2SoTheoDieuKien(this->A[mid].GetValue(), key, this->isIncrease)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}

			Sleep(this->tocDo);
			this->A[mid].VeBox(Color_Aqua);
			this->A[mid].InChuoi(0, Color_Aqua);
			Text_Mess_Center(25, Color_White, "                                     ");
			Text_Mess_Center(26, Color_White, "                                     ");
			Sleep(this->tocDo);
		}

		// Mess vị trí insert
		Text_Mess_Center(25, Color_Green, "INSERT POS: " + to_string(mid + 1));

		for (int j = i - 1; j >= left; j--)
		{
			this->A[j + 1].SetValue(this->A[j].GetValue());
		}

		this->A[left].SetValue(key);

		// In ra dãy số đã đúng vị trí
		for (int k = 0; k <= i; k++)
		{
			this->A[k].VeBox(Color_Aqua);
			this->A[k].InChuoi(0, Color_Aqua);
		}

		Sleep(this->tocDo);
		Text_Mess_Center(24, Color_White, "                                     ");
		Text_Mess_Center(25, Color_White, "                                     ");
		Text_Mess_Center(26, Color_White, "                                     ");
		Text_Mess_Center(27, Color_White, "                                     ");
		Sleep(this->tocDo);
	}

	// Mess đã sort xong
	Text_Mess_Center(24, Color_Blue, "BINARY INSERTION SORT. DONE!");
}