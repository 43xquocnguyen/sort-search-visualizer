#include "JumpSearch.h"

JumpSearch::JumpSearch() : Search() {

}
JumpSearch::~JumpSearch() {

}

//------Output------//
void JumpSearch::Searching() {
	// Thuật toán cần được sắp xếp trước
	this->SapXep();

	int size = this->size;
	ShowCur(false);

	// hiển thị ra mảng cần search
	for (int i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Jump Search");

	Sleep(this->tocDo);

	// Jump Search
	bool checkPhanTuTonTai = false;
	int step = sqrt(size);
	int prev = 0;
	int jump = 0;

	while (true)
	{
		prev = jump;
		jump += step;
	
		if (jump > size - 1) {
			jump = size - 1;
			prev = jump - step;
			if (this->A[jump].GetValue() >= this->key) checkPhanTuTonTai = true;
			break;
		}

		// GREEN 2 thằng jump và prev
		this->A[prev].VeBox(Color_Green);
		this->A[prev].InChuoi(0, Color_Green);
		Text_Mess_Center(25, Color_White, "PREV: A[" + to_string(prev) + "]");
		Sleep(this->tocDo);
		this->A[jump].VeBox(Color_Green);
		this->A[jump].InChuoi(0, Color_Green);
		Text_Mess_Center(26, Color_White, "JUMP: A[" + to_string(jump) + "]");
		// Xóa đi dữ liệu cũ
		Sleep(this->tocDo);
		this->A[jump].VeBox(Color_Black);
		this->A[jump].InChuoi(0, Color_Black);
		this->A[prev].VeBox(Color_Black);
		this->A[prev].InChuoi(0, Color_Black);
		Text_Mess_Center(25, Color_White, "                             ");
		Text_Mess_Center(26, Color_White, "                             ");
		Sleep(this->tocDo);

		if (this->A[jump].GetValue() >= this->key) {
			checkPhanTuTonTai = true;
			break;
		}
	}

	if (checkPhanTuTonTai) {
		// GREEN 2 thằng jump và prev
		this->A[prev].VeBox(Color_Green);
		this->A[prev].InChuoi(0, Color_Green);
		this->A[jump].VeBox(Color_Green);
		this->A[jump].InChuoi(0, Color_Green);
	}
	else {
		Text_Mess_Center(25, Color_White, "NOT FOUND!");
		_getch();
		return;
	}
	
	
	for (int i = prev; i <= jump; i++)
	{
		// In thằng thứ i đang kiểm tra thành màu GREY
		this->A[i].VeBox(Color_Grey);
		this->A[i].InChuoi(0, Color_Grey);
		Text_Mess_Center(25, Color_White, "SELECT A[" + to_string(i) + "]");

		Sleep(this->tocDo * 2);

		Text_Mess_Center(25, Color_White, "                         "); // clearLine

		// Nếu tìm thấy
		if (this->A[i].GetValue() == this->key) {
			// In thằng thứ i thành màu GREEN
			this->A[i].VeBox(Color_Green);
			this->A[i].InChuoi(0, Color_Green);
			Text_Mess_Center(25, Color_Green, "FOUND");
			// Trả box jump lại bth
			if (jump != i) {
				this->A[jump].VeBox(Color_Black);
				this->A[jump].InChuoi(0, Color_Black);
			}
			Sleep(this->tocDo * 5);
			Text_Mess_Center(25, Color_Green, "FOUND A[" + to_string(i) + "]");
			break;
		}
		// Nếu không thấy
		else
		{
			// In thằng thứ i thành màu RED
			this->A[i].VeBox(Color_Red);
			this->A[i].InChuoi(0, Color_Red);
			Text_Mess_Center(25, Color_Red, "NOT X");

			Sleep(this->tocDo);

			// Trả thằng thứ i thành màu BLACk
			this->A[i].VeBox(Color_Black);
			this->A[i].InChuoi(0, Color_Black);
		}

		Text_Mess_Center(25, Color_White, "                         "); // clearLine
		Sleep(this->tocDo);
	}
}