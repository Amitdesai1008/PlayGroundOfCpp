// Virtual_Keyword_Accessing_Private_Method_of_Derived_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class A
{
public:
	virtual void dp() = 0;
	virtual void show()
	{
		std::cout << "Base class\n";
	}
};

class B : public A
{
private:
	 void show()
	{
		std::cout << "Derived class\n";
	}

   void dp()
	{
		std::cout << "Derived dp\n";
	}
};

int main()
{
	A *a;
	B b;
	a = &b;
	a->show();
	a->dp();
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
