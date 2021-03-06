// VirtualDestructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

class Base
{
public:
	Base() { cout << "Base constructer " << endl; }
	void foo() { cout << "Base foo " << endl; }
	virtual ~Base() { cout << "Base distructer " << endl; }
};

class Derived :public Base
{
public:
	Derived() { cout << "Derived constructer " << endl; }
	void foo() { cout << "Base Derived" << endl; }
	~Derived() { cout << " Derived destructor " << endl; }
};

int main()
{
////$$$$$$$$$$$$$$$ Understanding of constructer and destructor $$$$$$$$$$$$
	////test 1  //without virtual 
	//////check for how constructer and destructor called for Base called
	//Base A;

////$$$$$$$$$$$$$$$ Understanding of inheritance constructer and destructor $$$$$$$$$$$$
	////test 2 //without virtual 
	//////check for how constructer and destructor called for Derived called
	// Derived B;

////$$$$$$$$$$$$$$$ Understanding of problem without virtul destructor $$$$$$$$$$$$
	////without virtual  
	//test 3
	// create base type object for base class 
	//and check for constructer and call destructor
	//Base *obj1 = new Base();
	//delete obj1;

	//everything is normal till here

	//test 4 ////without virtual  
	// create base type object for Derived class 
	//and check for constructer and call destructor
	//notice what happing ?
	//Base *obj2 = new Derived();
	//delete obj2;

////$$$$$$$$$$$$$$$ Understanding of VirtualDestructor  $$$$$$$$$$$$
	//its calling base destructor only it supposed to call destructor of Derived class 
	//So ad virtual for destructor of base and the check it out  
	//test 5 with virtual  
	Base *obj2 = new Derived();
	delete obj2;

	return 0;

}

