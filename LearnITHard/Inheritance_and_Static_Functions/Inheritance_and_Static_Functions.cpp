// Inheritance_and_Static_Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class B {
public:
	B() {

	}
	  int fun(int x) {
		std::cout << "Fun ->int" << std::endl;
		return x;
	}
	 int fun2(int x) {
		 std::cout << "Fun2 ->int" << std::endl;
		 return x;
	 }
};

class D :public B {
public:
	 int fun(double y) {
		std::cout << "Fun1 ->double" << std::endl;
		return 0;
	}
	 int fun2(double x) {
		 std::cout << "Fun2 ->double" << std::endl;
		 return x;
	 }
};

int main()
{
    std::cout << "Hello World!\n"; 
	D obj;
	
	obj.fun(10);
	obj.fun(2.0);
	obj.fun2(2);
	obj.B::fun(10);
	return 0;
}
