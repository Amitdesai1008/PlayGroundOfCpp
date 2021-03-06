// LearnITHard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


//
//enum VehicleType
//{
//	VT_TwoWheeler,VT_ThreeWheeler,VT_FourWheeler
//};
//
//
//// Library classes
//class Vehicle {
//public:
//	virtual void printVehicle() = 0;
//	static Vehicle * Create(VehicleType type);
//
//};
//
//class TwoWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am two wheeler" << endl;
//	}
//};
//
//class ThreeWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am 3 Wheeler" << endl;
//	}
//};
//
//class FourWheeler : public Vehicle {
//public:
//	void printVehicle() {
//		cout << "I am four wheeler" << endl;
//	}
//};
//
//
//Vehicle* Vehicle::Create(VehicleType type) {
//
//	if (type == VT_TwoWheeler) {
//		return new TwoWheeler;
//	}
//	else if (type == VT_ThreeWheeler) {
//		return new ThreeWheeler;
//	}
//	else if (type == VT_FourWheeler) {
//		return new FourWheeler;
//	}
//	else return nullptr;
//
//}
//
//// Client (or user) class
//class Client {
//private:
//	Vehicle * pVehicle;
//
//public:
//	Client() {
//		VehicleType type = VT_ThreeWheeler;
//		pVehicle = Vehicle::Create(type);
//	}
//
//	~Client() {
//		if (pVehicle)
//		{
//			delete[] pVehicle;
//			pVehicle = NULL;
//		}
//	}
//
//	Vehicle* getVehicle() {
//		return pVehicle;
//	}
//
//};
//
//// Driver program
//int main() {
//	std::vector<int> ar{ 1,2,3,4,5 };
//		ar.
//	//int stack[100000000];
//	return 0;
//
//}
//

#include <iostream>

class IntArray
{
private:
	int m_length = 0;
	int *m_array = nullptr;

public:
	IntArray(int length)
		:m_length(length)
	{
		_ASSERT((length > 0) && "length Should be more then Zero");
		m_array = new int[length];
	}

	~IntArray() {
		delete[] m_array;
	}

	//copy constructor 

	IntArray(const IntArray &array)
		:m_length(array.m_length)
	{
		m_array = new int[m_length];

		//copy all value form old to new
		for (int i = 0; i < m_length; i++) {
			m_array[i] = array.m_array[i];
		}
	}
		
	friend ostream& operator<<(ostream &out, IntArray arry) {

		for (int count = 0; count < arry.m_length; count++)
			out << arry.m_array[count] << " ";
		return out;
	}

	int& operator[](int index) {
		_ASSERT(index > 0);
		_ASSERT(index < m_length);
		return m_array[index];
	}
	
	IntArray& operator= (const IntArray &array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;

		m_length = array.m_length;

		// Allocate a new array
		m_array = new int[m_length];

		// Copy elements from original array to new array
		for (int count = 0; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}
};



IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}