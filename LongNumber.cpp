// LongNumber.cpp
// Thomas Wise
// COSC 2030
// Project01
// 26 Oct 2018

#include "LongNumber.h"

// Creates a basic long number which equals 0
longNumber::longNumber(void)
{
	num = 0;
	overflow = 0;
	fraction = 0;
}

// Creates a long number from a float
longNumber::longNumber(float x)
{
	*this = x;
}

// Creates a long number with info for each variable in long number
longNumber::longNumber(unsigned long long int n, unsigned long long int oflow, float frac)
{
	num = n;
	overflow = oflow;
	fraction = frac;
}

// Creates a copy of a long number
longNumber::longNumber(const longNumber& x)
{
	num = x.getNum();
	overflow = x.getOverflow();
	fraction = x.getFraction();
}

// Next three functions return variables from the long number
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

// Next three functions change the value of variables in the long number
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

// Compares the value of two long numbers
bool longNumber::operator>(const longNumber& right) const
{
	// Compares most significant value first
	if (overflow > right.getOverflow())
	{
		return true;
	}
	else if (overflow < right.getOverflow())
	{
		return false;
	}
	// Second most significant value
	if (num > right.getNum())
	{
		return true;
	}
	if (num < right.getNum())
	{
		return false;
	}
	// Least significant value
	if (fraction > right.getFraction())
	{
		return true;
	}
	return false;
}

// Adds two long numbers
longNumber longNumber::operator+(const longNumber& right) const
{
	unsigned long long int tempOverflow = overflow, tempNum = num;
	float tempFrac = fraction + right.getFraction();
	if (tempFrac >= 1)
	{
		tempNum++;
		tempFrac = tempFrac - 1;
	}
	tempNum = tempNum + right.getNum();
	if (tempNum < num || (right.getNum() == ULLONG_MAX && tempNum == num))
	{
		tempOverflow++;
		tempNum++;
		// tempNum++ is here because when it rolls over, it goes through zero.
		// So without incrementing the number, one would be lost every time it
		// overflows.
	}
	return longNumber(tempNum, tempOverflow, tempFrac);
}

// Adds a long number and a float
longNumber longNumber::operator+(float right)
{
	longNumber tempLong;
	tempLong = right;
	tempLong = tempLong + *this;
	return tempLong;
}

// Since long numbers can only be positive values,
// returns the absolute value of the difference between
// two long numbers.
longNumber longNumber::operator-(const longNumber& right) const
{
	// Ensures that the larger number is always subtracting the
	// smaller one. We only want the absolute value.
	if (right > *this)
	{
		longNumber temp(right - *this);
		return temp;
	}

	longNumber temp(right.getNum(), right.getOverflow(), right.getFraction());

	// Basically long subtraction logic, if subtracting the least significant
	// value yields a negative result, borrow some from the next significant value.
	//
	// Getting the fraction
	if (temp.getFraction() >= right.getFraction())
	{
		temp.setFraction(temp.getFraction() - right.getFraction());
	}
	else
	{
		temp.setFraction((1 + temp.getFraction()) - right.getFraction());
		if (temp.getNum() == 0)
		{
			temp.setNum(ULLONG_MAX);
			temp.setOverflow(temp.getOverflow() - 1);
		}
		else
		{
			temp.setNum(temp.getNum() - 1);
		}
	}

	// Getting the number
	if (temp.getNum() >= right.getNum())
	{
		temp.setNum(temp.getNum() - right.getNum());
	}
	else
	{
		temp.setNum(ULLONG_MAX - (right.getNum() - temp.getNum()));
		temp.setOverflow(temp.getOverflow() - 1);
	}
	// Getting the overflow
	//
	// This shouldn't be negative since we checked to see that
	// We were subtracting with the larger number in the beginning
	// of the function.
	temp.setOverflow(temp.getOverflow() - right.getOverflow());
}

// Assigns one large number's value to another large number.
longNumber longNumber::operator=(const longNumber& right)
{
	num = right.getNum();
	overflow = right.getOverflow();
	fraction = right.getFraction();
	longNumber temp(num, overflow, fraction);
	return temp;
}

// Assigns a float's value to a large number.
longNumber longNumber::operator=(float right)
{
	unsigned long long int tempOflow = 0, tempNum = right;
	float tempFrac = right - tempNum;
	longNumber temp(tempNum, tempOflow, tempFrac);
	num = temp.getNum();
	overflow = temp.getOverflow();
	fraction = temp.getFraction();
	return temp;
}

// Allows for stream insertion with large numbers
ostream& operator<<(ostream& out, const longNumber& longNum)
{
	if (longNum.getOverflow() > 0)
	{
		out << "(" << longNum.getOverflow() << ")"
			<< "(" << ULLONG_MAX << ")" << "+";
	}
	out << longNum.getNum() << "+" << longNum.getFraction();
	return out;
}

// Allows for stream extraction with large numbers
istream& operator>>(istream& in, longNumber& longNum)
{
	float input;
	in >> input;
	longNum = input;
	return in;
}