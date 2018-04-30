// FunctionPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


void forUnderstandingOfVariablePointers();// poiter referce 
void forUnderstandingOfFunctionPointers();
void forUnderstandingOfFPointersAsFunctionArgument();



//<forUnderstandingOfFunctionPointers_start>
int add(int a, int b) {
	return a + b; 
}

int sub(int a, int b) {
	return a - b;
}
//<forUnderstandingOfFunctionPointers_end>


//<forUnderstandingOfFPointersAsFunctionArgument_start>
void printAsItis(int tempVal) {
	cout << tempVal << endl;
}

void printByadding2(int tempVal) {
	cout << (tempVal+2) << endl;
}

void onEach(const vector<int> &values,void (*funPtr)(int)) //pass funtion poiter as argument
{

	for (int val : values) {
		funPtr(val);
	}


}
//<forUnderstandingOfFPointersAsFunctionArgument_end>

int main()
{
	cout << "@@forUnderstandingOfVariablePointers@@" << endl;
	forUnderstandingOfVariablePointers();

	cout << "\n\n@@forUnderstandingOfFunctionPointers@@" << endl;
	forUnderstandingOfFunctionPointers();

	cout << "\n\n@@forUnderstandingOfFPointersAsFunctionArgument@@" << endl;
	forUnderstandingOfFPointersAsFunctionArgument();
	

	getchar();
    return 0;
}

void forUnderstandingOfVariablePointers() {
	//Variable pointers 
	int var = 10;
	int *ptr; //pointer declaration 

			  //address of "var" is assined to "ptr" 
	ptr = &var; //; so now "ptr" can pont to "var" address location 
	std::cout << "address of \"var\" is assined to \"ptr\"" << std::endl;
	std::cout << "&var	" << &var << "\nptr	" << ptr << std::endl;

	//to get the value Dereferenc the pointer by "*" 
	std::cout << "Value of \"var\" is equal to \"*ptr\"" << std::endl;
	std::cout << "var	" << var << "\n*ptr	" << *ptr << std::endl;
	return;
}

void forUnderstandingOfFunctionPointers() {
	//funtion pointer
	int(*funPtr)(int, int); //funtion pointer declaration 
	cout << "By first way"<< endl;
	funPtr = &add;           //address of "add() fuction " is assined to "funPtr" 
	cout << (*funPtr)(2, 3) << endl; 

	cout << "\nBy second  way" << endl;
	funPtr = sub;			 // (with out &)address of "sub() fuction " is reassined to "funPtr" 
	cout << funPtr(2, 3) << endl; //can also use
	return;
}

void forUnderstandingOfFPointersAsFunctionArgument() {
	//Function Pointers As FunctionArgument
	vector<int> v_num = { 1,2,3,5,7,11,13 };
	cout << "By first way" << endl;
	onEach(v_num, printAsItis);
	//or we can also call 
	cout << "\nBy second  way" << endl;
	onEach(v_num, &printByadding2);
}