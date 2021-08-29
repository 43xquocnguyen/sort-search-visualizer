#include "InsertionSort.h"

InsertionSort::InsertionSort() : Sort() {

}
InsertionSort::~InsertionSort() {

}

//------Output------//
void InsertionSort::Sorting() {
	ShowCur(false); // ẩn trỏ chuột
	int size = this->size, i, j, key;

	// In ra toàn dãy số
	for (i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Insertion Sort");
	Sleep(this->tocDo);


	// Insertion Sort
	for (i = 1; i < size; i++)
	{
		key = this->A[i].GetValue();
		j = i - 1;

		// AQUA dãy đã chèn
		this->A[j].VeBox(Color_Aqua);
		this->A[j].InChuoi(0, Color_Aqua);

		// RED thằng cần chèn
		Sleep(this->tocDo);
		this->A[i].VeBox(Color_Red);
		this->A[i].InChuoi(0, Color_Red);
		Text_Mess_Center(24, Color_White, "KEY INSERT: A[" + to_string(i) + "]");

		Sleep(this->tocDo);

		while (j >= 0 && 
			SoSanh2SoTheoDieuKien(this->A[j].GetValue(), key, this->isIncrease))
		{
			this->A[j].VeBox(Color_Green);
			this->A[j].InChuoi(0, Color_Green);
			Sleep(this->tocDo);

			this->A[j + 1].SetValue(this->A[j].GetValue());

			this->A[j].VeBox(Color_Aqua);
			this->A[j].InChuoi(0, Color_Aqua);

			j--;
		}
		
		// Mess vị trí cần insert
		Text_Mess_Center(25, Color_White, "POS INSERT: " + to_string(j + 1));

		// Mess insert
		Sleep(this->tocDo);
		Text_Mess_Center(26, Color_LightRed, "INSERT A[" + to_string(i) + "] IN POS: " + to_string(j + 1));
		this->A[j + 1].SetValue(key);

		// Xóa mess
		Sleep(this->tocDo);
		Text_Mess_Center(24, Color_White, "                                 ");
		Text_Mess_Center(25, Color_White, "                                 ");
		Text_Mess_Center(26, Color_White, "                                    ");

		// In lại dãy đã đúng
		for (int k = 0; k <= i; k++)
		{
			this->A[k].VeBox(Color_Aqua);
			this->A[k].InChuoi(0, Color_Aqua);
		}

		Sleep(this->tocDo);
	}

	// Mess đã sort xong
	Text_Mess_Center(24, Color_Blue, "INSERTION SORT. DONE!");
}