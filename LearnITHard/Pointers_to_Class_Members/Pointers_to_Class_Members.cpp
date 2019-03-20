// Pointers_to_Class_Members.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Sample
{
public:
	int a;
	void display() {
		std::cout << a << std::endl;
	}
	Sample()=default;
	~Sample() = default;

private:

};



int main()
{
	Sample s;
	int Sample::*ptr = &Sample::a;
	s.*ptr = 10;
	void (Sample::*fptr) () = &Sample::display;
	(s.*fptr)();
    std::cout << "Hello World!\n"; 
	return 0;

}
