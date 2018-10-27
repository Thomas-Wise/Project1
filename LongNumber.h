// LongNumber.h
// Thomas Wise
// COSC 2030
// Project01
// 26 Oct 2018

#ifndef LONG_NUMBER_H
#define LONG_NUMBER_H

#include <climits>
#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;


// longNumber is a data type that stores three variables: num (basically a whole number), overflow, and fraction.
// When fraction gets above one, num goes up by one and fraction goes down by one so fraction is always < 1.
// When num rolls over, overflow is incremented by one. So it basically acts as one huge number.
class longNumber
{
public:
	longNumber(void);
	longNumber(float x);
	longNumber(unsigned long long int n, unsigned long long int oflow, float fraction);
	longNumber(const longNumber& x);
	unsigned long long int getNum(void) const;
	unsigned long long int getOverflow(void) const;
	float getFraction(void) const;
	void setNum(unsigned long long int x);
	void setOverflow(unsigned long long int x);
	void setFraction(float x);
	bool operator>(const longNumber& right) const;
	longNumber operator+(const longNumber& right) const;
	longNumber operator+(float right);
	longNumber operator-(const longNumber& right) const;
	longNumber operator=(const longNumber& right);
	longNumber operator=(float right);
private:
	unsigned long long int num;
	unsigned long long int overflow;
	float fraction;
};

ostream& operator<<(ostream& out, const longNumber& longNum);
istream& operator>>(istream& in, longNumber& longNum);

#endif