// unknownNumberOfArguments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void unknowNuberOgArgType1(initializer_list<string> stringList) {

	cout << "size" << stringList.size() << endl;

	for (auto oneByOne : stringList)
		cout << oneByOne << endl;

}

int main()
{

	unknowNuberOgArgType1({ "amit","desai","rajin","balaji" });

    return 0;
}

