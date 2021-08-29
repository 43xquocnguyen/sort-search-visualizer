#include "HoTro.h"

bool SoSanh2SoTheoDieuKien(int a, int b, bool checkTang) {
	if (a == b) {
		return false;
	}
	else if (a > b) {
		if (checkTang) {
			return true;
		}
	}
	else if (a < b) {
		if (!checkTang) {
			return true;
		}
	}
	return false;
}
void HoanDoi2Box(Box &A, Box &B) {
	int a = A.GetValue();
	int b = B.GetValue();

	A.SetValue(b);
	B.SetValue(a);
}

//----Frame----//
void FrameIntro(int speed) {
	ShowCur(false);

	for (int i = 0; i < 147; i++)
	{
		GotoXY(i, 0);
		cout << (char)205;
		GotoXY(147 - i, 43);
		cout << (char)205;
		Sleep(speed);

		// nhan phim bat ki cho no' bo qua
		if (_kbhit() && _getch()) speed = 0;
	}

	GotoXY(147, 0);
	cout << (char)187;
	GotoXY(0, 43);
	cout << (char)200;

	for (int i = 1; i < 43; i++)
	{
		GotoXY(147, i);
		cout << (char)186;
		GotoXY(0, 43 - i);
		cout << (char)186;
		Sleep(speed * 3);

		// nhan phim bat ki cho no' bo qua
		if (_kbhit() && _getch()) speed = 0;
	}

	GotoXY(0, 0);
	cout << (char)201;
	GotoXY(147, 43);
	cout << (char)188;
}
void TextIntro(int speed) {
	string design = "DESIGN BY: ";
	int i = 0, length = design.length();
	GotoXY(20, 6);
	for (; i < length; i++)
	{
		cout << design[i];
		Sleep(speed);
		
		// nhan phim bat ki cho no' bo qua
		if (_kbhit() && _getch()) speed = 0;
	}

	ifstream introText("TextFile/intro.txt", ios_base::in);
	string c;
	i = 3;

	if (introText.fail()) {
		TextColor(Color_Red);
		c = "ERROR: CAN'T OPEN FILE \"intro.txt\". PLEASE CHECK YOUR FILE!";
		GotoXY(40, i + 3);
		cout << c;
		TextColor(Color_White);
	}
	else {
		while (!introText.eof())
		{
			getline(introText, c);
			GotoXY(40, i);
			TextColor(i * 2);
			cout << c;
			Sleep(speed * 3);
			i++;

			// nhan phim bat ki cho no' bo qua
			if (_kbhit() && _getch()) speed = 0;
		}
	}

	introText.close();
}
void AboutMe(int speed) {
	ShowCur(false);

	ifstream introText("TextFile/aboutme.txt", ios_base::in);
	string c;
	int x = 148 / 2 - 22;
	int y = 13, length, i;


	if (introText.fail()) {
		TextColor(Color_Red);
		c = "ERROR: CAN'T OPEN FILE \"aboutme.txt\". PLEASE CHECK YOUR FILE!";
		x = 148 / 2 - c.length() / 2;
		GotoXY(x, y);
		cout << c;
		TextColor(Color_White);
	}
	else {
		Box* khung = new Box;
		khung->SetAll(x - 3, y - 1, 0);
		khung->SetWHText(51, 17, "");
		khung->VeBox(Color_Black);

	
		while (!introText.eof())
		{
			getline(introText, c);

			length = c.length();

			GotoXY(x, y);
			for (i = 0; i < length; i++)
			{
				cout << c[i];
				Sleep(speed);

				// nhan phim bat ki cho no' bo qua
				if (_kbhit() && _getch()) speed = 0;
			}
			y++;
		}

		delete khung;
	}

	introText.close();
	
	GotoXY(4, 40);
	string fb = "43xquocnguyen@gmail.com";
	i = 0;
	length = fb.length();

	for (; i < length; i++)
	{
		cout << fb[i];
		Sleep(speed);
	}
	while (true)
	{
		GotoXY(115, 40);
		int x = rand() % 254 + 1;
		TextColor(x);
		cout << "PRESS ANY KEY -> GO TO BACK!";
		// exit
		if (_kbhit() && _getch()) break;
		Sleep(500);
	}
	TextColor(7);
}
void Text_Prepering(string nameAlgu) {
	int x = 148 / 2 - 5;
	int y = 2;
	TextColor(Color_LightBlue);
	for (int i = 0; i < 5; i++)
	{
		GotoXY(x, y);
		cout << "                   ";
		GotoXY(x, y);
		cout << "PREPERING";
		if (_kbhit() && _getch()) break;
		Sleep(500);
		GotoXY(x, y);
		cout << "PREPERING.";
		if (_kbhit() && _getch()) break;
		Sleep(500);
		GotoXY(x, y);
		cout << "PREPERING..";
		if (_kbhit() && _getch()) break;
		Sleep(500);
		GotoXY(x, y);
		cout << "PREPERING...";
		if (_kbhit() && _getch()) break;
		Sleep(1000);
	}
	GotoXY(x, y); 
	cout << "                     ";
	GotoXY(x + 2, y);
	cout << "START";
	Sleep(500);
	GotoXY(x, y);
	cout << "                     ";
	x = 148 / 2 - nameAlgu.length() / 2;
	GotoXY(x, y);
	cout << nameAlgu;
	TextColor(7);
}
void Text_Mess_Center(int y, int color, string mess) {
	int x = 148 / 2 - mess.length() / 2;
	TextColor(color);

	GotoXY(x, y);
	cout << mess;

	TextColor(Color_White);
}
