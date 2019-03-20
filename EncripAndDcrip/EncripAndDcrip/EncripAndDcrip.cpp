// EncripAndDcrip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <conio.h>
#include "pwdbased.h"
#include "base64.h"
#include "osrng.h"
#include "modes.h"
#include "aes.h"
#include "filters.h"
#include "sha.h"
#include "hex.h"
#include <boost/exception/diagnostic_information.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>
#include <fstream>

using namespace std;
using namespace CryptoPP;
//typedef unsigned char byte;

string DecencrypedData = "";

int fun() {
	try
	{
	string inputdata{ "" };
	ifstream file(".\\input\\MAB_PRIZM_REQ_06-Feb-2019-01.txt", ios::in,ios::binary);
	if (file.is_open())
	{
		string data(istreambuf_iterator<char>(file), {});
		file.close();
		inputdata = data;
	}


	string skey = "92C336F2209922D478F3D46A54E1A2E81068AFCFE13A579711DA8A32474558B7";
	string dskey;
	StringSource ss(skey, true,
		new HexDecoder(
			new StringSink(dskey)
		) // HexDecoder
	); // Stri
	SecByteBlock key(0x00, 32);
	memcpy(key, dskey.c_str(), 32);

	string siv = "1234567891234567";
	SecByteBlock iv(AES::BLOCKSIZE);
	memcpy(iv, siv.c_str(), AES::BLOCKSIZE);

	CBC_Mode<AES>::Decryption aes;
	aes.SetKeyWithIV(key, 32, iv);

	StreamTransformationFilter* aes_dec = new StreamTransformationFilter(aes, new StringSink(DecencrypedData),BlockPaddingSchemeDef::PKCS_PADDING);
	StringSource source(inputdata, true, aes_dec);



}
catch (...)
{
	//std::cout << "catch  :"<<__FUNCSIG__ << "\n";
	string err = __FUNCSIG__;
	err += "  error :";
	err += boost::current_exception_diagnostic_information();
	//Log::WriteTheLog("HipaError_", err, true);
	cout << err;
	return 1;
}
return 0;
}

int main()
{
	fun();
	cout << DecencrypedData << endl;

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
