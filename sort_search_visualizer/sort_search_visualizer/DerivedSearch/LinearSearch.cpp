#include "LinearSearch.h"

LinearSearch::LinearSearch() : Search() {

}
LinearSearch::~LinearSearch() {

}

//------Output------//
void LinearSearch::Searching() {
	int size = this->size;
	ShowCur(false);

	// hiển thị ra mảng cần search
	for (int i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Linear Search");

	Sleep(this->tocDo);

	// Linear Search
	for (int i = 0; i < size - 1; i++)
	{
		// In thằng thứ i đang kiểm tra thành màu GREY
		this->A[i].VeBox(Color_Grey);
		this->A[i].InChuoi(0, Color_Grey);
		Text_Mess_Center(25, Color_White, "SELECT");

		Sleep(this->tocDo * 2);

		Text_Mess_Center(25, Color_White, "                         "); // clearLine

		// Nếu tìm thấy
		if (this->A[i].GetValue() == this->key) {
			// In thằng thứ i thành màu GREEN
			this->A[i].VeBox(Color_Green);
			this->A[i].InChuoi(0, Color_Green);
			Text_Mess_Center(25, Color_Green, "FOUND");
			Sleep(this->tocDo * 5);
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