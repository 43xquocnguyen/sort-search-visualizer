#include "BinarySearch.h"

BinarySearch::BinarySearch() : Search() {

}
BinarySearch::~BinarySearch() {

}

//------Output------//
void BinarySearch::Searching() {
	// Thuật toán cần được sắp xếp trước
	this->SapXep();

	int size = this->size;
	ShowCur(false);

	// hiện thị ra mảng cần search
	for (int i = 0; i < size; i++)
	{
		this->A[i].VeBox(Color_Black);
		this->A[i].InChuoi(0, Color_Black);
	}

	Text_Prepering("Binary Search");

	Sleep(this->tocDo);

	// Binary Search
	// left, right, mid
	int left = 0, right = size - 1, mid;
	bool notFound = true;

	do
	{
		int leftCu = left, rightCu = right;

		// In 2 thằng left/right lên trước
		this->A[left].VeBox(Color_Aqua);
		this->A[left].InChuoi(0, Color_Aqua);
		this->A[right].VeBox(Color_Aqua);
		this->A[right].InChuoi(0, Color_Aqua);
		Text_Mess_Center(25, Color_Aqua, "SELECT LEFT: A[" + to_string(left) + "] & " "RIGHT: A[" + to_string(right) + "]");

		Sleep(this->tocDo);

		// In thằng mid của 2 thằng left-right
		mid = (left + right) / 2;
		this->A[mid].VeBox(Color_Grey);
		this->A[mid].InChuoi(0, Color_Grey);
		Text_Mess_Center(26, Color_Grey, "SELECT MID A[" + to_string(mid) +"]");

		Sleep(this->tocDo);

		// Tìm thấy: In thằng mid thành màu GREEN
		if (this->A[mid].GetValue() == this->key) {
			notFound = false; 
			this->A[mid].VeBox(Color_Green);
			this->A[mid].InChuoi(0, Color_Green);
			Sleep(this->tocDo);
			break;
		}
		// Không thấy: In thằng mid thành màu RED -> Black -> Lặp bước tiếp theo
		else {
			// In thằng mid RED
			this->A[mid].VeBox(Color_Red);
			this->A[mid].InChuoi(0, Color_Red);
			Text_Mess_Center(27, Color_Red, "NOT X");

			Sleep(this->tocDo);

			// Trả thằng mid về lại BLACK
			this->A[mid].VeBox(Color_Black);
			this->A[mid].InChuoi(0, Color_Black);

			// Xử lí bước lặp kế tiếp
			if (this->A[mid].GetValue() > this->key) {
				right = mid - 1;
				Text_Mess_Center(24, Color_White, "RIGHT = MID - 1");
			}
			else {
				left = mid + 1;
				Text_Mess_Center(24, Color_White, "LEFT = MID + 1");
			}
		}

		// Trả 2 thằng left/right cũ về lại màu BLACK
		if (leftCu != mid) {
			this->A[leftCu].VeBox(Color_Black);
			this->A[leftCu].InChuoi(0, Color_Black);
			this->A[left].VeBox(Color_Black);
			this->A[left].InChuoi(0, Color_Black);
		}
		if (rightCu != mid) {
			this->A[rightCu].VeBox(Color_Black);
			this->A[rightCu].InChuoi(0, Color_Black);
			this->A[right].VeBox(Color_Black);
			this->A[right].InChuoi(0, Color_Black);
		}

		Sleep(this->tocDo);
		Text_Mess_Center(24, Color_Aqua, "                                ");
		Text_Mess_Center(25, Color_Aqua, "                                ");
		Text_Mess_Center(26, Color_Aqua, "                                ");
		Text_Mess_Center(27, Color_Aqua, "                                ");
		Text_Mess_Center(28, Color_Aqua, "                                ");

	} while (left <= right);

	if (notFound) {
		Text_Mess_Center(24, Color_White, "NOT FOUND");
	}
	else {
		Text_Mess_Center(24, Color_Green, "FOUND");
		Sleep(this->tocDo);
		Text_Mess_Center(25, Color_Green, "POS: A[" + to_string(mid) + "]");
	}
}