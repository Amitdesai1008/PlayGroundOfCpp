// CastsInCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>


class Base 
{
public:
	
	void hello() const {
		std::cout << "Hello world, this is Base!\n";
	}
	
};

class Derived :public Base
{
public:

	void hello() const {
		std::cout << "Hello world, this is Derived!\n";
	}
	void hi() const {
		std::cout << "hi world, this is Base!\n";
	}
};


struct B {
	int m = 0;
	void hello() const {
		std::cout << "Hello world, this is B!\n";
	}
};
struct D : B {
	void hello() const {
		std::cout << "Hello world, this is D!\n";
	}
};

int main()
{
	/*
	Syntax:- static_cast < new_type > ( expression ) 		
	1) If there is an implicit conversion sequence from expression to new_type,
		or if overload resolution for a direct initialization of an object 
		or reference of type new_type from expression would find at least one viable function, 
		then static_cast<new_type>(expression) returns the imaginary variable Temp initialized 
		as if by new_type Temp(expression); , 
		which may involve implicit conversions, a call to the constructor of new_type 
		or a call to a user - defined conversion operator
	*/
	// 1: initializing conversion
	int n = static_cast<int>(3.14);
	std::cout << "n = " << n << '\n';

	std::vector<int> v = static_cast<std::vector<int>>(10);
	std::cout << "v.size() = " << v.size() << '\n';



	/*If new_type is a pointer or reference to some class D 
	and the type of expression is a pointer or reference to its non-virtual base B,
	static_cast performs a downcast.
	This downcast is ill-formed 
	if B is ambiguous, inaccessible, or virtual base(or a base of a virtual base) of D.
	Such static_cast makes no runtime checks to ensure that the object's runtime type is actually D, 
	and may only be used safely if this precondition is guaranteed by other means, 
	such as when implementing static polymorphism. 
	Safe downcast may be done with dynamic_cast.
	*/
	// 2: static downcast
	D d;
	B& br = d; // upcast via implicit conversion
	br.hello();
	br.hello();
	D& another_d = static_cast<D&>(br); // downcast
	another_d.hello();
	
	Derived *Dptr = new Derived();
	Base *Bptr = Dptr;
	Bptr->hello();
	//Bptr->hi();
	Derived* Dp = static_cast<Derived*>(Bptr);
	Dp->hello();
	Dp->hi();
    return 0;
}




