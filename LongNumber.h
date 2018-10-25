// LongNumber.h
// Thomas Wise
// COSC 2030
// Project01
// 24 Oct 2018

#ifndef LONG_NUMBER_H
#define LONG_NUMBER_H

#include <string>
#include <climits>

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
	longNumber operator+(const longNumber& right);
	longNumber operator+(float right);
	longNumber operator=(const longNumber& right);
	longNumber operator=(float right);

private:
	unsigned long long int num;
	unsigned long long int overflow;
	float fraction;
};
#endif