#include "Algorithms.h"

Algorithms::Algorithms() {
	this->A = NULL;
	this->size = 0;
	this->tocDo = 0;
}
Algorithms::~Algorithms() {
	this->A = NULL;
	delete[] this->A;
}

//-----Setter-----//
void Algorithms::NhapTocDo() {
	Box* khungNhap = new Box;
	// 148: số ô của console / 2 => Ra giữa - 18 độ dài của box
	khungNhap->SetAll(148 / 2 - 18, 18, 0);
	khungNhap->SetWHText(36, 3, "ENTER SPEED DELAY (MS):");
	khungNhap->VeBox(Color_Black);
	khungNhap->InChuoi(2, Color_Black);

	int whereX = WhereX();
	int speed;
	bool checkfail;
	// Nhập tốc độ
	do
	{
		checkfail = true;
		GotoXY(whereX + 3, 19);
		cin >> speed;
		if (cin.fail() || (speed < 0)) {
			// Xóa dữ liệu cũ
			GotoXY(whereX + 3, 19);
			cout << "                                             ";
			// Vẽ lại phần bị mất của box |
			GotoXY(whereX + 11, 19);
			cout << (char)179;
			cin.clear();
			cin.ignore();
			checkfail = false;
		}
	} while (checkfail == false);

	this->tocDo = speed;

	delete khungNhap;
}
void Algorithms::NhapSoLuong() {
	Box* khungNhap = new Box;
	// 148: số ô của console / 2 => Ra giữa - 14 độ dài của box
	khungNhap->SetAll(148 / 2 - 14, 8, 0);
	khungNhap->SetWHText(28, 3, "ENTER NUMBER ELEMENTS:");
	khungNhap->VeBox(Color_Black);
	khungNhap->InChuoi(2, Color_Black);

	// Nhập Số lượng phần tử
	int whereX = WhereX();
	int size;
	bool checkfail;
	do
	{
		checkfail = true;
		GotoXY(whereX + 1, 9);
		cin >> size;

		if (cin.fail() || (size < 2) || (size > 15)) {
			// Xóa dữ liệu cũ
			GotoXY(whereX + 1, 9);
			cout << "                                             ";
			// Vẽ lại phần bị mất của box |
			GotoXY(whereX + 4, 9);
			cout << (char)179;
			cin.clear();
			cin.ignore();
			checkfail = false;
		}
	} while (checkfail == false);

	// Cập nhật size
	this->size = size;
	this->A = new Box[size];

	delete khungNhap;
}

//------Input-----//
void Algorithms::NhapTuBanPhim() {
	ShowCur(true);
	this->NhapSoLuong();

	// 148: số ô trên chiều ngang console 
	// 44: số ô trên chiều dọc console
	// 2 cái này mình set mặc định cho dễ
	int chiaDeu = 148 / this->size;

	Box* khungNhap = new Box; // khung nhập từng phần tử

	for (int i = 0; i < size; i++)
	{
		// cập nhật mới khung nhập
		khungNhap->SetAll(148 / 2 - 14, 13, 0);
		khungNhap->SetWHText(28, 3, "ENTER ELEMENTS A[" + to_string(i + 1) + "]:");
		khungNhap->VeBox(Color_Black);
		khungNhap->InChuoi(2, Color_Black);

		int whereX = WhereX();
		bool checkfail;
		int x; // biến nhập giá trị
		do
		{
			checkfail = true;
			GotoXY(whereX + 1, 14);
			cin >> x;

			if (cin.fail()) {
				// Xóa dữ liệu cũ
				GotoXY(whereX + 1, 14);
				cout << "                                                         ";
				// Vẽ lại phần bị mất của box |
				GotoXY(whereX + 6, 14);
				cout << (char)179;
				cin.clear();
				cin.ignore();

				checkfail = false;
			}
		} while (checkfail == false);

		// Set Box
		this->A[i].SetAll((chiaDeu * (i + 1)) - (chiaDeu / 2) - 3, 15 / 2, x);
		// Chia Console ra các phần bằng nhau cho số lượng box 
		// Vị trí x = W / size * {vị trí cái box} - 1/2 độ dài (chia đều) - 1/2 độ dài cái box
		// Ở đây set mặc định độ dài cái box là 10 => 1/2 * 10 = 5
	}

	this->NhapTocDo();
	ShowCur(false);
	delete khungNhap;
}
void Algorithms::SinhNgauNhien() {
	ShowCur(true);
	this->NhapSoLuong();

	// 148: số ô trên chiều ngang console 
	// 44: số ô trên chiều dọc console
	// 2 cái này mình set mặc định cho dễ
	int chiaDeu = 148 / size;
	int whereX, checkfail, max, min;
	Box* khungNhap = new Box;

	// Nhập max
	khungNhap->SetAll(148 / 2 - 30, 13, 0);
	khungNhap->SetWHText(28, 3, "ENTER VALUE MIN:");
	khungNhap->VeBox(Color_Black);
	khungNhap->InChuoi(2, Color_Black);
	whereX = WhereX();
	do
	{
		checkfail = true;
		GotoXY(whereX + 2, 14);
		cin >> min;

		if (cin.fail()) {
			// Xóa dữ liệu cũ
			GotoXY(whereX + 2, 14);
			cout << "                                                         ";
			// Vẽ lại phần bị mất của box |
			GotoXY(whereX + 4, 14);
			cout << (char)179;
			cin.clear();
			cin.ignore();

			checkfail = false;
		}
	} while (checkfail == false);


	// Nhập min
	khungNhap->SetAll(148 / 2 + 3, 13, 0);
	khungNhap->SetWHText(28, 3, "ENTER VALUE MAX:");
	khungNhap->VeBox(Color_Black);
	khungNhap->InChuoi(2, Color_Black);
	whereX = WhereX();
	do
	{
		checkfail = true;
		GotoXY(whereX + 2, 14);
		cin >> max;

		if (cin.fail()) {
			// Xóa dữ liệu cũ
			GotoXY(whereX + 2, 14);
			cout << "                                                         ";
			// Vẽ lại phần bị mất của box |
			GotoXY(whereX + 4, 14);
			cout << (char)179;
			cin.clear();
			cin.ignore();

			checkfail = false;
		}
	} while (checkfail == false);

	for (int i = 0; i < size; i++)
	{
		int x = rand() % (max - min + 1) + min;
		this->A[i].SetAll((chiaDeu * (i + 1)) - (chiaDeu / 2) - 3, 15 / 2, x);
	}

	this->NhapTocDo();
	ShowCur(false);
	delete khungNhap;
}
void Algorithms::NhapTuFile() {
	// tu tu
}