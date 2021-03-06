// RecursiveFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//factorial function
//fatorial of 5 
//is 5*4*3*2*1 =  
//factorial(n-1)*n

int factorialFunc(int n) {

	if (n == 0)
		return 1;
	return factorialFunc(n - 1) * n ;

}

//Add Digits 
// return the sum of all the integers between 1 (inclusive) and sumto (inclusive)
// returns 0 for negative numbers
//547 = 5+4+7=16
int AddDigit(int n) {
	
	if (n < 10)
		return n;
	else
		return AddDigit(n / 10) + n % 10;

}


int main()
{
	int inVal;
	std::cout << "Enter the \"n\" :" ;
	std::cin >> inVal;
	//std::cout << "factorial of" << inVal << " : " << factorialFunc(inVal)<<std::endl;
	std::cout << "AddDigit of" << inVal << " : " << AddDigit(inVal)<<std::endl;
    return 0;
}

