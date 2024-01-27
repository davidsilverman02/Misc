#include <iostream>
#include <Windows.h>
using namespace std;

extern "C" void printPData(int data1, int data2)
{
	cout << "Player 1: " << data1 << endl << "Player 2: " << data2 << endl;
}

extern "C" int checkKeysP1(int maxi, int min, int now)
{
	if (now > min && (GetKeyState('W') & 0x8000))
		return now - 1;

	if (now < maxi && (GetKeyState('S') & 0x8000))
		return now + 1;

	return now;
}

extern "C" int checkKeysP2(int maxi, int min, int now)
{
	if (now > min && (GetKeyState('W') & 0x8000))
		return now - 1;

	if (now < maxi && (GetKeyState('S') & 0x8000))
		return now + 1;

	return now;
}

extern "C" void cleanScreen()
{
	system("cls");
}

//extern "C" void _main();