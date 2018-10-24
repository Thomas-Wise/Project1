// LongNumber.cpp
// Thomas Wise
// COSC 2030
// Project01
// 24 Oct 2018

#include "LongNumber.h"

longNumber::longNumber(void)
{
	num = "0";
}

longNumber::longNumber(int x)
{
	num = to_string(x);
}

longNumber::longNumber(string x)
{
	num = x;
}

longNumber::longNumber(const longNumber& x)
{
	*this = x;
}

string longNumber::getNum(void) const
{
	return num;
}

longNumber longNumber::operator+(const longNumber& right)
{
	unsigned long long int Rlen = right.getNum().length();
	unsigned long long int Llen = num.length();
	string tempL = num;
	string tempR = right.getNum();
	string ans;
	bool rightIsLonger;

	if (Rlen > Llen)
	{
		rightIsLonger = true;
	}
	else
	{
		rightIsLonger = false;
	}

	if (rightIsLonger)
	{
		
	}
	
}