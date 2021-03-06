// RemortControl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int channelBegin = 0, channelEnd = 0;
std::vector<int> StartEnd, channelBlock, chennelview;

int digitCount(int tempNum) {
	return std::to_string(tempNum).length();
}

int channelDistence(int firstVal, int secondVal) {

	int tempCount = 0;
	if (firstVal > secondVal) { swap(firstVal, secondVal); }
	for (int i = firstVal; i != secondVal; i++) {
		for (int j = 1; j < channelBlock[0] + 1; j++) {
			if (channelBlock[j] == i) {
				tempCount++;
			}
		}
		if (i == (channelEnd)) {
			i = channelBegin;
		}
	}
	return ((abs(firstVal - secondVal)) - tempCount);
}

int channelDistenceRvc(int firstVal, int secondVal) {

	int tempCount = 0;
	//if (firstVal > secondVal) { swap(firstVal, secondVal); }
	for (int i = firstVal; i != secondVal; i--) {
		for (int j = 1; j < channelBlock[0] + 1; j++) {
			if (channelBlock[j] == i) {
				tempCount++;
			}
		}
		if (i == (channelBegin)) {
			i = channelEnd;
		}

	}
	return ((abs((firstVal + (channelEnd - channelBegin)) - secondVal)) - tempCount);
}


int mincount(int tempchannelCurrent, int tempchannelNext) {

	int pressCount = 0;
	int numCount = digitCount(tempchannelNext);
	int numUpDwon = (abs(channelDistence(tempchannelCurrent, tempchannelNext)));
	int numUpDwonRvc = (abs(channelDistenceRvc(tempchannelCurrent, tempchannelNext)));

	if ((numCount < numUpDwon) && (numCount < numUpDwonRvc)) {

		pressCount = numCount;
	}
	else if (numUpDwon < numUpDwonRvc)
	{
		pressCount = numUpDwon;
	}
	else
	{
		pressCount = numUpDwonRvc;
	}

	return pressCount;
}

string readFile() {
	ifstream f;
	f.open("input.txt", ios::in);
	if (f.is_open()) {
		string data(istreambuf_iterator<char>(f), {});

		return data;
	}
	return "";
}

std::vector<int> parceData(string line, char delima) {
	stringstream  ss;
	ss.str(line);
	string strVal;
	std::vector<int> intVal;
	while (std::getline(ss, strVal, delima))
	{
		intVal.push_back(atoi(strVal.c_str()));
	}

	return intVal;
}

void inputParce(string data, std::vector<int> &StartEnd, std::vector<int> &Block, std::vector<int> &View) {
	stringstream  ss;
	ss.str(data);
	string line;
	std::getline(ss, line);
	StartEnd = parceData(line, ' ');

	std::getline(ss, line);
	Block = parceData(line, ' ');

	std::getline(ss, line);
	View = parceData(line, ' ');
}
	
int main()
{
	inputParce(readFile(), StartEnd, channelBlock, chennelview);

	int pressCount = 0;

	int channelCurrent = NULL, channelNext = NULL, chennelOld = NULL;

	//find first value near to what?

	channelBegin = StartEnd[0];
	channelEnd = StartEnd[1];

	int dissBeginAndZero = abs(channelDistence(channelBegin, chennelview[1]));
	int dissEndAndZero = abs(channelDistence(channelEnd, chennelview[1]));

	//if (dissBeginAndZero < dissEndAndZero) {
	if ((abs(channelDistence(channelBegin, chennelview[1]))) < \
		(abs(channelDistence(channelEnd, chennelview[1]))))
	{
		//set current val
		channelCurrent = channelBegin;
	}
	else {
		channelCurrent = channelEnd;
	}
	chennelOld = channelCurrent;
	//channelCurrent
	for (int index = 1; index < chennelview[0] + 1; index++)
	{
		channelNext = chennelview[index];
		int withBack = (1 + mincount(chennelOld, channelNext));
		int noBack = mincount(channelCurrent, channelNext);
		cout << withBack << " <=> " << noBack << endl;
		if (withBack < noBack) {
			pressCount += withBack;
		}
		else
		{
			pressCount += noBack;
		}
		chennelOld = channelCurrent;
		channelCurrent = channelNext;

	}
	cout << "Min Dist	: " << pressCount << endl;
	return 0;
}


//const int BLOCKCOUNT = 1, VIEWCOUNT = 20;
// int BLOCKCOUNT = 1, VIEWCOUNT = 5;
//const int BLOCKCOUNT = 4, VIEWCOUNT = 8;
//const int BLOCKCOUNT = 1, VIEWCOUNT = 200;

//int chennelview[VIEWCOUNT]   = { 15,14,17,1,17 };
//	int chennelview[VIEWCOUNT]   = { 105,106,107,103,105 };
//int chennelview[VIEWCOUNT]   = { 10,13,13,100,99,98,77,81 };
//int chennelview[VIEWCOUNT]   = { 1,100,1,101 };
//int channelBegin = 103, channelEnd = 108;
//int channelBegin = 1, channelEnd = 100;


//	int channelBlock[BLOCKCOUNT] = { 18,19 };
//	int channelBlock[BLOCKCOUNT] = { 104};
//	int channelBlock[BLOCKCOUNT] = { 78,79,80,3};
//	int channelBlock[BLOCKCOUNT] = {0};

//34 65
//15 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
//4 62 34 50 65
