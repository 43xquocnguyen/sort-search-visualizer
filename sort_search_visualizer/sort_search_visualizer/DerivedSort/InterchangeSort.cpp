#include "InterchangeSort.h"

InterchangeSort::InterchangeSort() : Sort() {

}
InterchangeSort::~InterchangeSort() {

}

//------Output------//
void InterchangeSort::Sorting() {
	ShowCur(false); // ẩn trỏ chuột
	int size = this->size, i, j; //
	string nghichThe;

	// In ra toàn dãy số
	for (i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Interchange Sort");
	Sleep(this->tocDo);

	for (i = 0; i < size - 1; i++)
	{
		// GREEN thằng đang chọn
		this->A[i].VeBox(Color_Green);
		this->A[i].InChuoi(0, Color_Green);
		Text_Mess_Center(24, Color_White, "SELECT: A[" + to_string(i) + "]");

		for (j = i + 1; j < size; j++)
		{
			Sleep(this->tocDo);
			// so sánh
			if (this->A[i].GetValue() > this->A[j].GetValue()) {
				nghichThe = ">";
			}
			else if (this->A[i].GetValue() < this->A[j].GetValue()) {
				nghichThe = "<";
			}
			else nghichThe = "=";

			// RED thằng đang so sánh
			this->A[j].VeBox(Color_Red);
			this->A[j].InChuoi(0, Color_Red);

			// In mess so sánh
			Text_Mess_Center(25, Color_White, "COMPARE: A[" + to_string(i) + "] " + nghichThe + " A[" + to_string(j) + "]");
			Sleep(this->tocDo);

			if (SoSanh2SoTheoDieuKien(this->A[i].GetValue(), this->A[j].GetValue(), this->isIncrease))
			{
				// So sánh
				HoanDoi2Box(this->A[i], this->A[j]);

				// Mess đảo chỗ
				Text_Mess_Center(26, Color_Red, "SWAP: A[" + to_string(i) + "] <==> A[" + to_string(j) + "]");
			
				// GREEN lại I mới
				this->A[i].VeBox(Color_Green);
				this->A[i].InChuoi(0, Color_Green);
			}	
			else {
				Text_Mess_Center(26, Color_Green, "NO SWAP");
			}

			// Xóa 2 dòng so sánh
			Sleep(this->tocDo * 2);
			Text_Mess_Center(25, Color_Green, "                               ");
			Text_Mess_Center(26, Color_Green, "                               ");

			// BLACK: thằng J
			this->A[j].VeBox(Color_Black);
			this->A[j].InChuoi(0, Color_Black);
			Sleep(this->tocDo);
		}

		// BLUE: đã đúng thứ tự
		Text_Mess_Center(24, Color_White, "                                 ");
		this->A[i].VeBox(Color_Blue);
		this->A[i].InChuoi(0, Color_Blue);
		Sleep(this->tocDo);
	}

	// BLUE: thằng cuối
	this->A[i].VeBox(Color_Blue);
	this->A[i].InChuoi(0, Color_Blue);

	// Mess đã sort xong
	Text_Mess_Center(24, Color_Blue, "INTERCHANGE SORT. DONE!");
}