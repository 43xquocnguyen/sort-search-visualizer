#include "ShakerSort.h"

ShakerSort::ShakerSort() : Sort() {

}
ShakerSort::~ShakerSort() {

}

//------Output------//
void ShakerSort::Sorting() {
	ShowCur(false); // ẩn trỏ chuột
	int size = this->size, i, j; //
	string nghichThe;

	// In ra toàn dãy số
	for (i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Shaker Sort");
	Sleep(this->tocDo);

	int left = 0, right = size - 1, k = 0;

	while (left < right)
	{
		// Lượt đi
		for (i = left; i < right; i++)
		{
			Sleep(this->tocDo);

			// so sánh
			if (this->A[i].GetValue() > this->A[i + 1].GetValue()) {
				nghichThe = ">";
			}
			else if (this->A[i].GetValue() < this->A[i + 1].GetValue()) {
				nghichThe = "<";
			}
			else nghichThe = "=";

			// GREEN thằng đang chọn (i và i+1)
			this->A[i].VeBox(Color_Green);
			this->A[i].InChuoi(0, Color_Green);
			this->A[i + 1].VeBox(Color_Green);
			this->A[i + 1].InChuoi(0, Color_Green);
			Text_Mess_Center(24, Color_White, "SELECT: A[" + to_string(i) + "] AND A[" + to_string(i + 1) + "]");
			Sleep(this->tocDo);

			Text_Mess_Center(25, Color_White, "A[" + to_string(i) + "] " + nghichThe + " A[" + to_string(i + 1) + "]");
			Sleep(this->tocDo);

			if (SoSanh2SoTheoDieuKien(this->A[i].GetValue(), this->A[i + 1].GetValue(), this->isIncrease))
			{
				// So sánh
				HoanDoi2Box(this->A[i], this->A[i + 1]);

				// Mess đảo chỗ
				Text_Mess_Center(26, Color_Red, "SWAP: A[" + to_string(i) + "] <==> A[" + to_string(i + 1) + "]");
			}
			else {
				Text_Mess_Center(26, Color_Green, "NO SWAP");
			}

			k = i;

			// Xóa 3 dòng mess
			Sleep(this->tocDo * 2);
			Text_Mess_Center(24, Color_Green, "                               ");
			Text_Mess_Center(25, Color_Green, "                               ");
			Text_Mess_Center(26, Color_Green, "                               ");
			this->A[i].VeBox(Color_Black);
			this->A[i].InChuoi(0, Color_Black);
			this->A[i + 1].VeBox(Color_Black);
			this->A[i + 1].InChuoi(0, Color_Black);
			Sleep(this->tocDo);
		}

		// AQUA: đã đúng vị trí | i = thằng cuối
		this->A[i].VeBox(Color_Aqua);
		this->A[i].InChuoi(0, Color_Aqua);

		right = k;

		// Lượt về
		for (i = right; i > left; i--)
		{
			Sleep(this->tocDo);

			// so sánh
			if (this->A[i].GetValue() > this->A[i + 1].GetValue()) {
				nghichThe = ">";
			}
			else if (this->A[i].GetValue() < this->A[i + 1].GetValue()) {
				nghichThe = "<";
			}
			else nghichThe = "=";

			// GREEN thằng đang chọn (i-1 và i)
			this->A[i - 1].VeBox(Color_Green);
			this->A[i - 1].InChuoi(0, Color_Green);
			this->A[i].VeBox(Color_Green);
			this->A[i].InChuoi(0, Color_Green);

			Sleep(this->tocDo);

			Text_Mess_Center(24, Color_White, "SELECT: A[" + to_string(i - 1) + "] AND A[" + to_string(i) + "]");
			Sleep(this->tocDo);

			Text_Mess_Center(25, Color_White, "A[" + to_string(i - 1) + "] " + nghichThe + " A[" + to_string(i) + "]");
			Sleep(this->tocDo);

			if (SoSanh2SoTheoDieuKien(this->A[i - 1].GetValue(), this->A[i].GetValue(), this->isIncrease))
			{
				// So sánh
				HoanDoi2Box(this->A[i - 1], this->A[i]);

				// Mess đảo chỗ
				Text_Mess_Center(26, Color_Red, "SWAP: A[" + to_string(i - 1) + "] <==> A[" + to_string(i) + "]");
			}
			else {
				Text_Mess_Center(26, Color_Green, "NO SWAP");
			}

			k = i;

			// Xóa 3 dòng mess
			Sleep(this->tocDo * 2);
			Text_Mess_Center(24, Color_Green, "                               ");
			Text_Mess_Center(25, Color_Green, "                               ");
			Text_Mess_Center(26, Color_Green, "                               ");
			this->A[i - 1].VeBox(Color_Black);
			this->A[i - 1].InChuoi(0, Color_Black);
			this->A[i].VeBox(Color_Black);
			this->A[i].InChuoi(0, Color_Black);

			Sleep(this->tocDo);
		}

		// AQUA: Đã đúng vị trí | i = thằng đầu 
		this->A[i].VeBox(Color_Aqua);
		this->A[i].InChuoi(0, Color_Aqua);

		left = k;
	}

	// Đã đúng vị trí
	this->A[left].VeBox(Color_Aqua);
	this->A[left].InChuoi(0, Color_Aqua);

	// Mess đã sort xong
	Text_Mess_Center(24, Color_Blue, "SHAKER SORT. DONE!");
}