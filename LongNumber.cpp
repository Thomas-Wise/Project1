// LongNumber.cpp
// Thomas Wise
// COSC 2030
// Project01
// 24 Oct 2018

#include "LongNumber.h"

longNumber::longNumber(void)
{
	num = 0;
	overflow = 0;
	fraction = 0;
}

longNumber::longNumber(float x)
{
	*this = x;
}

longNumber::longNumber(unsigned long long int n, unsigned long long int oflow, float frac)
{
	num = n;
	overflow = oflow;
	fraction = frac;
}

longNumber::longNumber(const longNumber& x)
{
	*this = x;
}

unsigned long long int longNumber::getNum(void) const
{
	return num;
}

unsigned long long int longNumber::getOverflow(void) const
{
	return overflow;
}

float longNumber::getFraction(void) const
{
	return fraction;
}

void longNumber::setNum(unsigned long long int x)
{
	num = x;
}

void longNumber::setOverflow(unsigned long long int x)
{
	overflow = x;
}

void longNumber::setFraction(float x)
{
	fraction = x;
}

longNumber longNumber::operator+(const longNumber& right)
{
	unsigned long long int tempOverflow = overflow, tempNum = num;
	float tempFrac = fraction + right.getFraction();
	
	if (tempFrac >= 1)
	{
		tempNum ++;
		tempFrac -= 1;
	}
	tempNum += right.getNum();
	if (tempNum < num || (right.getNum() == ULLONG_MAX && tempNum == num))
	{
		tempOverflow++;
	}
	return longNumber(tempNum, tempOverflow, tempFrac);
}

longNumber longNumber::operator+(float right)
{
	longNumber tempLong = right;
	tempLong = tempLong + *this;
	return tempLong;
}

longNumber longNumber::operator=(const longNumber& right)
{
	num = right.getNum();
	overflow = right.getOverflow();
	fraction = right.getFraction();
	return *this;
}

longNumber longNumber::operator=(float right)
{
	unsigned long long int tempOflow = 0, tempNum = right;
	float tempFrac = right - tempNum;
	return longNumber(tempNum, tempOflow, tempFrac);
}

