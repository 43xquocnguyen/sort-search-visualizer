#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//---Thư viện có sẵn---//
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <ctime>
//---Định nghĩa màu sắc---//
#define Color_Black			0
#define Color_Blue			1
#define Color_Green			2
#define Color_Aqua			3
#define Color_Red			4
#define Color_Purple		5
#define Color_Yellow		6
#define Color_White			7
#define Color_Grey			8
#define Color_LightBlue		9
#define Color_LightGreen	10
#define Color_LightAqua		11
#define Color_LightRed		12
#define Color_LightPurple	13
#define Color_LightYellow	14
#define Color_BrightWhite	15

//---Chiều dài và chiều rộng console (tính theo ô)---//
#define WidthConsole 1100
#define HeightConsole 750

//---Hàm Console---//
void clrscr(); 
void GotoXY(int, int); 
void ClearLine(int, int); 
// Tọa độ
int WhereX(); 
int WhereY(); 
// Màu sắc
void TextColor(WORD); 
void BackgroundColor(WORD);
// Chỉnh chiều cao, chiều rộng, xóa scroolbar,...
void ResizeConsole(int, int);
void FullScreen(); 
void RemoveScrollBar(); 
// Disable
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);
void DisableSelection();
// true: hiện | false: ẩn
void ShowCur(bool);

