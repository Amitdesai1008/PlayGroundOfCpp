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


//
//
//
//
//// test.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <algorithm> // for std::swap, use <utility> instead if C++11
//#include <iostream>
//
//// Note our user-defined comparison is the third parameter
//void selectionSort(int *array, int size, bool(*comparisonFcn)(int, int))
//{
//	// Step through each element of the array
//	for (int startIndex = 0; startIndex < size; ++startIndex)
//	{
//		// bestIndex is the index of the smallest/largest element we've encountered so far.
//		int bestIndex = startIndex;
//
//		// Look for smallest/largest element remaining in the array (starting at startIndex+1)
//		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
//		{
//			// If the current element is smaller/larger than our previously found smallest
//			if (comparisonFcn(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
//																	  // This is the new smallest/largest number for this iteration
//				bestIndex = currentIndex;
//		}
//
//		// Swap our start element with our smallest/largest element
//		std::swap(array[startIndex], array[bestIndex]);
//	}
//}
//
//// Here is a comparison function that sorts in ascending order
//// (Note: it's exactly the same as the previous ascending() function)
//bool ascending(int x, int y)
//{
//	return x > y; // swap if the first element is greater than the second
//}
//
//// Here is a comparison function that sorts in descending order
//bool descending(int x, int y)
//{
//	return x < y; // swap if the second element is greater than the first
//}
//
//bool evenFirst(int x, int y) {
//
//	// if x is even and y is odd, x goes first (no swap needed)
//	if ((x % 2 == 0) && !(y % 2 == 0))
//		return false;
//
//	// if x is odd and y is even, y goes first (swap needed)
//	if (!(x % 2 == 0) && (y % 2 == 0))
//		return true;
//
//	// otherwise sort in ascending order
//	return ascending(x, y);
//}
//
//// This function prints out the values in the array
//void printArray(int *array, int size)
//{
//	for (int index = 0; index < size; ++index)
//		std::cout << array[index] << " ";
//	std::cout << '\n';
//}
//
//
//int main()
//{
//	int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
//
//	//// Sort the array in descending order using the descending() function
//	//selectionSort(array, 9, descending);
//	//printArray(array, 9);
//
//	//// Sort the array in ascending order using the ascending() function
//	//selectionSort(array, 9, ascending);
//	//printArray(array, 9);
//
//	selectionSort(array, 9, evenFirst);
//	printArray(array, 9);
//
//	return 0;
//}
