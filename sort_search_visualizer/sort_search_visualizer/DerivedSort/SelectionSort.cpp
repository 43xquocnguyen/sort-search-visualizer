#include "SelectionSort.h"

SelectionSort::SelectionSort() : Sort() {

}
SelectionSort::~SelectionSort() {

}

//------Output------//
// true: Tang Dan | false: Giam Dan
void SelectionSort::Sorting() {
    ShowCur(false); // ẩn trỏ chuột
    int size = this->size, i, j, min_idx; //
    string nghichThe;

    // In ra toàn dãy số
    for (i = 0; i < size; i++)
    {
        this->A[i].VeBox(Color_Black);
        this->A[i].InChuoi(0, Color_Black);
    }

    Text_Prepering("Selection Sort");
    Sleep(this->tocDo);

    for (int i = 0; i < size - 1; i++)
    {
        min_idx = i;

        // GREEN thằng MIN
        this->A[min_idx].VeBox(Color_Green);
        this->A[min_idx].InChuoi(0, Color_Green);
        Text_Mess_Center(24, Color_White, "MIN: A[" + to_string(min_idx) + "]");

        Sleep(this->tocDo);

        for (int j = i + 1; j < size; j++) {
            Sleep(this->tocDo);

            // so sánh
            if (this->A[min_idx].GetValue() > this->A[j].GetValue()) {
                nghichThe = ">";
            }
            else if (this->A[min_idx].GetValue() < this->A[j].GetValue()) {
                nghichThe = "<";
            }
            else nghichThe = "=";

            // RED thằng đang so sánh
            this->A[j].VeBox(Color_Red);
            this->A[j].InChuoi(0, Color_Red);

            // Mess select
            Text_Mess_Center(25, Color_White, "SELECT: A[" + to_string(j) + "]");
           
            Sleep(this->tocDo);
            
            // Mess compare
            Text_Mess_Center(26, Color_White, "COMPARE: A[" + to_string(min_idx) + "] " + nghichThe + " A[" + to_string(j) + "]");

            Sleep(this->tocDo);

            if (SoSanh2SoTheoDieuKien(this->A[min_idx].GetValue(), this->A[j].GetValue(), this->isIncrease))
            {
                // Mess đảo chỗ
                Text_Mess_Center(27, Color_Green, "NEW MIN: A[" + to_string(j) + "]");
            
                this->A[min_idx].VeBox(Color_Black);
                this->A[min_idx].InChuoi(0, Color_Black);
                min_idx = j;
                this->A[min_idx].VeBox(Color_Green);
                this->A[min_idx].InChuoi(0, Color_Green);

                // Xóa đi min cũ
                Sleep(this->tocDo);
                Text_Mess_Center(24, Color_White, "                                       ");
                Text_Mess_Center(25, Color_White, "                                       ");
                Text_Mess_Center(26, Color_White, "                                       ");
                Text_Mess_Center(27, Color_White, "                                       ");
                Sleep(this->tocDo);
                Text_Mess_Center(24, Color_White, "MIN: A[" + to_string(min_idx) + "]");
            }
            else {
                // Mess khoong đảo chỗ
                Text_Mess_Center(27, Color_White, "NO SWAP");

                this->A[j].VeBox(Color_Black);
                this->A[j].InChuoi(0, Color_Black);

                // Xóa đi select cũ
                Sleep(this->tocDo);
                Text_Mess_Center(25, Color_White, "                                       ");
                Text_Mess_Center(26, Color_White, "                                       ");
                Text_Mess_Center(27, Color_White, "                                       ");
            }
        }
        // Xóa min
        Text_Mess_Center(24, Color_White, "                                       ");
        Sleep(this->tocDo / 2);

        // Mess swap
        Text_Mess_Center(24, Color_Green, "SWAP MIN AND A[" + to_string(i) + "]");
        Sleep(this->tocDo);

        HoanDoi2Box(this->A[min_idx], this->A[i]); 
        this->A[min_idx].VeBox(Color_Black);
        this->A[min_idx].InChuoi(0, Color_Black);
        this->A[i].VeBox(Color_Blue);
        this->A[i].InChuoi(0, Color_Blue);
        Sleep(this->tocDo);
        Text_Mess_Center(24, Color_White, "                                       ");
    }

    // BLUE: thằng cuối
    this->A[size - 1].VeBox(Color_Blue);
    this->A[size - 1].InChuoi(0, Color_Blue);

    // Mess đã sort xong
    Text_Mess_Center(24, Color_Blue, "SELECTION SORT. DONE!");
}