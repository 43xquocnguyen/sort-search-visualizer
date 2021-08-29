#include "DieuKhienMenu.h"

DieuKhienMenu::DieuKhienMenu() {
	this->sort = NULL;
	this->search = NULL;
}
DieuKhienMenu::~DieuKhienMenu() {
	delete this->sort;
	delete this->search;
}

void DieuKhienMenu::OnScreen() {
	ResizeConsole(WidthConsole, HeightConsole); // set WH
	RemoveScrollBar(); // xóa scrool bar
	DisableResizeWindow();
	DisableCtrButton(0, 0, 1);
	//DisableSelection();
	srand(time(NULL));
}
void DieuKhienMenu::KhoiTao() {
	// Menu chinh [0]
	string* str1 = new string[4];
	str1[0] = "LET'S START SORT";
	str1[1] = "LET'S START SEARCH";
	str1[2] = "ABOUT ME (QUOC NGUYEN)";
	str1[3] = "EXIT";
	Menu* m1 = new Menu;
	m1->SetMenu(148 / 2 - 18, 15, 36, 3, Color_Red, 4, str1);
	this->menu.push_back(m1);

#pragma region Sort
	// Menu chon sort [1]
	//string* str2 = new string[13];
	//str2[0] = "INTERCHANGE SORT";
	//str2[1] = "BUBBLE SORT";
	//str2[2] = "SHAKER SORT";
	//str2[3] = "SELECTION SORT";
	//str2[4] = "INSERTION SORT";
	//str2[5] = "BINARY INSERTION SORT";
	//str2[6] = "SHELL SORT";
	//str2[7] = "COUNTING SORT";
	//str2[8] = "RADIX SORT";
	//str2[9] = "HEAP SORT";
	//str2[10] = "QUICK SORT";
	//str2[11] = "MERGE SORT";
	//str2[12] = "BACK";
	//Menu* m2 = new Menu;
	//m2->SetMenu(148 / 2 - 18, 3, 36, 3, Color_Red, 13, str2);
	//this->menu.push_back(m2);
	string* str2 = new string[7];
	str2[0] = "INTERCHANGE SORT";
	str2[1] = "BUBBLE SORT";
	str2[2] = "SHAKER SORT";
	str2[3] = "SELECTION SORT";
	str2[4] = "INSERTION SORT";
	str2[5] = "BINARY INSERTION SORT";
	str2[6] = "BACK";
	Menu* m2 = new Menu;
	m2->SetMenu(148 / 2 - 18, 10, 36, 3, Color_Red, 7, str2);
	this->menu.push_back(m2);

	// Menu chon input [2]
	string* str3 = new string[4];
	str3[0] = "KEYBOARD INPUT";
	str3[1] = "RANDOM INPUT";
	str3[2] = "FILE INPUT";
	str3[3] = "BACK TO MAIN MENU";
	Menu* m3 = new Menu;
	m3->SetMenu(148 / 2 - 18, 13, 36, 3, Color_Red, 4, str3);
	this->menu.push_back(m3);

	// Menu chon ins/des [3]
	string* str4 = new string[3];
	str4[0] = "INCREASE";
	str4[1] = "DECRESSE";
	str4[2] = "BACK TO MAIN MENU";
	Menu* m4 = new Menu;
	m4->SetMenu(148 / 2 - 18, 13, 36, 3, Color_Red, 3, str4);
	this->menu.push_back(m4);
#pragma endregion

#pragma region Search
	// Menu chon search [4]
	string* str5 = new string[4];
	str5[0] = "LINEAR SEARCH";
	str5[1] = "BINARY SEARCH (SORTED ARRAY)";
	str5[2] = "JUMP SEARCH (SORTED ARRAY)";
	str5[3] = "BACK TO MAIN MENU";
	Menu* m5 = new Menu;
	m5->SetMenu(148 / 2 - 18, 13, 36, 3, Color_Red, 4, str5);
	this->menu.push_back(m5);
#pragma endregion

}
void DieuKhienMenu::ChayChuongTrinh() {
	this->OnScreen();
	int check;
	while (true)
	{
		system("cls");
		check = -1;
		FrameIntro(20); // 20 ms
		TextIntro(30); // 30 ms
		this->menu[0]->Chay(check);

		// Chạy Sort
		if (check == 0) {
			check = -1;
			clrscr();
			FrameIntro(20);
			this->menu[1]->Chay(check);

			// kiểm tra lựa chọn sort
			if (check == 0) {
				this->sort = new InterchangeSort;
			}
			else if (check == 1) {
				this->sort = new BubbleSort;
			}
			else if (check == 2) {
				this->sort = new ShakerSort;
			}
			else if (check == 3) {
				this->sort = new SelectionSort;
			}
			else if (check == 4) {
				this->sort = new InsertionSort;
			}
			else if (check == 5) {
				this->sort = new BinaryInsertionSort;
			}

			//else if (check == 6) {
			//	// Shell Sort
			//}
			//else if (check == 7) {
			//	// Counting Sort
			//}
			//else if (check == 8) {
			//	// Radix Sort
			//}
			//else if (check == 9) {
			//	// Heap Sort
			//}
			//else if (check == 10) {
			//	// Quick Sort
			//}
			//else if (check == 10) {
			//	// Merge Sort
			//}

			// 12: back
			if (check != 6) {
				// chạy menu lựa chọn input
				clrscr();
				FrameIntro(20);
				check = -1;
				this->menu[2]->Chay(check);

				// check lựa chọn input
				if (check != 3) {
					clrscr();
					FrameIntro(20);
					if (check == 0) {
						this->sort->NhapTuBanPhim();
					}
					else if (check == 1) {
						this->sort->SinhNgauNhien();
					}
					else if (check == 2) {
						// nhap tu file
					}

					clrscr();
					FrameIntro(20);
					check = -1;
					// chạy menu lựa chọn increase/decrease
					this->menu[3]->Chay(check);

					this->sort->NhapTangDanHoacGiamDan(check == 0 ? true : false);

					// Sort
					if (check != 2) {
						clrscr();
						FrameIntro(20);
						this->sort->Sorting();
						_getch();
					}
				}
			}
		}

		// Chạy Search
		else if (check == 1) {
			check = -1;
			clrscr();
			FrameIntro(20);
			this->menu[4]->Chay(check);

			// kiểm tra lựa chọn search
			if (check == 0) {
				// LinearSearch
				this->search = new LinearSearch;
			}
			else if (check == 1) {
				// mảng đã sắp xếp
				this->search = new BinarySearch;
			}
			else if (check == 2) {
				// mảng đã sắp xếp
				this->search = new JumpSearch;
			}

			bool sorted = (check == 1 || check == 2) ? true : false;

			// Kiểm tra trở lại
			if (check != 3) {
				// chạy menu lựa chọn input
				clrscr();
				FrameIntro(20);
				check = -1;
				this->menu[2]->Chay(check);

				// check lựa chọn input
				if (check != 3) {
					clrscr();
					FrameIntro(20);
					if (check == 0) {
						do {
							this->search->NhapTuBanPhim();
						} while (sorted);
					}
					else if (check == 1) {
						do {
							this->search->SinhNgauNhien();
						} while (sorted);
					}
					else if (check == 2) {
						// nhap tu file
					}

					// Search
					clrscr();
					FrameIntro(20);
					this->search->Searching();
					_getch();
				}
			}
		}

		// About me
		else if (check == 2) {
			clrscr();
			FrameIntro(20);
			AboutMe(30);
		}
		// Exit
		else if (check == 3) {
			clrscr();
			cout << "END ! ";
			break;
		}
	}
}