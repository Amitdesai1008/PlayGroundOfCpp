// HashInRuby.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <boost/any.hpp>
#include <string>
#include <map>

using namespace std;


char &get_val(string &str, string::size_type ix) {
	return str[ix]; // get_val assumes the given index is valid 
} 
int main() {    
	string s("a value");    
	cout << s << endl;   // prints a value    
	get_val(s, 0) = 'A'; // changes s[0] to A    
	cout << s << endl;   // prints A value    
	return 0; }


//std::map<int, boost::any> HashInRuby{ { 1,4 },{ 2,std::string("amit") },{ 3,'a' } };
//Printer printer{ std::cout };
//f_any(printer, HashInRuby[1]);
//f_any(printer, HashInRuby.at(2));
//f_any(printer, HashInRuby.at(3));
////
//struct Printer
//{
//	std::ostream& os_;
//
//	template <typename T>
//	void operator()(const T& t)
//	{
//		os_ << t;
//	}
//};
//
//template <typename F>
//void f_any(F& f, const boost::any& a)
//{
//	if (auto p = boost::any_cast<std::string>(&a)) f(*p);
//	if (auto p = boost::any_cast<double>(&a))      f(*p);
//	if (auto p = boost::any_cast<int>(&a))         f(*p);
//	if (auto p = boost::any_cast<char>(&a))         f(*p);
//	// whatever handling for unknown types...
//}
//

////boost::any anys[] = { std::string("hi"), 3.14159, 27 };
////Printer printer{ std::cout };
////for (const auto& a : anys)
////{
////	f_any(printer, a);
////	std::cout << '\n';
////}
//
////struct Super_Any : boost::any
////{
////	template <typename T>
////	Super_Any(const T& t)
////		: boost::any(t),
////		printer_([](std::ostream& os, const boost::any& a) { os << boost::any_cast<const T&>(a); })
////	{ }
////
////	std::function<void(std::ostream&, const boost::any&)> printer_;
////};
