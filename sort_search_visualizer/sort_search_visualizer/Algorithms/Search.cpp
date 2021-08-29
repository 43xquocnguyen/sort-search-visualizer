#include "Search.h"

Search::Search() : Algorithms() {
	this->key = 0;
}
Search::~Search() {

}
//-----Sắp Xếp Mảng Đối Với Search Cần Mảng đã Sort----//
void Search::SapXep() {
	int size = this->size;	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (this->A[i].GetValue() > this->A[j].GetValue()) {
				int t = this->A[i].GetValue();
				this->A[i].SetValue(this->A[j].GetValue());
				this->A[j].SetValue(t);
			}
		}
	}
}
//-----Setter-----//
void Search::NhapPhanTuCanTim() {
	ShowCur(true);
	Box* khungNhap = new Box;
	// 148: số ô của console / 2 => Ra giữa - 18 độ dài của box
	khungNhap->SetAll(148 / 2 - 15, 23, 0);
	khungNhap->SetWHText(30, 3, "ENTER KEY NEED FIND:");
	khungNhap->VeBox(Color_Black);
	khungNhap->InChuoi(2, Color_Black);

	int whereX = WhereX();
	int key;
	bool checkfail;
	// Nhập tốc độ
	do
	{
		checkfail = true;
		GotoXY(whereX + 2, 24);
		cin >> key;
		if (cin.fail() || (key < 0)) {
			// Xóa dữ liệu cũ
			GotoXY(whereX + 2, 23);
			cout << "                                             ";
			// Vẽ lại phần bị mất của box |
			GotoXY(whereX + 6, 23);
			cout << (char)179;
			cin.clear();
			cin.ignore();
			checkfail = false;
		}
	} while (checkfail == false);
	ShowCur(false);

	this->key = key;

	delete khungNhap;
}

//-----Input-----/
void Search::NhapTuBanPhim() {
	Algorithms::NhapTuBanPhim();
	this->NhapPhanTuCanTim();
}
void Search::SinhNgauNhien() {
	Algorithms::SinhNgauNhien();
	this->NhapPhanTuCanTim();
}
void Search::NhapTuFile() {
	Algorithms::NhapTuFile();
	//this->NhapPhanTuCanTim();
}