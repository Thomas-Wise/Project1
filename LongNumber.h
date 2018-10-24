// LongNumber.h
// Thomas Wise
// COSC 2030
// Project01
// 24 Oct 2018

#ifndef LONG_NUMBER_H
#define LONG_NUMBER_H

#include <string>

using std::string;
using std::to_string;

class longNumber
{
public:
	longNumber(void);
	longNumber(int x);
	longNumber(string x);
	longNumber(const longNumber& x);
	string getNum(void) const;
	longNumber operator+(const longNumber& right);
	longNumber operator=(const longNumber& right);
private:
	string num;
};

#endif