// matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>


const int width = 1;
const int flipsPerLine = 5;
const int sleepTime = 1000;

using namespace std;

int main()
{
	int i = 0, x = 0;
	srand(time(NULL));

	bool switches[width] = { 0 };
	const string ch = "1234567890qwertyuiopasdfghjklzxcvbnm,./';{}[]!@#$%^&*()_+";
	const int l = ch.size();
	system("color 0A");
	while (true)
	{
		for ( i = 0; i < width; i+=2)
		{
			if (switches[i])
				cout << ch[rand() % l] << "";
			else
				cout << " ";
		}

		for ( i = 0; i != flipsPerLine; ++i)
		{
			x = rand() % width;
			switches[x] = !switches[x];
		}
		cout << endl;
		this_thread::sleep_for(chrono::microseconds(sleepTime));
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
