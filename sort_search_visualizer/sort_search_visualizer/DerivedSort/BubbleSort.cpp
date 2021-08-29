#include "BubbleSort.h"

BubbleSort::BubbleSort() : Sort() {

}
BubbleSort::~BubbleSort() {

}

//------Output------//
void BubbleSort::Sorting() {
	ShowCur(false); // ẩn trỏ chuột
	int size = this->size, i, j; //
	string nghichThe;

	// In ra toàn dãy số
	for (i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Bubble Sort");
	Sleep(this->tocDo);

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			Sleep(this->tocDo);

			// so sánh
			if (this->A[j].GetValue() > this->A[j + 1].GetValue()) {
				nghichThe = ">";
			}
			else if (this->A[j].GetValue() < this->A[j + 1].GetValue()) {
				nghichThe = "<";
			}
			else nghichThe = "=";

			// GREEN thằng đang chọn (j và j+1)
			this->A[j].VeBox(Color_Green);
			this->A[j].InChuoi(0, Color_Green);
			this->A[j + 1].VeBox(Color_Green);
			this->A[j + 1].InChuoi(0, Color_Green);
			Text_Mess_Center(24, Color_White, "SELECT: A[" + to_string(j) + "] AND A[" + to_string(j + 1) + "]");
			Sleep(this->tocDo);

			Text_Mess_Center(25, Color_White, "A[" + to_string(j) + "] " + nghichThe + " A[" + to_string(j + 1) + "]");
			Sleep(this->tocDo);

			if (SoSanh2SoTheoDieuKien(this->A[j].GetValue(), this->A[j + 1].GetValue(), this->isIncrease))
			{
				// So sánh
				HoanDoi2Box(this->A[j], this->A[j + 1]);

				// Mess đảo chỗ
				Text_Mess_Center(26, Color_Red, "SWAP: A[" + to_string(j) + "] <==> A[" + to_string(j + 1) + "]");
			}
			else {
				Text_Mess_Center(26, Color_Green, "NO SWAP");
			}

			this->A[j].VeBox(Color_Black);
			this->A[j].InChuoi(0, Color_Black);
			this->A[j + 1].VeBox(Color_Black);
			this->A[j + 1].InChuoi(0, Color_Black);

			// Xóa 3 dòng mess
			Sleep(this->tocDo * 2);
			Text_Mess_Center(24, Color_Green, "                               ");
			Text_Mess_Center(25, Color_Green, "                               ");
			Text_Mess_Center(26, Color_Green, "                               ");
			Sleep(this->tocDo);
		}

		// BLUE: đã đúng vị trí
		this->A[size - i - 1].VeBox(Color_Blue);
		this->A[size - i - 1].InChuoi(0, Color_Blue);
	}

	// BLUE: đã đúng vị trí
	this->A[0].VeBox(Color_Blue);
	this->A[0].InChuoi(0, Color_Blue);

	// Mess đã sort xong
	Text_Mess_Center(24, Color_Blue, "BUBBLE SORT. DONE!");
}
