// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#include<sstream>
#include <functional>
#include <memory>
#include <typeinfo>



using namespace std;

class date
{
	int day, month, year;
public:
	date(int d, int m, int y) :day(d), month(m), year(y)
	{

	}
	date() = default;
	//copy con
	date(date& d) {
		day = d.day;
		month = d.month;
		year = d.year;
	}

	date operator = (date& d) {
		day = d.day;
		month = d.month;
		year = d.year;
		return d;
	}

	void display()
	{
		cout << day << "/" << month << "/" << year;
	}

};

int main(void)
{
	date d1(25, 9, 1979);
	date d2 = d1;
	date d3(d2);
	//d3 = d2;
	d3.display();
	return 0;
}